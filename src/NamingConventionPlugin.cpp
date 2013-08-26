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
using namespace std;

namespace GPPGeneric
{

void NamingConventionPlugin::visitStringLiteral(const GenericTree decl, const std::string& name)
{
    cerr << "STRING LITERAL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumTypeDeclaration(const GenericTree decl, const std::string& name)
{
    cerr << "ENUM VALUE DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitEnumValueDeclaration(const GenericTree decl, const std::string& name)
{
    cerr << "ENUM DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree decl, const string& name)
{
    cerr << "VAR DECL: ";
    if (!regex.correct_variable_name(name, errmsg))
        cerr << errmsg << " in ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree decl, const string& name)
{
    cerr << "FUNC DECL: ";
    if (!regex.correct_method_name(name, errmsg))
        cerr << errmsg << " in ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree decl, const string& name)
{
    cerr << "PARM DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree decl, const string& name)
{
    cerr << "TYPE DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree decl, const string& name)
{
    cerr << "CLASS DECL: ";
    if (!regex.correct_class_name(name, errmsg))
        cerr << errmsg << " in ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree decl, const AccessModifier access, const string& name)
{
    cerr << "METHOD DECL: ";
    if (!regex.correct_method_name(name, errmsg))
        cerr << errmsg << " in ";
    static const char* access_label[] = {"PUBLIC", "PROTECTED", "PRIVATE"};
    cerr << access_label[access] << " METHOD DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitAttributeDeclaration(const GenericTree decl, const AccessModifier access, const string& name)
{
    cerr << "FIELD DECL: ";
    if (!regex.correct_variable_name(name, errmsg))
        cerr << errmsg << " in ";
    static const char* access_label[] = {"PUBLIC", "PROTECTED", "PRIVATE"};
    cerr << access_label[access] << " FIELD DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree decl, const string& name)
{
    cerr << "NAMESPACE DECL: ";
    if (!regex.correct_class_name(name, errmsg))
        cerr << errmsg << " in ";
    plugin->warning(decl, name);
}

} // end GPPGeneric