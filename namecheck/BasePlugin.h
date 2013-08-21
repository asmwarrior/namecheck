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
    PluginAPI* plugin;

private:
    virtual void visitVariableDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitFunctionDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitParameterDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitTypeDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitClassDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitMethodDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
    virtual void visitFieldDeclaration(const GenericTree /* decl*/, const std::string& /* name */) {}
    virtual void visitNamespaceDeclaration(const GenericTree /* decl */, const std::string& /* name */) {}
};

}

#endif