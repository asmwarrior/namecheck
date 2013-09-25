/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionPlugin.cpp
* @author      Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       This is an implementation of NamingConventionPlugin class
*/

#include <string>
#include <iostream>
#include "namecheck/NamingConventionPlugin.h"

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
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
#else
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
#endif

namespace GPPGeneric
{

NamingConventionPlugin::NamingConventionPlugin(const std::string& pathFile)
{
    _checker.load(pathFile.c_str());
}

inline void NamingConventionPlugin::setPluginWarning(const GenericTree decl, const DeclarationName& message)
{
    _plugin->warning(decl, message);
}

const char* NamingConventionPlugin::_accessLabel[] = {"PUBLIC", "PROTECTED", "PRIVATE"};

void NamingConventionPlugin::visitStringLiteral(const GenericTree decl, const DeclarationName& name)
{
    _plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result enumTypeResult;
    _checker.check(NamingChecker::RulesContainer::EnumTypeDeclaration, name, enumTypeResult);
    if (!enumTypeResult._match)
    {
        const std::string message = std::string("Enum type declaration ") + enumTypeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result enumValueResult;
    _checker.check(NamingChecker::RulesContainer::EnumValueDeclaration, name, enumValueResult);
    if (!enumValueResult._match)
    {
        const std::string message = std::string("Enum value declaration ") + enumValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result variableResult;
    _checker.check(NamingChecker::RulesContainer::VariableDeclaration, name, variableResult);
    if (!variableResult._match)
    {
        const std::string message = std::string("Variable declaration ") + variableResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result globalConstResult;
    _checker.check(NamingChecker::RulesContainer::GlobalConstDeclaration, name, globalConstResult);
    if (!globalConstResult._match)
    {
        const std::string message = std::string("Global const declaration ") + globalConstResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result functionResult;
    _checker.check(NamingChecker::RulesContainer::FunctionDeclaration, name, functionResult);
    if (!functionResult._match)
    {
        const std::string message = std::string("Function declaration ") + functionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/)
{
    Result parameterResult;
    _checker.check(NamingChecker::RulesContainer::ParameterDeclaration , name, parameterResult);
    if (!parameterResult._match)
    {
        const std::string message = std::string("Parameter declaration ") + parameterResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result typeResult;
    _checker.check(NamingChecker::RulesContainer::TypeDeclaration, name, typeResult);
    if (!typeResult._match)
    {
        const std::string message = std::string("Type declaration ") + typeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result classResult;
    _checker.check(NamingChecker::RulesContainer::ClassDeclaration, name, classResult);
    if (!classResult._match)
    {
        const std::string message = std::string("Class declaration ")+ classResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result structResult;
    _checker.check(NamingChecker::RulesContainer::StructDeclaration, name, structResult);
    if (!structResult._match)
    {
        const std::string message = std::string("Struct declaration ") + structResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result unionResult;
    _checker.check(NamingChecker::RulesContainer::UnionDeclaration, name, unionResult);
    if (!unionResult._match)
    {
        const std::string message = std::string("Union declaration ") + unionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result unionValueResult;
    _checker.check(NamingChecker::RulesContainer::UnionValueDeclaration, name, unionValueResult);
    if (!unionValueResult._match)
    {
        const std::string message = std::string("Union value declaration ") + unionValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/)
{
    Result methodResult;
    _checker.check(NamingChecker::RulesContainer::MethodDeclaration, name, methodResult);
    if (!methodResult._match)
    {
        const std::string message = std::string("Method declaration ") + methodResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result attributeResult;
    _checker.check(NamingChecker::RulesContainer::AttributeDeclaration, name, attributeResult);
    if (!attributeResult._match)
    {
        const std::string message = std::string("Attribute declaration ") + attributeResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result namespaceResult;
    _checker.check(NamingChecker::RulesContainer::NamespaceDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = std::string("Namespace declaration ") + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTemplateTypeParameterDeclaration(const GenericTree decl, const DeclarationName& name)
{
    Result namespaceResult;
    _checker.check(NamingChecker::RulesContainer::TemplateTypeParameterDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = std::string("Template's parameters declaration ") + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

} // end GPPGeneric