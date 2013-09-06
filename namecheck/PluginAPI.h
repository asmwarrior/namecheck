#ifndef GPP_PLUGIN_API_H
#define GPP_PLUGIN_API_H

#include "GenericTree.h"

#include <string>

namespace GPPGeneric
{

struct PluginAPI
{
    virtual void warning(const GenericTree& decl, const std::string& message) = 0;
    virtual void error(const GenericTree& decl, const std::string& message) = 0;
};

} // end GPPGeneric

#endif