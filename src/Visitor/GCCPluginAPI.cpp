/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GCCPluginAPI.cpp
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       This is the implementation of GCCPluginAPI interface
*/

#include <iostream>
#include <locale.h>
#include <libintl.h>
#include "Visitor/GCCPluginAPI.h"

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
	extern "C"
	{
	#include "diagnostic-core.h"
	}
#else
	#include "diagnostic-core.h"
#endif

namespace GPPGeneric
{
void GCCPluginApi::warning(const GenericTree& decl, const std::string& message)
{	
    warning_at(DECL_SOURCE_LOCATION(decl), 0, gettext(message.c_str()));
}

void GCCPluginApi::error(const GenericTree& decl, const std::string& message)
{
    error_at(DECL_SOURCE_LOCATION(decl), 0,  gettext(message.c_str()));
}

} // end GPPGeneric