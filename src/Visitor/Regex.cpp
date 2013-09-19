/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Regex.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       This is the implementation of Regex interface
*/

#include <iostream>
#include "Visitor/Regex.h"

namespace NamingChecker
{

Regex::Regex(std::string reg, std::string msg): _regex(reg), _errmsg(msg)
{}

void Regex::checkRule(const std::string& declarationName, Result& result) const
{
    result._match = boost::regex_match(declarationName, _regex);
    if (!result._match)
        result._message = _errmsg;
    else
        result._message.clear();
}

} // end namespace