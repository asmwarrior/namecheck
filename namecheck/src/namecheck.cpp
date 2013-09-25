/**
 * Taller Technologies - Software Development Company
 * Copyright 2013 - All rights reserved
 *
 * @file        namecheck.cpp
 * @author      Francisco Herrero
 * @date        2013-09-06
 * @brief       This is the main file that launches the namecheck plugin
 */

#include <libintl.h>
#include <locale.h>
#include "namecheck/NamingConventionPlugin.h"
#include "namecheck/GCCPluginAPI.h"
#include <traverser/TraverserCppThree.h>
#include <traverser/TraverserCppEleven.h>

#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 6)
extern "C"
{
#include "cp/cp-tree.h"
#include "plugin-version.h"
}
#else
#include "cp/cp-tree.h"
#include "plugin-version.h"
#endif

#include <memory>
#include <iostream>

int plugin_is_GPL_compatible; //not rename

std::string pathFile;
static struct plugin_info namingInfo =
{
    "0.1",                        // version
    "Naming Convention Plugin"    // help
};

/**
 * @brief Set data for gettext. For more infomation, see Linux man page
 */
void initGettext()
{
    setlocale(LC_ALL, "");
    bindtextdomain("namecheck", "/usr/share/locale");
    textdomain("namecheck");
}

extern "C" void gate_callback_cpp_three(void*, void*)
{
    // If there were errors during compilation,
    // let GCC handle the exit.
    //
    if (!(errorcount || sorrycount))
    {
        GPPGeneric::TraverserCppThree traverser;
        const std::auto_ptr<NamingChecker::BasePlugin> plugin(new NamingChecker::NamingConventionPlugin(pathFile.c_str()));
        const std::auto_ptr<NamingChecker::PluginApi> api(new NamingChecker::GCCPluginApi());
        plugin->initialize(api.get());
        std::clog << "processing " << main_input_filename << std::endl;
        traverser.traverse(global_namespace, plugin->getVisitor());
    }
    exit(EXIT_SUCCESS);
}

extern "C" void gate_callback_cpp_eleven(void*, void*)
{
    // If there were errors during compilation,
    // let GCC handle the exit.
    //
    if (!(errorcount || sorrycount))
    {
        GPPGeneric::TraverserCppEleven traverser;
        const std::auto_ptr<NamingChecker::BasePlugin> plugin(new NamingChecker::NamingConventionPlugin(pathFile.c_str()));
        const std::auto_ptr<NamingChecker::PluginApi> api(new NamingChecker::GCCPluginApi());
        plugin->initialize(api.get());
        std::clog << "processing with c++11 " << main_input_filename << std::endl;
        traverser.traverse(global_namespace, plugin->getVisitor());
    }
    exit(EXIT_SUCCESS);
}

extern "C" int plugin_init(plugin_name_args* info, plugin_gcc_version* version)
{
    std::cerr << "starting " << info->base_name << std::endl;

    // Disable assembly output.
    asm_file_name = HOST_BIT_BUCKET;

    if (!plugin_default_version_check(version, &gcc_version))
        return 1;

    if ((info->argc == 1) && !(strcmp(info->argv->key, "path")))
    {
        pathFile = info->argv->value;
    }

    //implement this when trying to execute the plugin with c++0x or c++03
    // if(info->argc == 1 && (strcmp(info->argv->key,"c++0x") || strcmp(info->argv->key, "c++11")))
    //     register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback_cpp_eleven, 0);
    // else
    //     register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback_cpp_three, 0);
    initGettext();
    register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback_cpp_three, 0);
    register_callback(info->base_name, PLUGIN_INFO, NULL, &namingInfo);

    return EXIT_SUCCESS;
}