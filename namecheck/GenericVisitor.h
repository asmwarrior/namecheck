/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GenericVisitor.h
* @author      Fracisco Herrero, Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing GenericVisitor struct.
*/

#ifndef GPP_GENERIC_VISITOR_H
#define GPP_GENERIC_VISITOR_H

#include "GenericTree.h"
#include "PluginAPI.h"
#include <string>

namespace GPPGeneric
{

typedef enum
{
    AccessPublic,
    AccessProtected,
    AccessPrivate
} AccessModifier;

typedef std::string DeclarationName; 

struct GenericVisitor
{
    virtual void visitStringLiteral(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitVariableDeclaration(const GenericTree& decl, const DeclarationName& name, bool is_const, const std::string& type_name) = 0;
    virtual void visitEnumTypeDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitEnumValueDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitFunctionDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitParameterDeclaration(const GenericTree& decl, const DeclarationName& name, bool is_const) = 0;
    virtual void visitTypeDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitClassDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitStructDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitUnionDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitUnionValueDeclaration(const GenericTree& decl, const DeclarationName& name, bool is_const, const std::string& type_name) = 0;
    virtual void visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool is_const) = 0;
    virtual void visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool is_const, const std::string& type_name) = 0;
    virtual void visitNamespaceDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
    virtual void visitGlobalConstDeclaration(const GenericTree& decl, const DeclarationName& name) = 0;
};

} // end GPPGeneric

#endif