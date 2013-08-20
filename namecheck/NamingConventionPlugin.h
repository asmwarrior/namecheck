#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include <gmp.h>

extern "C"
{
#include "gcc-plugin.h"
#include "tree.h"
}

#include <string>
#include "BasePlugin.h"


namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
    void visitVariableDeclaration(const tree decl, const std::string& name);
    void visitFunctionDeclaration(const tree decl, const std::string& name);
    void visitParameterDeclaration(const tree decl, const std::string& name);
    void visitTypeDeclaration(const tree decl, const std::string& name);
    void visitClassDeclaration(const tree decl, const std::string& name);
    void visitMethodDeclaration(const tree decl, const std::string& name);
    void visitFieldDeclaration(const tree decl, const std::string& name);
    void visitNamespaceDeclaration(const tree decl, const std::string& name);
};

} // end GPPGeneric

#endif