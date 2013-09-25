/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        LowerCamelCaseRule.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing LowerCamelCaseRule class.
*/

#include "namecheck/LowerCamelCaseRule.h"

namespace NamingChecker
{

LowerCamelCaseRule::LowerCamelCaseRule() : DefaultRules(3)
{
    _regexs[0] = "^\\l.*?";
    _regexs[1] = "^_?[\\l\\u\\d]*$";
    _regexs[2] = ".*?[^\\u_\\d]\\l?$";

    _errmsgs[0] = "names should start with lowercase";
    _errmsgs[1] = "names should not be written using underscore, only is supported one underscore at the beginning";
    _errmsgs[2] = "names should end with lowercase";
}

} //end namespace