/**
 * @file     BasePlugin.h
 * @brief    Provides the interface to BasePlugin class.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for BasePlugin
 *
 * System:    traverser
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

#ifndef GPP_BASE_PLUGIN_H
#define GPP_BASE_PLUGIN_H

#include "GenericVisitor.h"
#include "compilerapi/PluginAPI.h"

namespace NSGppGeneric
{

/**
 *  @brief Base class for the visitor.
 *
 * This class extends the vistor's interface with an initialization method, a _plugin attribute and a method to get
 * the visitor.
 */
class BasePlugin: public IGenericVisitor
{
public:

    /**
     * @brief Sets _api to point to the api attribute.
     *
     * @param api The pointer to the pluginAPI that is going to be set.
     */
    virtual void initialize(NSCompilerApi::IPluginApi* api);

protected:

    /**
     * @brief The api for the warnings and error messages.
     *
     */
    NSCompilerApi::IPluginApi* _api;

};

} // end namespace

#endif
