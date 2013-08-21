#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include "BasePlugin.h"
#include "GenericTree.h"
#include <string>

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
    virtual void visitEnumTypeDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitEnumValueDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitVariableDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitFunctionDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitParameterDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitTypeDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitClassDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitMethodDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitFieldDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitNamespaceDeclaration(const GenericTree decl, const std::string& name);
};

} // end GPPGeneric

#endif