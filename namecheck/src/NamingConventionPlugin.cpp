/*
 * @file     NamingConventionPlugin.cpp
 * @brief    This is the implementation of NamingConventionPlugin interface.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing NamingConventionPlugin implementation.
 *
 * System:   namecheck: Naming Convention Checker
 * Language: C++
 *
 * @date September 06, 2013
 *
 * This file is part of namecheck
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck.  If not, see <http://www.gnu.org/licenses/>.
 *
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

namespace NSNamingChecker
{

NamingConventionPlugin::NamingConventionPlugin(const std::string& pathFile)
{
    _checker.load(pathFile.c_str());
}

inline void NamingConventionPlugin::setPluginWarning(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& message)
{
    _api->warning(decl, message);
}

const std::string NamingConventionPlugin::_accessLabel[] = {"Public", "Protected", "Private"};

void NamingConventionPlugin::visitStringLiteral(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    _api->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result enumTypeResult;
    _checker.check(NSNamingChecker::RulesContainer::EnumTypeDeclaration, name, enumTypeResult);
    if (!enumTypeResult._match)
    {
        const std::string message = "Enum type declaration " + enumTypeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result enumValueResult;
    _checker.check(NSNamingChecker::RulesContainer::EnumValueDeclaration, name, enumValueResult);
    if (!enumValueResult._match)
    {
        const std::string message = "Enum value declaration " + enumValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Rule::Result variableResult;
    _checker.check(NSNamingChecker::RulesContainer::VariableDeclaration, name, variableResult);
    if (!variableResult._match)
    {
        const std::string message = "Variable declaration " + variableResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result globalConstResult;
    _checker.check(NSNamingChecker::RulesContainer::GlobalConstDeclaration, name, globalConstResult);
    if (!globalConstResult._match)
    {
        const std::string message = "Global const declaration " + globalConstResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result functionResult;
    _checker.check(NSNamingChecker::RulesContainer::FunctionDeclaration, name, functionResult);
    if (!functionResult._match)
    {
        const std::string message = "Function declaration " + functionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name, bool /*isConst*/)
{
    Rule::Result parameterResult;
    _checker.check(NSNamingChecker::RulesContainer::ParameterDeclaration , name, parameterResult);
    if (!parameterResult._match)
    {
        const std::string message = "Parameter declaration " + parameterResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result typeResult;
    _checker.check(NSNamingChecker::RulesContainer::TypeDeclaration, name, typeResult);
    if (!typeResult._match)
    {
        const std::string message = "Type declaration " + typeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result classResult;
    _checker.check(NSNamingChecker::RulesContainer::ClassDeclaration, name, classResult);
    if (!classResult._match)
    {
        const std::string message = "Class declaration " + classResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result structResult;
    _checker.check(NSNamingChecker::RulesContainer::StructDeclaration, name, structResult);
    if (!structResult._match)
    {
        const std::string message = "Struct declaration " + structResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result unionResult;
    _checker.check(NSNamingChecker::RulesContainer::UnionDeclaration, name, unionResult);
    if (!unionResult._match)
    {
        const std::string message = "Union declaration " + unionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionValueDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Rule::Result unionValueResult;
    _checker.check(NSNamingChecker::RulesContainer::UnionValueDeclaration, name, unionValueResult);
    if (!unionValueResult._match)
    {
        const std::string message = "Union value declaration " + unionValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitMethodDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::AccessModifier access, const NSGppGeneric::DeclarationName& name, bool /*isConst*/)
{
    Rule::Result methodResult;
    switch(access)
    {
        case  NSGppGeneric::AccessPublic:
            _checker.check(NSNamingChecker::RulesContainer::PublicMethodDeclaration, name, methodResult);
            break;
        case  NSGppGeneric::AccessProtected:
            _checker.check(NSNamingChecker::RulesContainer::ProtectedMethodDeclaration, name, methodResult);
            break;
        case  NSGppGeneric::AccessPrivate:
            _checker.check(NSNamingChecker::RulesContainer::PrivateMethodDeclaration, name, methodResult);
            break;
    }
    if (!methodResult._match)
    {
        const std::string message = _accessLabel[access] + " Method declaration " + methodResult._message + " in " + name ;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::AccessModifier access, const NSGppGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Rule::Result attributeResult;
    switch(access)
    {
        case  NSGppGeneric::AccessPublic:
            _checker.check(NSNamingChecker::RulesContainer::PublicAttributeDeclaration, name, attributeResult);
            break;
        case  NSGppGeneric::AccessProtected:
            _checker.check(NSNamingChecker::RulesContainer::ProtectedAttributeDeclaration, name, attributeResult);
            break;
        case  NSGppGeneric::AccessPrivate:
            _checker.check(NSNamingChecker::RulesContainer::PrivateAttributeDeclaration, name, attributeResult);
            break;
    }
    if (!attributeResult._match)
    {
        const std::string message = _accessLabel[access] + " Attribute declaration " + attributeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result namespaceResult;
    _checker.check(NSNamingChecker::RulesContainer::NamespaceDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = "Namespace declaration " + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTemplateTypeParameterDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::DeclarationName& name)
{
    Rule::Result namespaceResult;
    _checker.check(NSNamingChecker::RulesContainer::TemplateTypeParameterDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = "Template's parameters declaration " + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

} // end namespace