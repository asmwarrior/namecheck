/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionPluginInline.h
* @author      Francisco Herrero, Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing NamingConventionPlugin class.
*/

#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include <string>
#include "Rule.h"
#include "RulesContainer.h"
#include "BasePlugin.h"
#include "GenericTree.h"

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
public:
    NamingConventionPlugin();

private:

    typedef NamingChecker::Result Result;
    virtual void visitStringLiteral(const GenericTree& decl, const DeclarationName& name);
    virtual void visitVariableDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);
    virtual void visitGlobalConstDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitEnumTypeDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitEnumValueDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitFunctionDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitParameterDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/);
    virtual void visitTypeDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitClassDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitUnionDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitUnionValueDeclaration(const GenericTree& decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);
    virtual void visitStructDeclaration(const GenericTree& decl, const DeclarationName& name);
    virtual void visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/);
    virtual void visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);
    virtual void visitNamespaceDeclaration(const GenericTree& decl, const DeclarationName& name);
    void setPluginWarning(const GenericTree& decl, const std::string& message);

    NamingChecker::RulesContainer _checker;
    static const char* _accessLabel[];

};

} // end GPPGeneric

#endif