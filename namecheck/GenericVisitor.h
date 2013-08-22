#ifndef GPP_GENERIC_VISITOR_H
#define GPP_GENERIC_VISITOR_H

#include "GenericTree.h"
#include "PluginAPI.h"
#include <string>

namespace GPPGeneric
{


struct GenericVisitor
{
    virtual void visitStringLiteral(const GenericTree decl, const std::string& name) = 0;
    virtual void visitVariableDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitEnumTypeDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitEnumValueDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitFunctionDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitParameterDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitTypeDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitClassDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitMethodDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitFieldDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitNamespaceDeclaration(const GenericTree decl, const std::string& name) = 0;
};

} // end GPPGeneric

#endif