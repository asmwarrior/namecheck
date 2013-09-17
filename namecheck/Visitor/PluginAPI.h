/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        PluginAPI.h
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing PluginAPI interface.
*/

#ifndef GPP_PLUGIN_API_H
#define GPP_PLUGIN_API_H

#include "Traverser/GenericTree.h"
#include <string>

namespace GPPGeneric
{

/**
*  @brief Interface of plugin that makes the warning messages. 
*
*/
struct PluginApi
{
    virtual void warning(const GenericTree& decl, const std::string& message) = 0;
    virtual void error(const GenericTree& decl, const std::string& message) = 0;
};

} // end GPPGeneric

#endif