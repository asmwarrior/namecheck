/**
 * @file     NamingConventionPlugin.h
 * @brief    Provides the interface to NamingConventionPlugin class.
 *           Allow visit and process each statement.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing NamingConventionPlugin class.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 06, 2013
 *
 * This file is part of namecheck.
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GPP_NAMING_CONVENTION_PLUGIN_H
#define GPP_NAMING_CONVENTION_PLUGIN_H

#include <string>
#include <mili/mili.h>
#include "Rule.h"
#include "RulesContainer.h"
#include "traverser/BasePlugin.h"

namespace NSNamingChecker
{

class NamingConventionPlugin : public NSGppGeneric::BasePlugin
{
public:

    /**
     * @brief Constructor of class
     *
     * @param pathFile path configuration file
     */
    NamingConventionPlugin(const std::string& pathFile);

private:

    /**
     * @brief Checks String Literals.
     *
     * Checks the value according to the checker's rules, prints a warning (using the plugin) if it's not.
     *
     * @param decl is the tree of the string literal used for the warning message to print the location of the SL
     * @param name the name to check
     */
    virtual void visitStringLiteral(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief Checks variable name.
     *
     * Checks the name according to the checker's rules, prints a warning (using the plugin) if it's not.
     *
     * @param decl is the tree node of the name used for the warning message; it is passed to print the location of the name
     * @param name the name to check
     */
    virtual void visitVariableDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks global constant name
     *
     * Checks the declaration according to the checker's rules, prints a warning (using the plugin) if it's not.
     *
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitGlobalConstDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks enum name
     *
     * Checks the enum declaration according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitEnumTypeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks enum value name
     *
     * Checks the enum value according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitEnumValueDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks function name
     *
     * Checks the function name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitFunctionDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks parameter name
     *
     * Checks the parameter name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitParameterDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name, bool /*isConst*/);

    /**
     * @brief checks typedef name
     *
     * Checks the typedef name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitTypeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
    * @brief checks class name
     *
     * Checks the class declaration according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitClassDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks union name
     *
     * Checks the union name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitUnionDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks union member name
     *
     * Checks the union member name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitUnionValueDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks struct name
     *
     * Checks the struct member name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitStructDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks a method declaration
     *
     * Checks the method name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitMethodDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::AccessModifier access, const NSGppGeneric::IGenericVisitor::DeclarationName& name, bool /*isConst*/);

    /**
     * @brief checks an attribute declaration
     *
     * Checks the attribute name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitAttributeDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::AccessModifier access, const NSGppGeneric::IGenericVisitor::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks a variable declaration
     *
     * Checks the variable name according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitNamespaceDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief checks a template type parameter declaration
     *
     * Checks the template parameter according to the checker's rules, prints a warning (using the plugin) if it's not.
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitTemplateTypeParameterDeclaration(const NSCompilerApi::GenericTree decl, const NSGppGeneric::IGenericVisitor::DeclarationName& name);

    /**
     * @brief calls the warning message maker of the plugin
     *
     * @param decl is the tree node that contains the name used by the warning message to print the location of the name
     * @param message the message to print in the warning
     */
    void logPluginWarning(const NSCompilerApi::GenericTree decl, const std::string& message) const;

    /**
     * @brief Checker of naming conventions
     *
     * This is the object that checks the naming conventions
     */
    RulesContainer _checker;

    /**
     * @brief Names of access visibility
     *
     */
    static const std::string _accessLabel[];
};

} // end namespace

#endif
