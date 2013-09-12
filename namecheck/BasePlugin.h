/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        BasePlugin.h
* @author      Fracisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing BasePlugin class.
*/

#ifndef GPP_BASE_PLUGIN_H
#define GPP_BASE_PLUGIN_H

#include "GenericVisitor.h"
#include "GenericTree.h"

namespace GPPGeneric
{

class BasePlugin: private GenericVisitor
{
public:

    void initialize(PluginApi* plugin);
    GenericVisitor* getVisitor();

protected:

    PluginApi* _plugin;

private:

    virtual void visitStringLiteral(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitVariableDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */, bool /* isConst */, const std::string& /*typeName*/) {}
    virtual void visitEnumTypeDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitEnumValueDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitFunctionDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitParameterDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */, bool /* isConst */) {}
    virtual void visitTypeDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitClassDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitStructDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitUnionDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitUnionValueDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */, bool /* isConst */, const std::string& /*typeName*/) {}
    virtual void visitMethodDeclaration(const GenericTree& /* decl */, const AccessModifier /* access */, const DeclarationName& /* name */, bool /* isConst */) {}
    virtual void visitAttributeDeclaration(const GenericTree& /* decl */, const AccessModifier /* access */, const DeclarationName& /* name */, bool /* isConst */, const std::string& /*typeName*/) {}
    virtual void visitNamespaceDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}
    virtual void visitGlobalConstDeclaration(const GenericTree& /* decl */, const DeclarationName& /* name */) {}

};

}

#endif