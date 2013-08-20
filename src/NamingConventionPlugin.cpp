#include "NamingConventionPlugin.h"
#include <string>

using namespace std;

namespace GPPGeneric
{

void NamingConventionPlugin::visitVariableDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFunctionDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitParameterDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitTypeDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitClassDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitMethodDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitFieldDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

void NamingConventionPlugin::visitNamespaceDeclaration(const tree decl, const string& name)
{
    plugin->warning(decl, name);
}

} // end GPPGeneric