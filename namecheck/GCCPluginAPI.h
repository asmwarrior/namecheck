/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GCCPluginAPI.h
* @author      Fracisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing GCCPluginAPI class.
*/

#ifndef GCC_PLUGIN_API
#define GCC_PLUGIN_API

#include "PluginAPI.h"
#include "GenericTree.h"
#include <string>

namespace GPPGeneric
{

class GCCPluginAPI: public PluginAPI
{
    void warning(const GenericTree& decl, const std::string& message);
    void error(const GenericTree& decl, const std::string& message);
};

} // end GPPGeneric

#endif