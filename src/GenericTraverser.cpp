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
        {
            processDeclaration(decl);
        }
    }

    // Traverse namespaces.
    for (decl = level->namespaces; decl != 0; decl = TREE_CHAIN(decl))
    {
        std::string namespace_name = getName(decl);
        if (namespace_name != "std" && namespace_name.substr(0,2) != "__")
        {
            visitor->visitNamespaceDeclaration(decl, namespace_name);
            traverse(decl);
        }
    }
}

void GenericTraverser::traverse(const GenericTree ns, GenericVisitor* visitor)
{
    this->visitor = visitor;
    traverse(ns);
}


void GenericTraverser::processDeclaration(const GenericTree decl) const
{
    std::string names_name = getName(decl);
    if (!DECL_IS_BUILTIN(decl) && names_name != "std" && names_name.substr(0,2) != "__")
    {
        int tree_code = TREE_CODE(decl);

        if (tree_code == FUNCTION_DECL)
        {
            //if(DECL_LOCAL_FUNCTION_P(decl))
            processFunction(decl);
        }
        else if (tree_code == TYPE_DECL)
        {
            processType(decl);
        }
        else if (tree_code == TEMPLATE_DECL)
        {
            //TEMPLATES!
        }
        else //if (tree_code != TREE_LIST)
        {
            if (!DECL_ARTIFICIAL(decl))
            processVariableDeclaration(decl);
        }
        /*
        if (tree_code == NAMESPACE_DECL)
        {
            traverse(decl);
        }*/
    }
}

bool GenericTraverser::isConstant(const GenericTree decl)
{
    return CP_TYPE_CONST_P(TREE_TYPE(decl));
}

const std::string GenericTraverser::getName(const GenericTree decl)
{
   /* GenericTree aux(decl);
    if(TREE_CODE(TREE_TYPE(aux) == )*/
    const GenericTree id(DECL_NAME(decl));
    return std::string(id ? IDENTIFIER_POINTER(id) : "<unnamed>");
}

const std::string GenericTraverser::getTypeName(const GenericTree decl)
{
    std::string type_name("");
    GenericTree aux(decl);
    while(TREE_CODE(TREE_TYPE(aux))==ARRAY_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_array" + type_name;
    }
    while(TREE_CODE(TREE_TYPE(aux))==REFERENCE_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_ref" + type_name;
    }
    while(TREE_CODE(TREE_TYPE(aux))==POINTER_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_ptr" + type_name;
    }
    type_name = getName(TYPE_NAME(TREE_TYPE(aux))) + type_name;
    return type_name;
}

void GenericTraverser::processVariableDeclaration(const GenericTree decl) const
{
    if (TREE_CODE(decl) == CONST_DECL)
    {
        visitor->visitEnumValueDeclaration(decl, getName(decl));
    }
    else
    {
        /*si la variable pertenece a una clase , struct o union (es un atributo)*/
        if (TREE_CODE(CP_DECL_CONTEXT(decl)) == RECORD_TYPE)
        {
            if (TREE_PRIVATE(decl))
            {
                visitor->visitAttributeDeclaration(decl, ACCESS_PRIVATE, getName(decl), isConstant(decl), getTypeName(decl));
            }
            else if(TREE_PROTECTED(decl))
            {
                visitor->visitAttributeDeclaration(decl, ACCESS_PROTECTED, getName(decl), isConstant(decl), getTypeName(decl));
            }
            else
            {
                visitor->visitAttributeDeclaration(decl, ACCESS_PUBLIC, getName(decl), isConstant(decl), getTypeName(decl));
            }
        }
        else if (TREE_CODE(CP_DECL_CONTEXT(decl)) == UNION_TYPE)
        {
            visitor->visitUnionValueDeclaration(decl, getName(decl), isConstant(decl), getTypeName(decl));
        }
        else if (CP_DECL_CONTEXT(decl) == global_namespace && isConstant(decl))
        {
            visitor->visitGlobalConstDeclaration(decl, getName(decl));
        }
        else
        {
            visitor->visitVariableDeclaration(decl, getName(decl), isConstant(decl), getTypeName(decl));
        }
            GenericTree stmt = DECL_INITIAL(decl);
            if (stmt != NULL_TREE)
                processStatement(stmt);
    }
}

