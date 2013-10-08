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

#include <libintl.h>
#include <memory>
#include <iostream>
#include "namecheck/NamingConventionPlugin.h"
#include "compilerapi/GCCPluginAPI.h"
#include "traverser/GenericTraverser.h"

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

namespace NSNamingChecker
{

/**
 * @brief PluginData allows encapsulate all the information required by the plugin
 */
struct PluginData
{
    /**
     * @brief To load a configuration file name
     */
    std::string _pathFile;

    /**
     * @brief Represents the arguments of the plugin
     */
    enum PluginArguments
    {
        ConfigurationFile,
        NumberOfArguments
    };

    static struct plugin_info _namingInfo;
};

plugin_info PluginData::_namingInfo =
{   
    "0.1",                        // version
    "Naming Convention Plugin"    // help
};

static PluginData data;

/**     
 * @brief Set data for gettext. For more infomation, see Linux man page     
 */     
void initGettext()      
{       
    setlocale(LC_MESSAGES, "");      
    bindtextdomain("namecheck", "/usr/share/locale");           
    textdomain("namecheck");        
}

extern "C" void gate_callback_cpp_three(void*, void*)
{
    // If there were errors during compilation,
    // let GCC handle the exit.
    //
    if (errorcount == 0 && sorrycount == 0)
    {
        NSGppGeneric::TraverserCppThree traverser;
        const std::auto_ptr<NSGppGeneric::BasePlugin> plugin(new NSNamingChecker::NamingConventionPlugin(data._pathFile.c_str()));
        const std::auto_ptr<NSCompilerApi::IPluginApi> api(new NSCompilerApi::GCCPluginApi());
        plugin->initialize(api.get());
        std::clog << "processing " << main_input_filename << std::endl;
        traverser.traverse(global_namespace, plugin.get());
    }    
}

} //end namespace

/**
 * Please, don't delete or rename. Assert that this plugin is a
 * GPL-compatible license. If this symbol does not exist, the
 * compiler will emit a fatal error.
 */
int plugin_is_GPL_compatible;

/**
 * @brief This fucion is called right after the plugin is loaded.
 *
 * Is responsible for registering all the callbacks required by the
 * plugin and do any other required initialization.
 *
 * @param info plugin invocation information
 * @param version GCC version
 */
extern "C" int plugin_init(plugin_name_args* info, plugin_gcc_version* version)
{
    using namespace NSNamingChecker;

    size_t ret = EXIT_SUCCESS;
    std::cout << "starting " << info->base_name << std::endl;

    if (!plugin_default_version_check(version, &gcc_version))
        ret = EXIT_FAILURE;

    if ((info->argc == 1) && (strcmp(info->argv[PluginData::ConfigurationFile].key, "path")) == 0)
        data._pathFile = info->argv[PluginData::ConfigurationFile].value;

    initGettext();
    register_callback(info->base_name, PLUGIN_EARLY_GIMPLE_PASSES_START, &gate_callback_cpp_three, 0);
    register_callback(info->base_name, PLUGIN_INFO, NULL, &data._namingInfo);

    return ret;
}
