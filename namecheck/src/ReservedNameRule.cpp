/**
 * Taller Technologies - Software Development Company
 * Copyright 2013 - All rights reserved
 *
 * @file        LowerUnderscoreRule.cpp
 * @author      Franco Riberi
 * @date        2013-09-17
 * @brief       Header file for namecheck providing LowerUnderscoreRule class.
 */

#include "namecheck/ReservedNameRule.h"

namespace NamingChecker
{

ReservedNameRule::ReservedNameRule() : RegexCollection(MatchAmount)
{
    _regexs[MatchNotUnderscoreUpper] = "^_\\u.*?";
    _regexs[MatchNotEDOrUpper] = "^E(\\d|\\u).*?";
    _regexs[MatchNotIsOrToLower] = "^(is|to)\\l.*?";
    _regexs[MatchNotLCUnderscore] = "^LC_\\u.*?";
    _regexs[MatchNotSIGUnderscore] = "^SIG_?\\u.*?";
    _regexs[MatchNotStrMemWcsLower] = "^(str|mem|wcs)\\l.*?";
    _regexs[MatchNotUnderscoretEnding] = ".*?_t$";

    _errmsgs[MatchNotUnderscoreUpper] = "Names should not start with _ and an Uppercase";
    _errmsgs[MatchNotEDOrUpper] = "Names beginning with a capital ‘E’ followed by a digit or uppercase letter may be used for additional error code names";
    _errmsgs[MatchNotIsOrToLower] = "Names that begin with either ‘is’ or ‘to’ followed by a lowercase letter may be used for additional character testing and conversion functions.";
    _errmsgs[MatchNotLCUnderscore] = "Names that begin with ‘LC_’ followed by an uppercase letter may be used for additional macros specifying locale attributes.";
    _errmsgs[MatchNotSIGUnderscore] = "Names that begin with ‘SIG’ or 'SIG_' followed by an uppercase letter are reserved for additional signal names or actions.";
    _errmsgs[MatchNotStrMemWcsLower] = "Names beginning with ‘str’, ‘mem’, or ‘wcs’ followed by a lowercase letter are reserved for additional string and array functions.";
    _errmsgs[MatchNotUnderscoretEnding] = "Names that end with ‘_t’ are reserved for additional type names.";
}

} //end namespace