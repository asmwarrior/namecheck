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

#include "Visitor/PluginAPI.h"
#include "Traverser/GenericTree.h"
#include <string>

namespace GPPGeneric
{

/**
*  @brief The Api for error and warning messages for GCC. 
*
*/
class GCCPluginApi: public PluginApi
{
    /**
    * @brief gives gcc the warning message.
    *
    *
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param message the message to print
    */
    void warning(const GenericTree& decl, const std::string& message);

    /**
    * @brief gives gcc the error message.
    *
    * 
    * @param decl is the tree of the name it is used for the warning message to print the location of the name
    * @param message the message to print
    */
    void error(const GenericTree& decl, const std::string& message);
};

} // end GPPGeneric

#endif