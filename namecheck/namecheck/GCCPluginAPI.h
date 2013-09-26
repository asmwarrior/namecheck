/**
 * @file     GCCPluginAPI.h
 * @brief    Provides the API for error and warning messages for GCC.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing GCCPluginAPI interface.
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

#ifndef GCC_PLUGIN_API
#define GCC_PLUGIN_API

#include "PluginAPI.h"

namespace NamingChecker
{

/**
 * @brief The Api for error and warning messages for GCC.
 *
 */
class GCCPluginApi: public PluginApi
{
    /**
     * @brief gives gcc the warning message.
     *
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param message the message to print
     */
    virtual void warning(const GPPGeneric::GenericTree& decl, const std::string& message);

    /**
     * @brief gives gcc the error message.
     *
     * @param decl is the tree of the name it is used for the warning message to print the location of the name
     * @param message the message to print
     */
    virtual void error(const GPPGeneric::GenericTree& decl, const std::string& message);
};

} // end namespace

#endif