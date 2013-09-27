/*
 * @file     GCCPluginAPI.cpp
 * @brief    This is the implementation of GCCPluginAPI interface.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Source file for api providing GCCPluginAPI implementation.
 *
 * System:   api
 * Language: C++
 *
 * @date September 06, 2013
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

#include <iostream>
#include "api/GCCPluginAPI.h"

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
	extern "C"
	{
		#include "diagnostic-core.h"
	}
#else
	#include "diagnostic-core.h"
#endif

namespace Api
{

void GCCPluginApi::warning(const GenericTree& decl, const std::string& message)
{
    warning_at(DECL_SOURCE_LOCATION(decl), 0, message.c_str());
}

void GCCPluginApi::error(const GenericTree& decl, const std::string& message)
{
    error_at(DECL_SOURCE_LOCATION(decl), 0,  message.c_str());
}

} // end namespace