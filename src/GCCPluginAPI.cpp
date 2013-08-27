#include "GCCPluginAPI.h"
#include <iostream>

extern "C" {
#include "diagnostic-core.h"
}

namespace GPPGeneric
{

void GCCPluginAPI::warning(const GenericTree& decl, const std::string& message)
{
    warning_at(DECL_SOURCE_LOCATION(decl), 0, message.c_str());
}

void GCCPluginAPI::error(const GenericTree& decl, const std::string& message)
{
    error_at(DECL_SOURCE_LOCATION(decl), 0,  message.c_str());
}

} // end GPPGeneric
