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

    void initialize(PluginAPI* plugin);
    GenericVisitor* getVisitor();

protected:

    PluginAPI* _plugin;

private:

    virtual void visitStringLiteral(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitVariableDeclaration(const GenericTree& /* decl */, const std::string& /* name */, bool /* is_const */, const std::string& /*type_name*/) {}
    virtual void visitEnumTypeDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitEnumValueDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitFunctionDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitParameterDeclaration(const GenericTree& /* decl */, const std::string& /* name */, bool /* is_const */) {}
    virtual void visitTypeDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitClassDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitStructDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitUnionDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitUnionValueDeclaration(const GenericTree& /* decl */, const std::string& /* name */, bool /* is_const */, const std::string& /*type_name*/) {}
    virtual void visitMethodDeclaration(const GenericTree& /* decl */, const AccessModifier /* access */, const std::string& /* name */, bool /* is_const */) {}
    virtual void visitAttributeDeclaration(const GenericTree& /* decl */, const AccessModifier /* access */, const std::string& /* name */, bool /* is_const */, const std::string& /*type_name*/) {}
    virtual void visitNamespaceDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}
    virtual void visitGlobalConstDeclaration(const GenericTree& /* decl */, const std::string& /* name */) {}

};

}

#endif