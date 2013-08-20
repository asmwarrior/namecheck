#include <stdlib.h>
#include <gmp.h>

#include <cstdlib> // Include before GCC poisons
// some declarations.

extern "C"
{
#include "gcc-plugin.h"
#include "plugin-version.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "intl.h"

#include "tm.h"

#include "cp/cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
}

#include <iostream>
#include <set>

#include "GCCPluginAPI.h"
#include "NamingConventionPlugin.h"
#include "GenericTraverser.h"

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
    if (errorcount || sorrycount)
        return;

    int r(0);

    GenericTraverser traverser;
    GenericVisitor* visitor = new NamingConventionPlugin();
    PluginAPI* api = new GCCPluginAPI();
    visitor->initialize(api);

    //
    // Process AST. Issue diagnostics and set r
    // to 1 in case of an error.
    //
    std::clog << "processing " << main_input_filename << std::endl;

    traverser.traverse(global_namespace, visitor);
    delete api;
    delete visitor;

    exit(r);
}

extern "C" int plugin_init(plugin_name_args* info, plugin_gcc_version* version)
{
    int r(0);

    std::cerr << "starting " << info->base_name << std::endl;

    //
    // Parse options if any.
    //

    // Disable assembly output.
    asm_file_name = HOST_BIT_BUCKET;

    // Register callbacks.
    register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback, 0);
    register_callback(info->base_name, PLUGIN_INFO, NULL, &naming_info);

    return r;
}