void GenericTraverser::processType(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == TYPE_DECL);

    if (TREE_CODE(TREE_TYPE(decl)) == ENUMERAL_TYPE)
    {
        visitor->visitEnumTypeDeclaration(decl, getName(decl));
    }
    else if(DECL_ARTIFICIAL(decl))
        processClass(decl);
    else
        visitor->visitTypeDeclaration(decl, getName(decl));
}

void GenericTraverser::processClass(const GenericTree decl) const
{
   // assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));


    // Ignore internal classes
    if (getName(decl) == "._0" || getName(decl).substr(0,2) == "__")
        return;

    GenericTree type(TREE_TYPE (decl));

    if(TREE_CODE(type) == RECORD_TYPE)
    {
        if(CLASSTYPE_DECLARED_CLASS(type))
            visitor->visitClassDeclaration(decl, getName(decl));
        else
           
            visitor->visitStructDeclaration(decl, getName(decl));
    }
    else if (TREE_CODE(type) == UNION_TYPE)
        visitor->visitUnionDeclaration(decl, getName(decl));
 
    
    for (GenericTree d(TYPE_FIELDS(type)); d != 0; d = TREE_CHAIN(d))
    {
      /*one of the nodes in TYPE_FIELDS is the self reference*/
        if(!DECL_SELF_REFERENCE_P(d))
            processDeclaration(d);
    }

    for (GenericTree d(TYPE_METHODS(type)); d != 0; d = TREE_CHAIN(d))
    {
        if (!DECL_ARTIFICIAL(d) && TREE_CODE(d) == FUNCTION_DECL)
        {
            processFunction(d);
        }
    }
}

void GenericTraverser::processFunction(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == FUNCTION_DECL);

    if (TREE_CODE(TREE_TYPE(decl)) == METHOD_TYPE)
    {
        if (!DECL_COPY_CONSTRUCTOR_P(decl)
            && !DECL_CONSTRUCTOR_P(decl)
            && !DECL_DESTRUCTOR_P(decl)
            && !DECL_OVERLOADED_OPERATOR_P(decl)
            && !DECL_CONV_FN_P(decl))
        {
            if (TREE_PRIVATE(decl))
            {
                 visitor->visitMethodDeclaration(decl, ACCESS_PRIVATE, getName(decl), isConstant(decl));
            }
            else if(TREE_PROTECTED(decl))
            {
                visitor->visitMethodDeclaration(decl, ACCESS_PROTECTED, getName(decl), isConstant(decl));
            }
            else
            {
                visitor->visitMethodDeclaration(decl, ACCESS_PUBLIC, getName(decl), isConstant(decl));
            }
        }
    }
    else
        visitor->visitFunctionDeclaration(decl, getName(decl));

    for (GenericTree d(DECL_ARGUMENTS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        if(!DECL_SELF_REFERENCE_P(d) 
            && (getName(d) != "<unnamed>")    
            && (getName(d) != "this")        
            && (getName(d) != "__in_chrg") )
        {
            visitor->visitParameterDeclaration(d, getName(d), isConstant(d));
        }
    }
    
    /*
    GenericTree function_decl(DECL_SAVED_TREE(decl));
    if (function_decl != NULL_TREE)
    {
        // Body of function
        GenericTree stmt_list = TREE_OPERAND(function_decl, 1);
        if(stmt_list != NULL_TREE)
        {
            if (STMT_IS_FULL_EXPR_P(function_decl) && (TREE_CODE(stmt_list) == STATEMENT_LIST))
            {
     */
                /*
                // Maybe this inline iterator could work with some workaround.
                // Based on tree-iterator.h

                for(tree_stmt_iterator it(tsi_start(stmt_list)); tsi_end_p(it); tsi_next(&it))
                {
                    std::cerr << getName(tsi_stmt(it));
                }
                */
/*
                for(tree_statement_list_node* it(STATEMENT_LIST_HEAD(stmt_list)); it != NULL; it = it->next)
                {
                processStatement(it->stmt);
                }

            }
        }
    }
*/
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
        GenericTree operand(TREE_OPERAND(decl, i));
        if (operand != NULL_TREE)
            processStatement(operand);
    }

}


void GenericTraverser::processBlock(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);
    for(GenericTree block(decl); block != 0; block = BLOCK_CHAIN(block))
    {
        for (GenericTree d(BLOCK_VARS(block)); d != 0; d = TREE_CHAIN(d))
        {   
            processDeclaration(d);
        }

        GenericTree subblocks(BLOCK_SUBBLOCKS(block));
        if (subblocks != NULL_TREE)
        {
            processBlock(subblocks);
        }
    }
}


} // end GPPGeneric