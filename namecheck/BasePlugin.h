#ifndef GPP_BASE_PLUGIN_H
#define GPP_BASE_PLUGIN_H

#include "GenericVisitor.h"

namespace GPPGeneric
{

class BasePlugin: GenericVisitor
{
    virtual void visitVariableDeclaration(const tree decl, const std::string& name) {}
    virtual void visitFunctionDeclaration(const tree decl, const std::string& name) {}
    virtual void visitParameterDeclaration(const tree decl, const std::string& name) {}
    virtual void visitTypeDeclaration(const tree decl, const std::string& name) {}
    virtual void visitClassDeclaration(const tree decl, const std::string& name) {}
    virtual void visitMethodDeclaration(const tree decl, const std::string& name) {}
    virtual void visitFieldDeclaration(const tree decl, const std::string& name) {}
    virtual void visitNamespaceDeclaration(const tree decl, const std::string& name) {}

protected:
    PluginAPI* plugin;
public:
    void initialize(PluginAPI* plugin);
    GenericVisitor* getVisitor();
};

}

#endif