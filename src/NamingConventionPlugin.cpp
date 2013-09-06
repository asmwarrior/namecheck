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
    if (!_regex.correct_enum_type_name(name, _errmsg))
        setPluginWarning(decl, name, "Enum type declaration ");
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_enum_value_name(name, _errmsg))
        setPluginWarning(decl, name, "Enum value declaration ");
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_variable_name(name, _errmsg))
        setPluginWarning(decl, name, "Variable declaration ");
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_global_const_name(name, _errmsg))
        setPluginWarning(decl, name, "Global const declaration ");
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_method_name(name, _errmsg))
        setPluginWarning(decl, name, "Function declaration ");
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correct_variable_name(name, _errmsg))
        setPluginWarning(decl, name, "Parameter declaration ");
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_typedef_name(name, _errmsg))
        setPluginWarning(decl, name, "Type declaration ");
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_class_name(name, _errmsg))
        setPluginWarning(decl, name, "Class declaration ");
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_struct_name(name, _errmsg))
        setPluginWarning(decl, name, "Struct declaration ");
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_union_name(name, _errmsg))
        setPluginWarning(decl, name, "Union declaration ");
}


void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_union_value_name(name, _errmsg))
        setPluginWarning(decl, name, "Union value declaration ");
}


void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correct_method_name(name, _errmsg))
    {
        _errmsg = "Method declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        _plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_attribute_name(name, _errmsg))
    {
        _errmsg = "Attribute declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        _plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_namespace_name(name, _errmsg))
        setPluginWarning(decl, name, "Namespace declaration ");
}

} // end GPPGeneric