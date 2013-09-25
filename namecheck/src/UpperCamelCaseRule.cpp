/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        UpperCamelCaseRule.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing UpperCamelCaseRule class.
*/

#include "namecheck/UpperCamelCaseRule.h"

namespace NamingChecker
{

UpperCamelCaseRule::UpperCamelCaseRule() : RegexCollection(3)
{
    _regexs[0] = "^\\u.*?";
    _regexs[1] = "^_?[\\l\\u\\d]*$";
    _regexs[2] = ".*?\\l$";

    _errmsgs[0] = "names should start with uppercase";
    _errmsgs[1] = "names should not be written using underscore, only is supported one underscore at the beginning";
    _errmsgs[2] = "names should end with lowercase";
}

} //end namespace