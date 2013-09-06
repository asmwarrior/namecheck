#include "NamingConventionChecker.h"

NamingConventionChecker::NamingConventionChecker() : _regexs(NameRulesSize), _errmsgs(NameRulesSize)
{
    _regexs[MatchStartWithUpper] = "^\\u.*?";
    _regexs[MatchStartWithLower] = "^\\l.*?";
    _regexs[MatchStartUnderscore] = "^_\\l.*?";
    _regexs[MatchEndLower] = ".*?[^\\u_\\d]\\l?$";
    _regexs[MatchEndUpper] = ".*?\\u$";
    _regexs[MatchEndLowerRestricted] = ".*?\\l$";
    _regexs[MatchUpperAndUnderscore] = "[A-Z_]*?";

    _errmsgs[MatchStartWithUpper] = "names should start with uppercase";
    _errmsgs[MatchStartWithLower] = "names should start with lowercase";
    _errmsgs[MatchStartUnderscore] = "names should start with underscore followed by a lowercase";
    _errmsgs[MatchEndLower] = "names should end with lowercase";
    _errmsgs[MatchEndUpper] = "names should end with uppercase";
    _errmsgs[MatchEndLowerRestricted] = "names should end with lowercase";
    _errmsgs[MatchUpperAndUnderscore] = "names should be written with uppercase and underscore";
    setRules();
}

void NamingConventionChecker::setRules()
{    
    ruleCamelCase(_typedefRules);
    ruleCamelCase(_classRules);
    ruleCamelCase(_structRules);
    ruleGlobalCont(_globalConstRules);    
    ruleCamelCase(_enumTypeRules);
    ruleCamelCase(_enumValueRules);
    ruleCamelBack(_methodRules);
    ruleCamelBack(_varRules);
    ruleAttribute(_attributeRules);    
    ruleCamelCase(_unionRules);
    ruleCamelCase(_unionValueRules);
    ruleCamelCase(_namespaceRules);
}

bool NamingConventionChecker::generic_checker(const std::string &s, const Rules& rules, std::string &errmsg) const
{
    bool result(true);
    size_t i(0);
    while(result && i != rules.size())
    {
        result = boost::regex_match(s, _regexs[rules[i]]);
        if(!result)
            errmsg = _errmsgs[rules[i]];
        ++i;
    }
    return result;
}

void NamingConventionChecker::ruleCamelCase(Rules& rules) const
{
    rules.push_back(MatchStartWithUpper);
    rules.push_back(MatchEndLowerRestricted);
}

void NamingConventionChecker::ruleCamelBack(Rules& rules) const
{
    rules.push_back(MatchStartWithLower);
    rules.push_back(MatchEndLower);
}

void NamingConventionChecker::ruleGlobalCont(Rules& rules) const
{
    rules.push_back(MatchStartWithUpper);
    rules.push_back(MatchUpperAndUnderscore);
    rules.push_back(MatchEndUpper);
}

void NamingConventionChecker::ruleAttribute(Rules& rules) const
{
    rules.push_back(MatchStartUnderscore);
    rules.push_back(MatchEndLower);
}