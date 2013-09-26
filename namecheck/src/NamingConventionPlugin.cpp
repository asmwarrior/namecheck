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

namespace NamingChecker
{

NamingConventionPlugin::NamingConventionPlugin(const std::string& pathFile)
{
    _checker.load(pathFile.c_str());
}

inline void NamingConventionPlugin::setPluginWarning(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& message)
{
    _plugin->warning(decl, message);
}

const char* NamingConventionPlugin::_accessLabel[] = {"PUBLIC", "PROTECTED", "PRIVATE"};

void NamingConventionPlugin::visitStringLiteral(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    _plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result enumTypeResult;
    _checker.check(NamingChecker::RulesContainer::EnumTypeDeclaration, name, enumTypeResult);
    if (!enumTypeResult._match)
    {
        const std::string message = "Enum type declaration " + enumTypeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result enumValueResult;
    _checker.check(NamingChecker::RulesContainer::EnumValueDeclaration, name, enumValueResult);
    if (!enumValueResult._match)
    {
        const std::string message = "Enum value declaration " + enumValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result variableResult;
    _checker.check(NamingChecker::RulesContainer::VariableDeclaration, name, variableResult);
    if (!variableResult._match)
    {
        const std::string message = "Variable declaration " + variableResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result globalConstResult;
    _checker.check(NamingChecker::RulesContainer::GlobalConstDeclaration, name, globalConstResult);
    if (!globalConstResult._match)
    {
        const std::string message = "Global const declaration " + globalConstResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result functionResult;
    _checker.check(NamingChecker::RulesContainer::FunctionDeclaration, name, functionResult);
    if (!functionResult._match)
    {
        const std::string message = "Function declaration " + functionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/)
{
    Result parameterResult;
    _checker.check(NamingChecker::RulesContainer::ParameterDeclaration , name, parameterResult);
    if (!parameterResult._match)
    {
        const std::string message = "Parameter declaration " + parameterResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result typeResult;
    _checker.check(NamingChecker::RulesContainer::TypeDeclaration, name, typeResult);
    if (!typeResult._match)
    {
        const std::string message = "Type declaration " + typeResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result classResult;
    _checker.check(NamingChecker::RulesContainer::ClassDeclaration, name, classResult);
    if (!classResult._match)
    {
        const std::string message = "Class declaration " + classResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result structResult;
    _checker.check(NamingChecker::RulesContainer::StructDeclaration, name, structResult);
    if (!structResult._match)
    {
        const std::string message = "Struct declaration " + structResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result unionResult;
    _checker.check(NamingChecker::RulesContainer::UnionDeclaration, name, unionResult);
    if (!unionResult._match)
    {
        const std::string message = "Union declaration " + unionResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitUnionValueDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result unionValueResult;
    _checker.check(NamingChecker::RulesContainer::UnionValueDeclaration, name, unionValueResult);
    if (!unionValueResult._match)
    {
        const std::string message = "Union value declaration " + unionValueResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitMethodDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::AccessModifier access, const GPPGeneric::DeclarationName& name, bool /*isConst*/)
{
    Result methodResult;
    _checker.check(NamingChecker::RulesContainer::MethodDeclaration, name, methodResult);
    if (!methodResult._match)
    {
        const std::string message = "Method declaration " + methodResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::AccessModifier access, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/)
{
    Result attributeResult;
    _checker.check(NamingChecker::RulesContainer::AttributeDeclaration, name, attributeResult);
    if (!attributeResult._match)
    {
        const std::string message = "Attribute declaration " + attributeResult._message + " in " + name + " (" +  _accessLabel[access] + ")";
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result namespaceResult;
    _checker.check(NamingChecker::RulesContainer::NamespaceDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = "Namespace declaration " + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

void NamingConventionPlugin::visitTemplateTypeParameterDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name)
{
    Result namespaceResult;
    _checker.check(NamingChecker::RulesContainer::TemplateTypeParameterDeclaration, name, namespaceResult);
    if (!namespaceResult._match)
    {
        const std::string message = "Template's parameters declaration " + namespaceResult._message + " in " + name;
        setPluginWarning(decl, message);
    }
}

} // end namespace