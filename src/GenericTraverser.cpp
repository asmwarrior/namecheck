/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GenericTraverser.cpp
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       This is the implementation of GenericTraverser class
*/

#include "GenericTraverser.h"
extern "C"
{
#include "tree-iterator.h"
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
        std::string namespace_name;
        getName(decl, namespace_name);
        if (!DECL_IS_BUILTIN(decl) && namespace_name != "std")
        {
            _visitor->visitNamespaceDeclaration(decl, namespace_name);
            traverse(decl);
        }
    }
}

void GenericTraverser::traverse(const GenericTree ns, GenericVisitor* visitor)
{
    _visitor = visitor;
    traverse(ns);
}


void GenericTraverser::processDeclaration(const GenericTree decl) const
{
    std::string names_name;
    getName(decl, names_name);
    if (!DECL_IS_BUILTIN(decl) && names_name != "std")
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
        else if (tree_code == TEMPLATE_DECL)
        {
            processTemplateDeclaration(decl);
        }
        else if (tree_code == BLOCK)
        {
            processBlock(decl);
        }
        else if (!DECL_ARTIFICIAL(decl))
        {
            processVariableDeclaration(decl);
        }
    }
}

inline bool GenericTraverser::isConstant(const GenericTree decl)
{
    return CP_TYPE_CONST_P(TREE_TYPE(decl));
}

inline void GenericTraverser::getName(const GenericTree decl, std::string& name)
{
    const GenericTree id(DECL_NAME(decl));
    name = (id ? IDENTIFIER_POINTER(id) : "<unnamed>");
}

void GenericTraverser::getTypeName(const GenericTree decl, std::string& return_name)
{
    std::string type_name;
    GenericTree aux(decl);
    while (TREE_CODE(TREE_TYPE(aux)) == ARRAY_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_array" + type_name;
    }
    while (TREE_CODE(TREE_TYPE(aux)) == REFERENCE_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_ref" + type_name;
    }
    while (TREE_CODE(TREE_TYPE(aux)) == POINTER_TYPE)
    {
        aux = TREE_TYPE(aux);
        type_name = "_ptr" + type_name;
    }
    if (TREE_CODE(TREE_TYPE(aux)) == FUNCTION_TYPE)
        type_name = "func" + type_name;
    else if (TYPE_NAME(TREE_TYPE(aux)) == 0)
        type_name = "internal" + type_name;
    else
    {
        getName(TYPE_NAME(TREE_TYPE(aux)), return_name);
    }
    return_name += type_name;
}

inline bool GenericTraverser::isReservedDeclaration(const GenericTree decl)
{
    std::string name;
    getName(decl, name);
    return (name.substr(0, 2) == "._");
}

AccessModifier GenericTraverser::getAccess(const GenericTree decl)
{
    AccessModifier ret;
    if (TREE_PRIVATE(decl))
        ret = AccessPrivate;
    else if (TREE_PROTECTED(decl))
        ret = AccessProtected;
    else
        ret = AccessPublic;
    return ret;
}

void GenericTraverser::processVariableDeclaration(const GenericTree decl) const
{
    std::string name;
    std::string type_name;
    getName(decl, name);
    // Enum Values are Traversed in ProcessEnumValue
    if (TREE_CODE(decl) != CONST_DECL)
    {
        getTypeName(decl, type_name);
        if (TREE_CODE(CP_DECL_CONTEXT(decl)) == RECORD_TYPE)
        {
            _visitor->visitAttributeDeclaration(decl, getAccess(decl), name, isConstant(decl), type_name);
        }
        else if (TREE_CODE(CP_DECL_CONTEXT(decl)) == UNION_TYPE)
        {
            _visitor->visitUnionValueDeclaration(decl, name, isConstant(decl), type_name);
        }
        else if (CP_DECL_CONTEXT(decl) == global_namespace && isConstant(decl))
        {
            _visitor->visitGlobalConstDeclaration(decl, name);
        }
        else
        {
            _visitor->visitVariableDeclaration(decl, name, isConstant(decl), type_name);
        }
    }
}

void GenericTraverser::processTemplateDeclaration(const GenericTree decl) const
{
    processDeclaration(DECL_TEMPLATE_RESULT(decl));
    GenericTree templateparms(TREE_VALUE(DECL_TEMPLATE_PARMS(decl)));
    for(int i = 0; i < TREE_VEC_LENGTH(templateparms); ++i)
    {
        processDeclaration(TREE_VALUE(TREE_VEC_ELT(templateparms, i)));
    }

}

