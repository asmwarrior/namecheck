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
 * Contents: Header file for api providing PluginAPI interface.
 *
 * System:    api
 * Language:  C++
 *
 * @date      September 06, 2013
 *
 * This file is part of api.
 *
 * api is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * api is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with api. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include <string>
#include "GenericTree.h"

namespace Api
{

/**
 * @brief Interface of plugin that makes the warning messages.
 *
 */
struct PluginApi
{
    /**
     * @brief Represent a message to print
     */
    typedef std::string Message;

    /**
     * @brief gives the warning message.
     *
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param message the message to print
     */
    virtual void warning(const GenericTree& decl, const Message& message) = 0;

    /**
     * @brief gives the error message.
     *
     * @param decl is the tree of the name it is used for the error message to print the location of the name
     * @param message the message to print
     */
    virtual void error(const GenericTree& decl, const Message& message) = 0;
};

} // end namespace

#endif
