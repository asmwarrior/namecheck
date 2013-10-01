/*
 * @file     Namecheck.cpp
 * @brief    This is the main file that launches the namecheck plugin.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing main file that launches the plugin.
 *
 * System:   namecheck: Naming Convention Checker
 * Language: C++
 *
 * @date September 06, 2013
 *
 * This file is part of namecheck
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <memory>
#include <iostream>
#include "namecheck/NamingConventionPlugin.h"
#include "compilerapi/GCCPluginAPI.h"
#include "traverser/TraverserCppThree.h"
#include "traverser/TraverserCppEleven.h"

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

/**
 * Please, don't delete or rename. This variable is used by GCC
 * to identify the plugin is GPL licensed
 */
int plugin_is_GPL_compatible;

namespace NSNamingChecker
{

std::string pathFile;

static struct plugin_info namingInfo =
{
    "0.1",                        // version
    "Naming Convention Plugin"    // help
};

/**
 * @brief Represents the arguments of the plugin
 */
enum PluginArguments
{
    ConfigurationFile,
    NumberOfArguments
};

extern "C" void gate_callback_cpp_three(void*, void*)
{
    // If there were errors during compilation,
    // let GCC handle the exit.
    //
    if (errorcount == 0 && sorrycount == 0)
    {
        NSGppGeneric::TraverserCppThree traverser;
        const std::auto_ptr<NSGppGeneric::BasePlugin> plugin(new NSNamingChecker::NamingConventionPlugin(pathFile.c_str()));
        const std::auto_ptr<NSCompilerApi::IPluginApi> api(new NSCompilerApi::GCCPluginApi());
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
    if (errorcount == 0 && sorrycount == 0)
    {
        NSGppGeneric::TraverserCppEleven traverser;
        const std::auto_ptr<NSGppGeneric::BasePlugin> plugin(new NSNamingChecker::NamingConventionPlugin(pathFile.c_str()));
        const std::auto_ptr<NSCompilerApi::IPluginApi> api(new NSCompilerApi::GCCPluginApi());
        plugin->initialize(api.get());
        std::clog << "processing with c++11 " << main_input_filename << std::endl;
        traverser.traverse(global_namespace, plugin->getVisitor());
    }
    exit(EXIT_SUCCESS);
}

extern "C" int plugin_init(plugin_name_args* info, plugin_gcc_version* version)
{
    size_t ret = EXIT_SUCCESS;
    std::cerr << "starting " << info->base_name << std::endl;

    // Disable assembly output.
    asm_file_name = HOST_BIT_BUCKET;

    if (!plugin_default_version_check(version, &gcc_version))
        ret = EXIT_FAILURE;

    if ((info->argc == 1) && (strcmp(info->argv[ConfigurationFile].key, "path")) == 0)
        pathFile = info->argv[ConfigurationFile].value;

    register_callback(info->base_name, PLUGIN_OVERRIDE_GATE, &gate_callback_cpp_three, 0);
    register_callback(info->base_name, PLUGIN_INFO, NULL, &namingInfo);

    return ret;
}

} //end namespace