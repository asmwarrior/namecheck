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

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
    extern "C"
    {
    #include "tree-iterator.h"
    #include "cp/cp-tree.h"
    #include "c-family/c-common.h"
    #include "c-family/c-pragma.h"
    #include "diagnostic-core.h"
    }
#else
    #include "tree-iterator.h"
    #include "cp/cp-tree.h"
    #include "c-family/c-common.h"
    #include "c-family/c-pragma.h"
    #include "diagnostic-core.h"
#endif
#include "GenericTree.h"
#include <cassert>
#include <iostream>

namespace GPPGeneric
{

inline bool GenericTraverser::isConstant(const GenericTree decl)
{
    return CP_TYPE_CONST_P(TREE_TYPE(decl));
}

inline void GenericTraverser::getName(const GenericTree decl, std::string& name)
{
    const GenericTree id(DECL_NAME(decl));
    name = (id ? IDENTIFIER_POINTER(id) : "<unnamed>");
}

inline void GenericTraverser::traverseDeclarations(const GenericTree ns) const
{
    const cp_binding_level* level(NAMESPACE_LEVEL(ns));
    for (GenericTree decl(level->names); decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }
}

inline void GenericTraverser::traverseNamespaces(const GenericTree ns) const
{
    const cp_binding_level* level(NAMESPACE_LEVEL(ns));
    for (GenericTree decl = level->namespaces; decl != 0; decl = TREE_CHAIN(decl))
    {
        std::string namespaceName;
        getName(decl, namespaceName);
        if (!DECL_IS_BUILTIN(decl) && namespaceName != "std")
        {
            _visitor->visitNamespaceDeclaration(decl, namespaceName);
            traverse(decl);
        }
    }
}

void GenericTraverser::traverse(const GenericTree ns) const
{
    // Traverse declarations.
    traverseDeclarations(ns);

    // Traverse namespaces.
    traverseNamespaces(ns);
}

inline void GenericTraverser::processTemplateDeclaration(const GenericTree decl) const
{
    processDeclaration(DECL_TEMPLATE_RESULT(decl));

    GenericTree templateparms(TREE_VALUE(DECL_TEMPLATE_PARMS(decl)));
    for (int i = 0; i < TREE_VEC_LENGTH(templateparms); ++i)
    {
        processDeclaration(TREE_VALUE(TREE_VEC_ELT(templateparms, i)));
    }

}

inline void GenericTraverser::checkArrayTypeName(GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == ARRAY_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_array" + typeName;
    }
}

inline void GenericTraverser::checkReferenceTypeName(GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == REFERENCE_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_ref" + typeName;
    }
}

inline void GenericTraverser::checkPointerTypeName(GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == POINTER_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_ptr" + typeName;
    }
}

void GenericTraverser::getTypeName(const GenericTree decl, std::string& returnName)
{
    std::string typeName;
    GenericTree aux(decl);

    checkArrayTypeName(aux, typeName);
    checkReferenceTypeName(aux, typeName);
    checkPointerTypeName(aux, typeName);

    if (TREE_CODE(TREE_TYPE(aux)) == FUNCTION_TYPE)
        typeName = "func" + typeName;
    else if (TYPE_NAME(TREE_TYPE(aux)) == 0)
        typeName = "internal" + typeName;
    else
    {
        getName(TYPE_NAME(TREE_TYPE(aux)), returnName);
    }
    returnName += typeName;
}

inline bool GenericTraverser::isReservedDeclaration(const GenericTree decl)
{
    std::string name;
    getName(decl, name);
    return (name.substr(0, 2) == "._");
}

inline AccessModifier GenericTraverser::getAccess(const GenericTree decl)
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

inline void GenericTraverser::processEnumValues(const GenericTree decl) const
{
    std::string name;
    for (GenericTree d(TYPE_VALUES(TREE_TYPE(decl))); d != 0; d = TREE_CHAIN(d))
    {
        getName(TREE_VALUE(d), name);
        _visitor->visitEnumValueDeclaration(TREE_VALUE(d), name);
    }
}

