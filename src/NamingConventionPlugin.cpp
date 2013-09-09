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

namespace GPPGeneric
{

const char* NamingConventionPlugin::_accessLabel[] = {"PUBLIC", "PROTECTED", "PRIVATE"};

void NamingConventionPlugin::visitStringLiteral(const GenericTree& decl, const std::string& name)
{
    _plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctEnumTypeName(name, _errmsg))
        setPluginWarning(decl, name, "Enum type declaration ");
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctEnumValueName(name, _errmsg))
        setPluginWarning(decl, name, "Enum value declaration ");
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correctVariableName(name, _errmsg))
        setPluginWarning(decl, name, "Variable declaration ");
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctGlobalConstName(name, _errmsg))
        setPluginWarning(decl, name, "Global const declaration ");
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctMethodName(name, _errmsg))
        setPluginWarning(decl, name, "Function declaration ");
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correctVariableName(name, _errmsg))
        setPluginWarning(decl, name, "Parameter declaration ");
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctTypedefName(name, _errmsg))
        setPluginWarning(decl, name, "Type declaration ");
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctClassName(name, _errmsg))
        setPluginWarning(decl, name, "Class declaration ");
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctStructName(name, _errmsg))
        setPluginWarning(decl, name, "Struct declaration ");
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctUnionName(name, _errmsg))
        setPluginWarning(decl, name, "Union declaration ");
}

void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correctUnionValueName(name, _errmsg))
        setPluginWarning(decl, name, "Union value declaration ");
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correctMethodName(name, _errmsg))
    {
        _errmsg = "Method declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        _plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correctAttributeName(name, _errmsg))
    {
        _errmsg = "Attribute declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        _plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correctNamespaceName(name, _errmsg))
        setPluginWarning(decl, name, "Namespace declaration ");
}

} // end GPPGeneric