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
#include "Rule.h"
#include "RulesContainer.h"
#include "BasePlugin.h"

namespace NamingChecker
{

class NamingConventionPlugin : public BasePlugin
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
     * @brief check String Literals
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the string literal it is used for the warning message to print the location of the SL
     * @param name the name to check
     */
    virtual void visitStringLiteral(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks variable  name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitVariableDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks global constant name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitGlobalConstDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks enum name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitEnumTypeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks enum value name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitEnumValueDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks function name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitFunctionDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks parameter name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitParameterDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/);

    /**
     * @brief checks typedef name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitTypeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
    * @brief checks class name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitClassDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks union name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitUnionDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks union member name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitUnionValueDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks struct name
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitStructDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks Variable Declarations
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitMethodDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::AccessModifier access, const GPPGeneric::DeclarationName& name, bool /*isConst*/);

    /**
     * @brief checks Variable Declarations
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitAttributeDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::AccessModifier access, const GPPGeneric::DeclarationName& name, bool /*isConst*/, const std::string& /*typeName*/);

    /**
     * @brief checks Variable Declarations
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitNamespaceDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief checks Template Type Parameter Declarations
     *
     * check if it is correct according to the checker, if not prints a warning (using the plugin)
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param name the name to check
     */
    virtual void visitTemplateTypeParameterDeclaration(const GPPGeneric::GenericTree decl, const GPPGeneric::DeclarationName& name);

    /**
     * @brief calls the warning message maker of the plugin
     *
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param message the message to print in the warning
     */
    void setPluginWarning(const GPPGeneric::GenericTree decl, const std::string& message);

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
    static const char* _accessLabel[];
};

} // end namespace

#endif