#include "NamingConventionChecker.h"

NamingConventionChecker::NamingConventionChecker() : regexs(kNameRulesSize), errmsgs(kNameRulesSize)
{
    regexs[kMatch_not__Upper] = "^_\\u.*?";
    regexs[kMatch_not_ED_or_Upper] = "^E(\\d|\\u).*?";
    regexs[kMatch_not_is_or_to_Lower] = "^(is|to)\\l.*?";
    regexs[kMatch_not_LC_] = "^LC_\\u.*?";
    regexs[kMatch_not_SIG_] = "^SIG_?\\u.*?";
    regexs[kMatch_not_strmemwcsLower] = "^(str|mem|wcs)\\l.*?";
    regexs[kMatch_not__tEnding] = ".*?_t$";
    regexs[kMatch_Upper] = "^\\u.*?";
    regexs[kMatch_Lower] = "^\\l.*?";

    errmsgs[kMatch_not__Upper] = "Names should not start with _ and an Uppercase";
    errmsgs[kMatch_not_ED_or_Upper] = "Names beginning with a capital ‘E’ followed by a digit or uppercase letter may be used for additional error code names";
    errmsgs[kMatch_not_is_or_to_Lower] = "Names that begin with either ‘is’ or ‘to’ followed by a lowercase letter may be used for additional character testing and conversion functions.";
    errmsgs[kMatch_not_LC_] = "Names that begin with ‘LC_’ followed by an uppercase letter may be used for additional macros specifying locale attributes.";
    errmsgs[kMatch_not_SIG_] = "Names that begin with ‘SIG’ or 'SIG_' followed by an uppercase letter are reserved for additional signal names or actions.";
    errmsgs[kMatch_not_strmemwcsLower] = "Names beginning with ‘str’, ‘mem’, or ‘wcs’ followed by a lowercase letter are reserved for additional string and array functions.";
    errmsgs[kMatch_not__tEnding] = "Names that end with ‘_t’ are reserved for additional type names.";
    errmsgs[kMatch_Upper] = "Class and Namespace names should start with uppercase";
    errmsgs[kMatch_Lower] = "names should start with lowercase";
}

bool NamingConventionChecker::correct_class_name(const std::string &s, std::string &errmsg)
{
    bool result = correct_general_name(s,errmsg);
    if(result)
    {
        std::vector<int> v;
        v.push_back(kMatch_Upper);
        result = generic_checker(s, errmsg, v);
    }
    return result;
}

bool NamingConventionChecker::correct_general_name(const std::string &s, std::string &errmsg)
{
    bool result = true;
    int i=0;
    while(result && i != kMatch_Upper)
    {
        result=!boost::regex_match(s, regexs[i]);
        if(!result)
            errmsg=errmsgs[i];
        ++i;
    }
    return result;
}

bool NamingConventionChecker::generic_checker(const std::string &s, std::string &errmsg, std::vector<int> &v)
{
    bool result = true;
    unsigned int i=0;
    while(result && i != v.size())
    {
        result=boost::regex_match(s, regexs[(v[i])]);
        if(!result)
            errmsg=errmsgs[(v[i])];
        ++i;
    }
    return result;
}

bool NamingConventionChecker::correct_variable_name(const std::string &s, std::string &errmsg)
{
    bool result = correct_general_name(s,errmsg);
    if(result)
    {
        std::vector<int> v;
        v.push_back(kMatch_Lower);
        result = generic_checker(s, errmsg, v);
    }
    return result;
}

bool NamingConventionChecker::correct_method_name(const std::string &s, std::string &errmsg)
{
    bool result = correct_general_name(s,errmsg);
    if(result)
    {
        std::vector<int> v;
        v.push_back(kMatch_Lower);
        result = generic_checker(s, errmsg, v);
    }
    return result;
}