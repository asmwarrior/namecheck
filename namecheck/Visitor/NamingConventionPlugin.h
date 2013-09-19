/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionPlugin.h
* @author      Francisco Herrero, Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing NamingConventionPlugin class.
*/

#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include <string>
#include "Visitor/Rule.h"
#include "Visitor/RulesContainer.h"
#include "Visitor/BasePlugin.h"
#include "Traverser/GenericTree.h"

namespace GPPGeneric
{

class NamingConventionPlugin : public BasePlugin
{
public:
    NamingConventionPlugin();

private:

    typedef NamingChecker::Result Result;

    /**
    * @brief check String Literals
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the string literal it is used for the warning message to print the location of the SL
    * @param name the name to check
    */
    virtual void visitStringLiteral(const GenericTree decl, const DeclarationName& name);

    /**
    * @brief checks variable  name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitVariableDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);
    
    /**
    * @brief checks global constant name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitGlobalConstDeclaration(const GenericTree decl, const DeclarationName& name);
    
    /**
    * @brief checks enum name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitEnumTypeDeclaration(const GenericTree decl, const DeclarationName& name);
    
    /**
    * @brief checks enum value name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitEnumValueDeclaration(const GenericTree decl, const DeclarationName& name);
    
    /**
    * @brief checks function name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitFunctionDeclaration(const GenericTree decl, const DeclarationName& name);
    
    /**
    * @brief checks parameter name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitParameterDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/);
    
    /**
    * @brief checks typedef name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitTypeDeclaration(const GenericTree decl, const DeclarationName& name);
    
    /**
    * @brief checks class name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitClassDeclaration(const GenericTree decl, const DeclarationName& name);

    /**
    * @brief checks union name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitUnionDeclaration(const GenericTree decl, const DeclarationName& name);

    /**
    * @brief checks union member name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitUnionValueDeclaration(const GenericTree decl, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
    * @brief checks struct name
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitStructDeclaration(const GenericTree decl, const DeclarationName& name);

    /**
    * @brief checks Variable Declarations
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitMethodDeclaration(const GenericTree decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/);

    /**
    * @brief checks Variable Declarations
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitAttributeDeclaration(const GenericTree decl, const AccessModifier access, const DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
    * @brief checks Variable Declarations
    *
    * check if it is correct according to the checker, if not prints a warning (using the plugin)
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param name the name to check
    */
    virtual void visitNamespaceDeclaration(const GenericTree decl, const DeclarationName& name);

    /**
    * @brief calls the warning message maker of the plugin
    *
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param message the message to print in the warning
    */
    void setPluginWarning(const GenericTree decl, const std::string& message);

    /** 
    * @brief Checker of naming conventions
    * 
    * This is the object that checks the naming conventions
    */
     NamingChecker::RulesContainer _checker;

    /** 
    * @brief Names of access visibility
    * 
    */
    static const char* _accessLabel[];
};

} // end GPPGeneric

#endif