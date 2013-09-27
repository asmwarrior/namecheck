/*
 * @file     BasePlugin.cpp
 * @brief    This is the implementation of BasePlugin interface.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Source file for traverser providing BasePlugin implementation.
 *
 * System:   traverser
 * Language: C++
 *
 * @date September 06, 2013
 *
 * This file is part of traverser
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

#include <iostream>
#include "traverser/BasePlugin.h"

namespace GPPGeneric
{

GenericVisitor* BasePlugin::getVisitor()
{
    return this;
}

void BasePlugin::initialize(Api::PluginApi* plugin)
{
    _plugin = plugin;
}

} // end namespace