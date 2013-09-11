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
#include "NamingConventionChecker.h"
#include "BasePlugin.h"
#include "GenericTree.h"

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
private:

    typedef NamingConventionChecker::Result Result;

    virtual void visitStringLiteral(const GenericTree& decl, const std::string& name);
    virtual void visitVariableDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/);
    virtual void visitGlobalConstDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitEnumTypeDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitEnumValueDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitFunctionDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitParameterDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/);
    virtual void visitTypeDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitClassDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitUnionDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitUnionValueDeclaration(const GenericTree& decl, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/);
    virtual void visitStructDeclaration(const GenericTree& decl, const std::string& name);
    virtual void visitMethodDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/);
    virtual void visitAttributeDeclaration(const GenericTree& decl, const AccessModifier access, const std::string& name, bool /*is_const*/, const std::string& /*type_name*/);
    virtual void visitNamespaceDeclaration(const GenericTree& decl, const std::string& name);
    void setPluginWarning(const GenericTree& decl, const std::string& message);

    NamingConventionChecker _regex;    
    static const char* _accessLabel[];
};

} // end GPPGeneric

#endif