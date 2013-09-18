/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Rule.h
* @author      Franco Riberi
* @date        2013-09-16
* @brief       Header file for namecheck providing Rule struct.
*/

#ifndef RULE_H
#define RULE_H

#include <boost/regex.hpp>

namespace NamingChecker
{

typedef boost::regex BoostRegex;
typedef std::string Message;

struct Result
{
    bool _match;
    Message _message;
};

struct Rule
{
    virtual void checkRule(const std::string& declarationName, Result& result) const = 0;
};

} //end namespace

#endif