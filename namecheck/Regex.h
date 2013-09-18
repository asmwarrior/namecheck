/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Regex.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing Regex struct.
*/

#ifndef REGEX_H
#define REGEX_H

#include "Rule.h"

namespace NamingChecker
{

class Regex : public Rule
{
private:

    virtual void checkRule(const std::string& declarationName, Result& result) const;

    BoostRegex _regex;
    Message _errmsg;
};

} //end namespace

#endif