inline void GenericTraverser::processEnumType(const GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    if (DECL_ARTIFICIAL(decl))
        _visitor->visitEnumTypeDeclaration(decl, name);
    else
        _visitor->visitTypeDeclaration(decl, name);
    processEnumValues(decl);
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


inline void GenericTraverser::unionOrRecord(const GenericTree decl, const GenericTree type, std::string& name) const
{
    if (TREE_CODE(type) == RECORD_TYPE)
    {
        processRecordDeclaration(decl);
    }
    else if (TREE_CODE(type) == UNION_TYPE)
        _visitor->visitUnionDeclaration(decl, name);
}

void GenericTraverser::processDeclaration(const GenericTree decl) const
{
    if (!DECL_IS_BUILTIN(decl))
    {
        const int treeCode = TREE_CODE(decl);

        if (treeCode == FUNCTION_DECL)
        {
            processFunction(decl);
        }
        else if (treeCode == TYPE_DECL)
        {
            processType(decl);
        }
        else if (treeCode == TEMPLATE_DECL)
        {
            processTemplateDeclaration(decl);
        }
        else if (treeCode == BLOCK)
        {
            processBlock(decl);
        }
        else if (!DECL_ARTIFICIAL(decl))
        {
            processVariableDeclaration(decl);
        }
    }
}

void GenericTraverser::processVariableDeclaration(const GenericTree decl) const
{
    std::string name;
    std::string typeName;
    getName(decl, name);
    // Enum Values are Traversed in ProcessEnumValue
    if (TREE_CODE(decl) != CONST_DECL)
    {
        getTypeName(decl, typeName);
        if (TREE_CODE(CP_DECL_CONTEXT(decl)) == RECORD_TYPE)
        {
            _visitor->visitAttributeDeclaration(decl, getAccess(decl), name, isConstant(decl), typeName);
        }
        else if (TREE_CODE(CP_DECL_CONTEXT(decl)) == UNION_TYPE)
        {
            _visitor->visitUnionValueDeclaration(decl, name, isConstant(decl), typeName);
        }
        else if ((TREE_CODE(CP_DECL_CONTEXT(decl)) == NAMESPACE_DECL)
                 && isConstant(decl))
        {
            _visitor->visitGlobalConstDeclaration(decl, name);
        }
        else
        {
            _visitor->visitVariableDeclaration(decl, name, isConstant(decl), typeName);
        }
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
            processTypeDeclArtificial(decl);
        else
            _visitor->visitTypeDeclaration(decl, name);
    }
}

void GenericTraverser::processTypeDeclArtificial(const GenericTree decl) const
{
    assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));

    GenericTree type(TREE_TYPE(decl));
    std::string name;
    getName(decl, name);

    unionOrRecord(decl, type, name);

    if (TREE_CODE(type) == TEMPLATE_TYPE_PARM || TREE_CODE(type) == TEMPLATE_TEMPLATE_PARM)
    {
        if (name != "<unnamed>")
            _visitor->visitTypeDeclaration(decl, name);
    }
    else
    {
        processAttributes(type);

        processMethods(type);
    }
}

inline void GenericTraverser::functionOrMethod(const GenericTree decl, std::string& name) const
{
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

}

inline void GenericTraverser::processFunctionBody(const GenericTree decl) const
{
    const GenericTree declInitial = DECL_INITIAL(decl);
    if (declInitial != NULL_TREE && TREE_CODE(declInitial) != ERROR_MARK)
        processBlock(declInitial);
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

void GenericTraverser::processFunction(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == FUNCTION_DECL);
    std::string name;
    getName(decl, name);
    if (name != "__static_initialization_and_destruction_0")
    {
        functionOrMethod(decl, name);
        processParameters(decl);
        processFunctionBody(decl);
    }
}

inline void GenericTraverser::processBlockVariables(const GenericTree block) const
{
    for (GenericTree d(BLOCK_VARS(block)); d != 0; d = TREE_CHAIN(d))
    {
        processDeclaration(d);
    }
}

inline void GenericTraverser::processSubblocks(const GenericTree block) const
{
    GenericTree subblocks(BLOCK_SUBBLOCKS(block));
    if (subblocks != NULL_TREE)
    {
        processBlock(subblocks);
    }
}

void GenericTraverser::processBlock(const GenericTree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);
    for (GenericTree block(decl); block != 0; block = BLOCK_CHAIN(block))
    {
        processBlockVariables(block);

        processSubblocks(block);
    }
}

} // end GPPGeneric