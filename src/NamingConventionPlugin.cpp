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
        errmsg = errmsg + " in " + name;
        plugin->warning(decl, name);
    }
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_enum_value_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin -> warning(decl, name);
    }
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_variable_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin->warning(decl, name);
    }
}

void NamingConventionPlugin::visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_global_const_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin -> warning(decl, name);
    }
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_method_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin->warning(decl, name);
    }
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/)
{
    if (!regex.correct_variable_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_typedef_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin -> warning(decl, name);
    }
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_class_name(name, errmsg))
    {
        errmsg = errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitStructDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_class_name(name, errmsg))
    {
        errmsg = errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitUnionDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_union_name(name, errmsg))
    {
        errmsg = errmsg +" in "+ name;
        plugin->warning(decl, errmsg);
    }
}


void NamingConventionPlugin::visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_union_value_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin -> warning(decl, name);
    }
}


void NamingConventionPlugin::visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/)
{
    if (!regex.correct_method_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name + " (" +  accessLabel[access] + ")";
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/)
{
    if (!regex.correct_attribute_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name + " (" +  accessLabel[access] + ")";
        plugin->warning(decl, errmsg);
    }
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree& decl, const std::string& name)
{
    if (!regex.correct_class_name(name, errmsg))
    {
        errmsg = errmsg + " in " + name;
        plugin->warning(decl, name);
    }
}

} // end GPPGeneric