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

const char* NamingConventionPlugin::accessLabel[] = {"PUBLIC", "PROTECTED", "PRIVATE"};

void NamingConventionPlugin::visitStringLiteral(const GenericTree& decl, const std::string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_enum_type_name(name, errmsg))
    {
        errmsg = "Enum type declaration " + errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_enum_value_name(name, errmsg))
    {
        errmsg = "Enum value declaration " + errmsg + " in " + name;
        plugin -> warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_variable_name(name, errmsg))
    {
        errmsg = "Variable declaration " + errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_global_const_name(name, errmsg))
    {
        errmsg = "Global const declaration " + errmsg + " in " + name;
        plugin -> warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_method_name(name, errmsg))
    {
        errmsg = "Function declaration " + errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/)
{
    if (!regex.correct_variable_name(name, errmsg))
    {
        errmsg = "Parameter declaration " + errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_typedef_name(name, errmsg))
    {
        errmsg = "Type declaration " + errmsg + " in " + name;
        plugin -> warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_class_name(name, errmsg))
    {
        errmsg = "Class declaration " + errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_struct_name(name, errmsg))
    {
        errmsg = "Struct declaration " + errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_union_name(name, errmsg))
    {
        errmsg = "Union declaration " + errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}


void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_union_value_name(name, errmsg))
    {
        errmsg = "Union value declaration " + errmsg + " in " + name;
        plugin -> warning(decl, errmsg);
    }
}


void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/)
{
    if (!regex.correct_method_name(name, errmsg))
    {
        errmsg = "Method declaration " + errmsg + " in " + name + " (" +  accessLabel[access] + ")";
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_attribute_name(name, errmsg))
    {
        errmsg = "Attribute declaration " + errmsg + " in " + name + " (" +  accessLabel[access] + ")";
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_namespace_name(name, errmsg))
    {
        errmsg = "Namespace declaration " + errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

} // end GPPGeneric