#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include "BasePlugin.h"
#include "GenericTree.h"
#include <string>

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
    void visitVariableDeclaration(const GenericTree decl, const std::string& name);
    void visitFunctionDeclaration(const GenericTree decl, const std::string& name);
    void visitParameterDeclaration(const GenericTree decl, const std::string& name);
    void visitTypeDeclaration(const GenericTree decl, const std::string& name);
    void visitClassDeclaration(const GenericTree decl, const std::string& name);
    void visitMethodDeclaration(const GenericTree decl, const std::string& name);
    void visitFieldDeclaration(const GenericTree decl, const std::string& name);
    void visitNamespaceDeclaration(const GenericTree decl, const std::string& name);
};

} // end GPPGeneric

#endif