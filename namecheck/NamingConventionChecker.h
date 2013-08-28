#ifndef NAMING_CONVENTION_CHECKER_H
#define NAMING_CONVENTION_CHECKER_H

#include <string>
#include <boost/regex.hpp>


class NamingConventionChecker
{
public:
    NamingConventionChecker();
    bool correct_class_name(const std::string &s, std::string &errmsg);
    bool correct_general_name(const std::string &s, std::string &errmsg);
    bool correct_variable_name(const std::string &s, std::string &errmsg);
    bool correct_method_name(const std::string &s, std::string &errmsg);

private:
    enum namerules
    {
        kMatch_not__Upper,
        kMatch_not_ED_or_Upper,
        kMatch_not_is_or_to_Lower,
        kMatch_not_LC_,
        kMatch_not_SIG_,
        kMatch_not_strmemwcsLower,
        kMatch_not__tEnding,
        kMatch_Upper,
        kMatch_Lower,
        kNameRulesSize
    };
    bool generic_checker(const std::string &s, std::string &errmsg, std::vector<int> &v);
    std::vector<boost::regex> regexs;
    std::vector<std::string> errmsgs;
};

#endif