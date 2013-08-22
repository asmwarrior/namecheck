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

    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree decl, const string& name)
{
    cerr << "FUNC DECL: ";

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
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree decl, const string& name)
{
    cerr << "METHOD DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFieldDeclaration(const GenericTree decl, const string& name)
{
    cerr << "FIELD DECL: ";
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree decl, const string& name)
{
    cerr << "NAMESPACE DECL: ";

    plugin->warning(decl, name);
}

} // end GPPGeneric