/**
 * @file     GCCPluginAPI.h
 * @brief    Provides the API for communication from the plugin to gcc.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for api providing GCCPluginAPI interface.
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

#ifndef GCC_PLUGIN_API_H
#define GCC_PLUGIN_API_H

#include "PluginAPI.h"

namespace NSCompilerApi
{

/**
 * @brief The API for communication from the plugin to gcc.
 *
 */
class GCCPluginApi: public IPluginApi
{
    
    virtual void warning(const GenericTree& decl, const Message& message) const;
    
    virtual void error(const GenericTree& decl, const Message& message) const;
};

} // end namespace

#endif
