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

#include <traverser/GenericTree.h>
#include <string>

using namespace GPPGeneric;

namespace NamingCheck
{

/**
*  @brief Interface of plugin that makes the warning messages. 
*
*/
struct PluginApi
{
	/**
    * @brief gives the warning message.
    *
    *
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param message the message to print
    */
    virtual void warning(const GenericTree& decl, const std::string& message) = 0;

    /**
    * @brief gives the error message.
    *
    *
    * @param decl is the tree of the name it is used for the error message to print the location of the name
    * @param message the message to print
    */
    virtual void error(const GenericTree& decl, const std::string& message) = 0;
};

} // end GPPGeneric

#endif