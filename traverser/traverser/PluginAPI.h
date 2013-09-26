/**
 * @file     PluginAPI.h
 * @brief    Provides the interface of plugin that makes the warning messages.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for traverser providing PluginAPI interface.
 *
 * System:    traverser: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 06, 2013
 *
 * This file is part of traverser.
 *
 * traverser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * traverser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with traverser. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GPP_PLUGIN_API_H
#define GPP_PLUGIN_API_H

#include <GenericTree.h>
#include <string>

namespace NamingChecker
{

/**
 * @brief Interface of plugin that makes the warning messages.
 *
 */
struct PluginApi
{
    /**
     * @brief gives the warning message.
     *
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param message the message to print
     */
    virtual void warning(const GPPGeneric::GenericTree& decl, const std::string& message) = 0;

    /**
     * @brief gives the error message.
     *
     * @param decl is the tree of the name it is used for the error message to print the location of the name
     * @param message the message to print
     */
    virtual void error(const GPPGeneric::GenericTree& decl, const std::string& message) = 0;
};

} // end namespace

#endif
