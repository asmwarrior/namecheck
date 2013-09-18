/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        DefaultRules.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       This is an implementation of DefaultRules class
*/

#include "DefaultRules.h"

namespace NamingChecker
{

DefaultRules::DefaultRules(const size_t length) : _regexs(length), _errmsgs(length)
{}

void DefaultRules::checkRule(const std::string& declarationName, Result& result) const
{
    assert(_regexs.size() != 0);
    size_t i(0);
    do
    {
        result._match = boost::regex_match(declarationName, _regexs[i]);
        ++i;
    }
    while (result._match && i < _regexs.size());
    if (!result._match)
        result._message = _errmsgs[i - 1];
    else
        result._message.clear();
}

} //end namespace