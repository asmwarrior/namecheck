#include "GenericTraverser.h"

#include "tree-iterator.h"

extern "C"
{
#include "cp/cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
}

#include "GenericTree.h"
#include <cassert>
#include <iostream>

namespace GPPGeneric
{

void GenericTraverser::traverse(const GenericTree ns) const
{
    GenericTree decl;
    const cp_binding_level* level(NAMESPACE_LEVEL(ns));

    // Traverse declarations.
    for (decl = level->names; decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }

    // Traverse namespaces.
    for (decl = level->namespaces; decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }
}

void GenericTraverser::traverse(const GenericTree ns, GenericVisitor* visitor)
{
    this->visitor = visitor;
    traverse(ns);
}


void GenericTraverser::processDeclaration(const GenericTree decl) const
{

    if (!DECL_IS_BUILTIN(decl))
    {
        int tree_code = TREE_CODE(decl);

        if (tree_code == FUNCTION_DECL)
        {
            processFunction(decl);
        }
        else if (tree_code == TYPE_DECL)
        {
            processType(decl);
        }
        else
        {
            processVariableDeclaration(decl);
        }

        if (tree_code == NAMESPACE_DECL)
        {
            traverse(decl);
        }
    }
}

const std::string GenericTraverser::getName(const GenericTree decl)
{
    const GenericTree id(DECL_NAME(decl));
    return std::string(id ? IDENTIFIER_POINTER(id) : "<unnamed>");
}


void GenericTraverser::processVariableDeclaration(const GenericTree decl) const
{
    if (TREE_CODE(decl) == CONST_DECL)
    {
        visitor->visitEnumValueDeclaration(decl, getName(decl));
    }
    else
    {
        visitor->visitVariableDeclaration(decl, getName(decl));
        GenericTree stmt = DECL_INITIAL(decl);
        if (stmt != NULL_TREE)
            processStatement(stmt);
    }
}

void GenericTraverser::processType(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == TYPE_DECL);

    if (DECL_ARTIFICIAL(decl))
        processClass(decl);
    else if (TREE_CODE(TREE_TYPE(decl)) == ENUMERAL_TYPE)
        visitor->visitEnumTypeDeclaration(decl, getName(decl));
    else
        visitor->visitTypeDeclaration(decl, getName(decl));
}


void GenericTraverser::processClass(const GenericTree decl) const
{
    assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));

    GenericTree type (TREE_TYPE (decl));

    visitor->visitClassDeclaration(decl, getName(decl));

    for (GenericTree d(TYPE_FIELDS(type)); d != 0; d = TREE_CHAIN(d))
    {
        switch (TREE_CODE (d))
        {
        case TYPE_DECL:
            if(!DECL_SELF_REFERENCE_P(d))
            {
                processType(d);
            }
            break;

        case FIELD_DECL:
            if(!DECL_ARTIFICIAL(d))
                visitor->visitAttributeDeclaration(d, ACCESS_PRIVATE, getName(d));
            break;

        default:
            break;
        }
    }

    for (GenericTree d(TYPE_METHODS(type)); d != 0; d = TREE_CHAIN(d))
    {
        if (!DECL_ARTIFICIAL(d) && TREE_CODE(d) == FUNCTION_DECL)
            processFunction(d);
    }
}


void GenericTraverser::processFunction(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == FUNCTION_DECL);

    if (TREE_CODE(TREE_TYPE(decl)) == METHOD_TYPE)
        visitor->visitMethodDeclaration(decl, ACCESS_PRIVATE, getName(decl));
    else
        visitor->visitFunctionDeclaration(decl, getName(decl));

    for (GenericTree d(DECL_ARGUMENTS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        if(!DECL_SELF_REFERENCE_P(d))
        {
            visitor->visitParameterDeclaration(d, getName(d));
        }
    }

    GenericTree function_decl(DECL_SAVED_TREE(decl));
    if ((function_decl != NULL_TREE))
    {
        // Body of function
        GenericTree stmt_list = TREE_OPERAND(function_decl, 1);
        if (STMT_IS_FULL_EXPR_P(function_decl) && (TREE_CODE(stmt_list) == STATEMENT_LIST))
        {
            /*
            // Maybe this inline iterator could work with some workaround.
            // Based on tree-iterator.h

            for(tree_stmt_iterator it(tsi_start(stmt_list)); tsi_end_p(it); tsi_next(&it))
            {
                std::cerr << getName(tsi_stmt(it));
            }
            */

            for(tree_statement_list_node* it(STATEMENT_LIST_HEAD(stmt_list)); it != NULL; it = it->next)
            {
                processStatement(it->stmt);
            }

        }
    }
    GenericTree decl_initial = DECL_INITIAL(decl);
    if (decl_initial != NULL_TREE)
        processBlock(decl_initial);

}

void GenericTraverser::processStatement(const GenericTree decl) const
{
    //std::cerr << tree_code_name[TREE_CODE(decl)] << std::endl;

    if (TREE_CODE(decl) == STRING_CST)
    {
        visitor->visitStringLiteral(decl, std::string(TREE_STRING_POINTER(decl)));
    }

    for(int i = 0; i < TREE_OPERAND_LENGTH(decl); ++i)
    {
        processStatement(TREE_OPERAND(decl, i));
    }

}


void GenericTraverser::processBlock(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);

    for (GenericTree d(BLOCK_VARS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        processDeclaration(d);
    }

    GenericTree subblocks(BLOCK_SUBBLOCKS(decl));
    if (subblocks != NULL_TREE)
    {
        processBlock(subblocks);
    }
}


} // end GPPGeneric