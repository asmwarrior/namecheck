/*
 * @file     GenericTraverser.cpp
 * @brief    This is the implementation of GenericTraverser interface.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Source file for traverser providing GenericTraverser implementation.
 *
 * System:   traverser
 * Language: C++
 *
 * @date September 06, 2013
 *
 * This file is part of traverser.
 *
 * traverser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * traverser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with traverser. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <cassert>
#include <iostream>
#include "compilerapi/GenericTree.h"
#include "traverser/GenericTraverser.h"
#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
extern "C"
{        
#   include "cp/cp-tree.h"
}
#else
#   include "cp/cp-tree.h"
#endif

namespace NSGppGeneric
{

const std::string GenericTraverser::RESERVED_DECLARATION = "._";

inline void GenericTraverser::getName(const NSCompilerApi::GenericTree decl, std::string& name)
{
    const NSCompilerApi::GenericTree id(DECL_NAME(decl));
    name = id ? IDENTIFIER_POINTER(id) : "<unnamed>";
}

inline bool GenericTraverser::isReservedDeclaration(const NSCompilerApi::GenericTree decl)
{
    std::string name;
    getName(decl, name);
    return (name.substr(0, 2) == RESERVED_DECLARATION);
}

inline IGenericVisitor::AccessModifier GenericTraverser::getAccess(const NSCompilerApi::GenericTree decl)
{
    IGenericVisitor::AccessModifier ret;
    if (TREE_PRIVATE(decl))
        ret = IGenericVisitor::AccessPrivate;
    else if (TREE_PROTECTED(decl))
        ret = IGenericVisitor::AccessProtected;
    else
        ret = IGenericVisitor::AccessPublic;
    return ret;
}

inline bool GenericTraverser::isConstant(const NSCompilerApi::GenericTree decl)
{
    return CP_TYPE_CONST_P(TREE_TYPE(decl));
}

inline void GenericTraverser::checkArrayTypeName(NSCompilerApi::GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == ARRAY_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_array" + typeName;
    }
}

inline void GenericTraverser::checkReferenceTypeName(NSCompilerApi::GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == REFERENCE_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_ref" + typeName;
    }
}

inline void GenericTraverser::checkPointerTypeName(NSCompilerApi::GenericTree decl, std::string& typeName)
{
    while (TREE_CODE(TREE_TYPE(decl)) == POINTER_TYPE)
    {
        decl = TREE_TYPE(decl);
        typeName = "_ptr" + typeName;
    }
}

inline void GenericTraverser::getTypeName(const NSCompilerApi::GenericTree decl, std::string& returnName)
{
    std::string typeName;
    NSCompilerApi::GenericTree aux(decl);

    checkArrayTypeName(aux, typeName);
    checkReferenceTypeName(aux, typeName);
    checkPointerTypeName(aux, typeName);

    if (TREE_CODE(TREE_TYPE(aux)) == FUNCTION_TYPE)
    {
        typeName = "func" + typeName;
    }
    else if (TYPE_NAME(TREE_TYPE(aux)) == 0)
    {
        typeName = "internal" + typeName;
    }
    else
    {
        getName(TYPE_NAME(TREE_TYPE(aux)), returnName);
    }
    returnName += typeName;
}

inline void GenericTraverser::processVariableDeclaration(const NSCompilerApi::GenericTree decl) const
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

inline void GenericTraverser::processTemplateDeclaration(const NSCompilerApi::GenericTree decl) const
{
    processDeclaration(DECL_TEMPLATE_RESULT(decl));

    NSCompilerApi::GenericTree templateparms(TREE_VALUE(DECL_TEMPLATE_PARMS(decl)));
    for (size_t i(0); i < size_t(TREE_VEC_LENGTH(templateparms)); ++i)
    {
        processDeclaration(TREE_VALUE(TREE_VEC_ELT(templateparms, i)));
    }

}

inline void GenericTraverser::processMethods(const NSCompilerApi::GenericTree type) const
{
    for (NSCompilerApi::GenericTree d(TYPE_METHODS(type)); d != 0; d = TREE_CHAIN(d))
    {
        if (!DECL_ARTIFICIAL(d))
        {
            processDeclaration(d);
        }
    }
}

inline void GenericTraverser::processAttributes(const NSCompilerApi::GenericTree type) const
{
    for (NSCompilerApi::GenericTree d(TYPE_FIELDS(type)); d != 0; d = TREE_CHAIN(d))
    {
        /*one of the nodes in TYPE_FIELDS is the self reference*/
        if (!DECL_SELF_REFERENCE_P(d))
            processDeclaration(d);
    }
}

inline void GenericTraverser::processRecordDeclaration(const NSCompilerApi::GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    if (CLASSTYPE_DECLARED_CLASS(TREE_TYPE(decl)))
        _visitor->visitClassDeclaration(decl, name);
    else
        _visitor->visitStructDeclaration(decl, name);
}

