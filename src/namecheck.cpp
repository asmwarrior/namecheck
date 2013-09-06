#include "NamingConventionPlugin.h"
#include "GCCPluginAPI.h"
#include "GenericTraverser.h"
extern "C"
{
#include "cp/cp-tree.h"
}
#include <memory>
#include <iostream>

int plugin_is_GPL_compatible;

using namespace GPPGeneric;

static struct plugin_info naming_info =
{
    "0.1",                        // version
    "Naming Convention Plugin"    // help
};

extern "C" void gate_callback(void*, void*)
{
    // If there were errors during compilation,
    // let GCC handle the exit.
    //
    if (!(errorcount || sorrycount))
    {        
        GenericTraverser traverser;
        const std::auto_ptr<BasePlugin> plugin(new NamingConventionPlugin());
        const std::auto_ptr<PluginAPI> api(new GCCPluginAPI());
        plugin->initialize(api.get());
        std::clog << "processing " << main_input_filename << std::endl;
        traverser.traverse(global_namespace, plugin->getVisitor());
    }
    exit(EXIT_SUCCESS); 
}

extern "C" int plugin_init(plugin_name_args* info, plugin_gcc_version* /* version */)
{
    std::cerr << "starting " << info->base_name << std::endl;

    // Disable assembly output.
    asm_file_name = HOST_BIT_BUCKET;

    // Register callbacks.
    register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback, 0);
    register_callback(info->base_name, PLUGIN_INFO, NULL, &naming_info);

    return EXIT_SUCCESS;
}
