#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include <string>
#include "NamingConventionChecker.h"
#include "BasePlugin.h"
#include "GenericTree.h"

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
private:
    std::string errmsg;
    NamingConventionChecker regex;
    virtual void visitStringLiteral(const GenericTree decl, const std::string& name);
    virtual void visitEnumTypeDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitEnumValueDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitVariableDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitFunctionDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitParameterDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitTypeDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitClassDeclaration(const GenericTree decl, const std::string& name);
    virtual void visitMethodDeclaration(const GenericTree decl, const AccessModifier access, const std::string& name);
    virtual void visitAttributeDeclaration(const GenericTree decl, const AccessModifier access, const std::string& name);
    virtual void visitNamespaceDeclaration(const GenericTree decl, const std::string& name);
};

} // end GPPGeneric

#endif