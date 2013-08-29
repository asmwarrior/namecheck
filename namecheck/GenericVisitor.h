#ifndef GPP_GENERIC_VISITOR_H
#define GPP_GENERIC_VISITOR_H

#include "GenericTree.h"
#include "PluginAPI.h"
#include <string>

namespace GPPGeneric
{

typedef enum {
    ACCESS_PUBLIC,
    ACCESS_PROTECTED,
    ACCESS_PRIVATE
} AccessModifier;

struct GenericVisitor
{
    virtual void visitStringLiteral(const GenericTree decl, const std::string& name) = 0;
    virtual void visitVariableDeclaration(const GenericTree decl, const std::string& name, bool is_const, const std::string& type_name) = 0;
    virtual void visitEnumTypeDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitEnumValueDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitFunctionDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitParameterDeclaration(const GenericTree decl, const std::string& name, bool is_const) = 0;
    virtual void visitTypeDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitClassDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitStructDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitUnionDeclaration(const GenericTree decl, const std::string& name) = 0;
    virtual void visitMethodDeclaration(const GenericTree decl, const AccessModifier access, const std::string& name, bool is_const) = 0;
    virtual void visitAttributeDeclaration(const GenericTree decl, const AccessModifier access, const std::string& name, bool is_const, const std::string& type_name) = 0;
    virtual void visitNamespaceDeclaration(const GenericTree decl, const std::string& name) = 0;
};

} // end GPPGeneric

#endif