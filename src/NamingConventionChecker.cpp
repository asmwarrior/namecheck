/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionChecker.cpp
* @author      Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       This is an implementation of NamingConventionChecker class
*/

#include "NamingConventionChecker.h"

namespace NamingChecker
{

NamingConventionChecker::NamingConventionChecker() : _regexs(NameRulesSize), _errmsgs(NameRulesSize)
{
    _regexs[MatchStartWithUpper] = "^\\u.*?";
    _regexs[MatchStartWithLower] = "^\\l.*?";
    _regexs[MatchStartUnderscore] = "^_\\l.*?";
    _regexs[MatchEndLower] = ".*?[^\\u_\\d]\\l?$";
    _regexs[MatchEndUpper] = ".*?\\u$";
    _regexs[MatchEndLowerRestricted] = ".*?\\l$";
    _regexs[MatchUpperAndUnderscore] = "[\\u_]*?";
    _regexs[MatchWithoutUndescore] = "^_?[\\l\\u\\d]*$";

    _errmsgs[MatchStartWithUpper] = "names should start with uppercase";
    _errmsgs[MatchStartWithLower] = "names should start with lowercase";
    _errmsgs[MatchStartUnderscore] = "names should start with underscore followed by a lowercase";
    _errmsgs[MatchEndLower] = "names should end with lowercase";
    _errmsgs[MatchEndUpper] = "names should end with uppercase";
    _errmsgs[MatchEndLowerRestricted] = "names should end with lowercase";
    _errmsgs[MatchUpperAndUnderscore] = "names should be written with uppercase and underscore";
    _errmsgs[MatchWithoutUndescore] = "names should not be written using underscore, only is supported one underscore at the beginning";
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

void NamingConventionChecker::genericChecker(const std::string& declarationName, const Rules& rules, Result& result) const
{
    assert(rules.size() != 0);    
    size_t i(0);
    do
    {
        result.match = boost::regex_match(declarationName, _regexs[rules[i]]); 
        ++i;
    }
    while(result.match && i < rules.size());
    if(!result.match)        
        result.message = _errmsgs[rules[i-1]];    
    else
        result.message.clear();
}

void NamingConventionChecker::ruleCamelCase(Rules& rules) const
{
    rules.push_back(MatchStartWithUpper);
    rules.push_back(MatchWithoutUndescore);
    rules.push_back(MatchEndLowerRestricted);
}

void NamingConventionChecker::ruleCamelBack(Rules& rules) const
{
    rules.push_back(MatchStartWithLower);
    rules.push_back(MatchWithoutUndescore);
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
    rules.push_back(MatchWithoutUndescore);
    rules.push_back(MatchEndLower);
}

}