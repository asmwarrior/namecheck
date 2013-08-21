#include "NamingConventionPlugin.h"
#include <string>

using namespace std;

namespace GPPGeneric
{

void NamingConventionPlugin::visitVariableDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFunctionDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitParameterDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitTypeDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitClassDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitMethodDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFieldDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitNamespaceDeclaration(const GenericTree decl, const string& name)
{
    plugin->warning(decl, name);
}

} // end GPPGeneric