/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionPlugin.cpp
* @author      Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       This is an implementation of NamingConventionPlugin class
*/

#include "NamingConventionPlugin.h"
#include <string>
#include <iostream>

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 7)
#include "gcc-plugin.h"
#include "plugin-version.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "intl.h"
#include "tm.h"
#include "cp/cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
#else
extern "C"
{
#include "gcc-plugin.h"
#include "plugin-version.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "intl.h"
#include "tm.h"
#include "cp/cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
}
#endif

namespace GPPGeneric
{

inline void NamingConventionPlugin::setPluginWarning(const GenericTree& decl, const DeclarationName& message)
{
    _plugin->warning(decl, message);
}

const char* NamingConventionPlugin::_accessLabel[] = {"PUBLIC", "PROTECTED", "PRIVATE"};

void NamingConventionPlugin::visitStringLiteral(const GenericTree& decl, const DeclarationName& name)
{
    _plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result enumTypeResult;
    _regex.checkCorrectEnumTypeName(name, enumTypeResult);
    if (!enumTypeResult._match)
    {
        const std::string message = "Enum type declaration " + enumTypeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result enumValueResult;
    _regex.checkCorrectEnumTypeName(name, enumValueResult);
    if (!enumValueResult._match)
    {
        const std::string message = "Enum value declaration " + enumValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result variableResult;
    _regex.checkCorrectVariableName(name, variableResult);
    if (!variableResult._match)
    {
        const std::string message = "Variable declaration " + variableResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result globalConstResult;
    _regex.checkCorrectGlobalConstName(name, globalConstResult);
    if (!globalConstResult._match)
    {
        const std::string message = "Global const declaration " + globalConstResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result functionResult;
    _regex.checkCorrectMethodName(name, functionResult);
    if (!functionResult._match)
    {
        const std::string message = "Function declaration " + functionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/)
{
    Result parameterResult;
    _regex.checkCorrectVariableName(name, parameterResult);
    if (!parameterResult._match)
    {
        const std::string message = "Parameter declaration " + parameterResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result typeResult;
    _regex.checkCorrectTypedefName(name, typeResult);
    if (!typeResult._match)
    {
        const std::string message = "Type declaration " + typeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result classResult;
    _regex.checkCorrectClassName(name, classResult);
    if (!classResult._match)
    {
        const std::string message = "Class declaration " + classResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result structResult;
    _regex.checkCorrectStructName(name, structResult);
    if (!structResult._match)
    {
        const std::string message = "Struct declaration " + structResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result unionResult;
    _regex.checkCorrectUnionName(name, unionResult);
    if (!unionResult._match)
    {
        const std::string message = "Union declaration " + unionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result unionValueResult;
    _regex.checkCorrectUnionValueName(name, unionValueResult);
    if (!unionValueResult._match)
    {
        const std::string message = "Union value declaration " + unionValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/)
{
    Result methodResult;
    _regex.checkCorrectMethodName(name, methodResult);
    if (!methodResult._match)
    {
        const std::string message = "Method declaration " + methodResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result attributeResult;
    _regex.checkCorrectAttributeName(name, attributeResult);
    if (!attributeResult._match)
    {
        const std::string message = "Attribute declaration " + attributeResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const DeclarationName& name)
{
    Result namespaceResult;
    _regex.checkCorrectNamespaceName(name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = "Namespace declaration " + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

} // end GPPGeneric