inline void GenericTraverser::unionOrRecord(const NSCompilerApi::GenericTree decl, const NSCompilerApi::GenericTree type, std::string& name) const
{
    if (TREE_CODE(type) == RECORD_TYPE)
    {
        processRecordDeclaration(decl);
    }
    else if (TREE_CODE(type) == UNION_TYPE)
    {
        _visitor->visitUnionDeclaration(decl, name);
    }
}

inline void GenericTraverser::processTypeDeclArtificial(const NSCompilerApi::GenericTree decl) const
{
    assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));

    NSCompilerApi::GenericTree type(TREE_TYPE(decl));
    std::string name;
    getName(decl, name);

    unionOrRecord(decl, type, name);

    if (TREE_CODE(type) == TEMPLATE_TYPE_PARM || TREE_CODE(type) == TEMPLATE_TEMPLATE_PARM)
    {
        if (name != "<unnamed>")
        {
            _visitor->visitTemplateTypeParameterDeclaration(decl, name);
        }
    }
    else
    {
        processAttributes(type);

        processMethods(type);
    }
}

inline void GenericTraverser::processEnumValues(const NSCompilerApi::GenericTree decl) const
{
    std::string name;
    for (NSCompilerApi::GenericTree d(TYPE_VALUES(TREE_TYPE(decl))); d != 0; d = TREE_CHAIN(d))
    {
        getName(TREE_VALUE(d), name);
        _visitor->visitEnumValueDeclaration(TREE_VALUE(d), name);
    }
}

inline void GenericTraverser::processEnumType(const NSCompilerApi::GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    if (DECL_ARTIFICIAL(decl))
        _visitor->visitEnumTypeDeclaration(decl, name);
    else
        _visitor->visitTypeDeclaration(decl, name);
    processEnumValues(decl);
}

inline void GenericTraverser::processType(const NSCompilerApi::GenericTree decl) const
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
        {
            processTypeDeclArtificial(decl);
        }
        else
        {
            _visitor->visitTypeDeclaration(decl, name);
        }
    }
}

inline void GenericTraverser::processSubblocks(const NSCompilerApi::GenericTree block) const
{
    NSCompilerApi::GenericTree subblocks(BLOCK_SUBBLOCKS(block));
    if (subblocks != NULL_TREE)
    {
        processBlock(subblocks);
    }
}

inline void GenericTraverser::processBlockVariables(const NSCompilerApi::GenericTree block) const
{
    for (NSCompilerApi::GenericTree d(BLOCK_VARS(block)); d != 0; d = TREE_CHAIN(d))
    {
        processDeclaration(d);
    }
}

inline void GenericTraverser::processBlock(const NSCompilerApi::GenericTree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);
    for (NSCompilerApi::GenericTree block(decl); block != 0; block = BLOCK_CHAIN(block))
    {
        processBlockVariables(block);

        processSubblocks(block);
    }
}

inline void GenericTraverser::functionOrMethod(const NSCompilerApi::GenericTree decl, std::string& name) const
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

inline void GenericTraverser::processFunctionBody(const NSCompilerApi::GenericTree decl) const
{
    const NSCompilerApi::GenericTree declInitial = DECL_INITIAL(decl);
    if (declInitial != NULL_TREE && TREE_CODE(declInitial) != ERROR_MARK)
        processBlock(declInitial);
}

inline void GenericTraverser::processParameters(const NSCompilerApi::GenericTree decl) const
{
    std::string name;
    getName(decl, name);
    for (NSCompilerApi::GenericTree d(DECL_ARGUMENTS(decl)); d != 0; d = TREE_CHAIN(d))
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

inline void GenericTraverser::processFunction(const NSCompilerApi::GenericTree decl) const
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

inline void GenericTraverser::processDeclaration(const NSCompilerApi::GenericTree decl) const
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

inline void GenericTraverser::traverseDeclarations(const NSCompilerApi::GenericTree ns) const
{
    const cp_binding_level* level(NAMESPACE_LEVEL(ns));
    for (NSCompilerApi::GenericTree decl(level->names); decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }
}

inline void GenericTraverser::traverseNamespaces(const NSCompilerApi::GenericTree ns) const
{
    const cp_binding_level* const level(NAMESPACE_LEVEL(ns));
    for (NSCompilerApi::GenericTree decl = level->namespaces; decl != 0; decl = TREE_CHAIN(decl))
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

void GenericTraverser::traverse(const NSCompilerApi::GenericTree ns) const
{
    // Traverse declarations.
    traverseDeclarations(ns);

    // Traverse namespaces.
    traverseNamespaces(ns);
}

} // end namespace