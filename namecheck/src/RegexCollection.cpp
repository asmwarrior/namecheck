/**
 * Taller Technologies - Software Development Company
 * Copyright 2013 - All rights reserved
 *
 * @file        RegexCollection.cpp
 * @author      Franco Riberi
 * @date        2013-09-17
 * @brief       This is an implementation of RegexCollection class
 */

#include "namecheck/RegexCollection.h"

namespace NamingChecker
{

RegexCollection::RegexCollection(const size_t length) : _regexs(length), _errmsgs(length)
{}

void RegexCollection::checkRule(const std::string& declarationName, Result& result) const
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