/**
 * @file     GenericTree.h
 * @brief    This file contains all the definitions needed in api
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for api providing GenericTree type.
 *
 * System:    api
 * Language:  C++
 *
 * @date      September 13, 2013
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

#ifndef GCC_GENERIC_TREE_H
#define GCC_GENERIC_TREE_H

#include <gmp.h>

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
	extern "C"
	{
		#include "config.h"
		#undef HAVE_DECL_GETOPT
		#define HAVE_DECL_GETOPT 1
		#include "gcc-plugin.h"
		#include "tree.h"
	}
#else
	#include "config.h"
	#undef HAVE_DECL_GETOPT
	#define HAVE_DECL_GETOPT 1
	#include "gcc-plugin.h"
	#include "tree.h"
#endif


namespace Api
{

/**
* @brief A tree node (is a pointer type).
*
*/
typedef tree GenericTree;

}

#endif
