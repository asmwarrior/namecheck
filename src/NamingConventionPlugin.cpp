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
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_enum_type_name(name, _errmsg))
    {
        _errmsg = "Enum type declaration " + _errmsg + " in " + name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_enum_value_name(name, _errmsg))
    {
        _errmsg = "Enum value declaration " + _errmsg + " in " + name;
        plugin -> warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_variable_name(name, _errmsg))
    {
        _errmsg = "Variable declaration " + _errmsg + " in " + name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_global_const_name(name, _errmsg))
    {
        _errmsg = "Global const declaration " + _errmsg + " in " + name;
        plugin -> warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_method_name(name, _errmsg))
    {
        _errmsg = "Function declaration " + _errmsg + " in " + name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correct_variable_name(name, _errmsg))
    {
        _errmsg = "Parameter declaration " + _errmsg + " in " + name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_typedef_name(name, _errmsg))
    {
        _errmsg = "Type declaration " + _errmsg + " in " + name;
        plugin -> warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_class_name(name, _errmsg))
    {
        _errmsg = "Class declaration " + _errmsg +" in "+ name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_struct_name(name, _errmsg))
    {
        _errmsg = "Struct declaration " + _errmsg +" in "+ name;
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_union_name(name, _errmsg))
    {
        _errmsg = "Union declaration " + _errmsg +" in "+ name;
        plugin->warning(decl, _errmsg);
    }
}


void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_union_value_name(name, _errmsg))
    {
        _errmsg = "Union value declaration " + _errmsg + " in " + name;
        plugin -> warning(decl, _errmsg);
    }
}


void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/)
{
    if (!_regex.correct_method_name(name, _errmsg))
    {
        _errmsg = "Method declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!_regex.correct_attribute_name(name, _errmsg))
    {
        _errmsg = "Attribute declaration " + _errmsg + " in " + name + " (" +  _accessLabel[access] + ")";
        plugin->warning(decl, _errmsg);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!_regex.correct_namespace_name(name, _errmsg))
    {
        _errmsg = "Namespace declaration " + _errmsg + " in " + name;
        plugin->warning(decl, _errmsg);
    }
}

} // end GPPGeneric