#include "GCCPluginAPI.h"
#include <iostream>

namespace GPPGeneric
{

void GCCPluginAPI::warning(const tree& decl, const std::string& message)
{
    //warning_at(DECL_SOURCE_LOCATION(decl), 0, message.c_str());
    std::cerr << message << std::endl;
}

void GCCPluginAPI::error(const tree& decl, const std::string& message)
{
    //error_at(DECL_SOURCE_LOCATION(decl), 0,  message.c_str());
    std::cerr << message << std::endl;
}

} // end GPPGeneric
