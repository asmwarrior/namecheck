#ifndef GPP_GENERIC_VISITOR_H
#define GPP_GENERIC_VISITOR_H

#include <gmp.h>

extern "C"
{
#include "gcc-plugin.h"
#include "tree.h"
}

#include "PluginAPI.h"

namespace GPPGeneric
{


struct GenericVisitor
{
	virtual void initialize(PluginAPI* plugin) = 0;

    virtual void visitVariableDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitFunctionDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitParameterDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitTypeDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitClassDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitMethodDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitFieldDeclaration(const tree decl, const std::string& name) = 0;
    virtual void visitNamespaceDeclaration(const tree decl, const std::string& name) = 0;
};

} // end GPPGeneric

#endif