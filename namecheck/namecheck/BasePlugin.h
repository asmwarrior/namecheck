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

#ifndef GPP_BASE_PLUGIN_H
#define GPP_BASE_PLUGIN_H

#include <traverser/GenericVisitor.h>
#include "PluginAPI.h"

namespace NamingChecker
{

/**
 *  @brief Base class for the visitor.
 *
 * This class add to the vistor's interface the initialization method, the _plugin attribute and a method to get
 * the visitor.
 */
class BasePlugin: private GPPGeneric::GenericVisitor
{
public:

    /**
     * @brief this sets the _plugin .
     *
     * @param plugin this is the pointer to the plugin that is going to be set.
     */
    void initialize(PluginApi* plugin);

    /**
     * @brief this gets the visitor.
     *
     * The visitor is this class. But it could change.
     * @return The visitor (in this case a pointer to this).
     */
    GPPGeneric::GenericVisitor* getVisitor();

protected:

    /**
     * @brief This is the plugin for the warnings and error messages.
     *
     */
    PluginApi* _plugin;

};

} // end namespace

#endif
