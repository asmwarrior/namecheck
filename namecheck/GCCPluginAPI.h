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