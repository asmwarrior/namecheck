/**
 * Taller Technologies - Software Development Company
 * Copyright 2013 - All rights reserved
 *
 * @file        UpperUnderscoreRule.cpp
 * @author      Franco Riberi
 * @date        2013-09-17
 * @brief       Header file for namecheck providing UpperUnderscoreRule class.
 */

#include "namecheck/UpperUnderscoreRule.h"

namespace NamingChecker
{

UpperUnderscoreRule::UpperUnderscoreRule() : RegexCollection(3)
{
    _regexs[0] = "^\\u.*?";
    _regexs[1] = "[\\u_]*?";
    _regexs[2] = ".*?\\u$";

    _errmsgs[0] = "names should start with uppercase";
    _errmsgs[1] = "names should be written with uppercase and underscore";
    _errmsgs[2] = "names should end with uppercase";
}

} //end namespace