void GenericTraverser::processType(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == TYPE_DECL);
    std::string name;
    getName(decl, name);
    if (!isReservedDeclaration(decl))
    {
        if (TREE_CODE(TREE_TYPE(decl)) == ENUMERAL_TYPE)
        {
            processEnumType(decl);
        }
        else if (DECL_ARTIFICIAL(decl))
            processClassStructUnion(decl);
        else
            _visitor->visitTypeDeclaration(decl, name);
    }
}

void GenericTraverser::processEnumType(const GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    if (DECL_ARTIFICIAL(decl))
        _visitor->visitEnumTypeDeclaration(decl, name);
    else
        _visitor->visitTypeDeclaration(decl, name);
    processEnumValues(decl);
}

void GenericTraverser::processEnumValues(const GenericTree decl) const
{
    std::string name;
    for (GenericTree d(TYPE_VALUES(TREE_TYPE(decl))); d != 0; d = TREE_CHAIN(d))
    {
        getName(TREE_VALUE(d), name);
        _visitor->visitEnumValueDeclaration(TREE_VALUE(d), name);
    }
}

void GenericTraverser::processClassStructUnion(const GenericTree decl) const
{
    assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));

    GenericTree type(TREE_TYPE(decl));
    std::string name;
    getName(decl, name);

    if (TREE_CODE(type) == RECORD_TYPE)
    {
        processRecordDeclaration(decl);
    }
    else if (TREE_CODE(type) == UNION_TYPE)
        _visitor->visitUnionDeclaration(decl, name);

    if(TREE_CODE(type) == TEMPLATE_TYPE_PARM || TREE_CODE(type) == TEMPLATE_TEMPLATE_PARM)
    {
        if(name != "<unnamed>")
            _visitor->visitTypeDeclaration(decl, name);
    }  
    else
    {
        processAttributes(type);

        processMethods(type);
    }
}

inline void GenericTraverser::processAttributes(const GenericTree type) const
{
    for (GenericTree d(TYPE_FIELDS(type)); d != 0; d = TREE_CHAIN(d))
    {
        /*one of the nodes in TYPE_FIELDS is the self reference*/
        if (!DECL_SELF_REFERENCE_P(d))
            processDeclaration(d);
    }
}

inline void GenericTraverser::processMethods(const GenericTree type) const
{
    for (GenericTree d(TYPE_METHODS(type)); d != 0; d = TREE_CHAIN(d))
    {
        if (!DECL_ARTIFICIAL(d))
        {
            processDeclaration(d);
        }
    }
}

inline void GenericTraverser::processRecordDeclaration(const GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    if (CLASSTYPE_DECLARED_CLASS(TREE_TYPE(decl)))
        _visitor->visitClassDeclaration(decl, name);
    else
        _visitor->visitStructDeclaration(decl, name);
}

void GenericTraverser::processFunction(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == FUNCTION_DECL);
    std::string name;
    getName(decl, name);
    if (TREE_CODE(TREE_TYPE(decl)) == METHOD_TYPE)
    {
        if (!DECL_COPY_CONSTRUCTOR_P(decl)
                && !DECL_CONSTRUCTOR_P(decl)
                && !DECL_DESTRUCTOR_P(decl)
                && !DECL_OVERLOADED_OPERATOR_P(decl)
                && !DECL_CONV_FN_P(decl))
        {
            _visitor->visitMethodDeclaration(decl, getAccess(decl), name, isConstant(decl));
        }
    }
    else
        _visitor->visitFunctionDeclaration(decl, name);
    processParameters(decl);

    GenericTree decl_initial = DECL_INITIAL(decl);
    if (decl_initial != NULL_TREE && TREE_CODE(decl_initial) != ERROR_MARK)
        processBlock(decl_initial);
}

inline void GenericTraverser::processParameters(const GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    for (GenericTree d(DECL_ARGUMENTS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        getName(d, name);
        if (!DECL_SELF_REFERENCE_P(d)
                && (name != "<unnamed>")
                && (name != "this")
                && (name != "__in_chrg"))
        {
            _visitor->visitParameterDeclaration(d, name, isConstant(d));
        }
    }
}

void GenericTraverser::processBlock(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);
    for (GenericTree block(decl); block != 0; block = BLOCK_CHAIN(block))
    {
        processBlockVariables(block);

        GenericTree subblocks(BLOCK_SUBBLOCKS(block));
        if (subblocks != NULL_TREE)
        {
            processBlock(subblocks);
        }
    }
}

inline void GenericTraverser::processBlockVariables(const GenericTree block) const
{
    for (GenericTree d(BLOCK_VARS(block)); d != 0; d = TREE_CHAIN(d))
    {
        processDeclaration(d);
    }
}


} // end GPPGeneric