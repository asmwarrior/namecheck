/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GCCPluginAPI.cpp
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       This is the implementation of GCCPluginAPI interface
*/

#include "GCCPluginAPI.h"
#include <iostream>

extern "C"
{
#include "diagnostic-core.h"
}


namespace GPPGeneric
{

void GCCPluginApi::warning(const GenericTree& decl, const std::string& message)
{
    warning_at(DECL_SOURCE_LOCATION(decl), 0, message.c_str());
}

void GCCPluginApi::error(const GenericTree& decl, const std::string& message)
{
    error_at(DECL_SOURCE_LOCATION(decl), 0,  message.c_str());
}

} // end GPPGeneric