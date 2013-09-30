/*
 * @file     ReservedNameRule.cpp
 * @brief    This is the implementation of ReservedNameRule interface.
 *           It is a specific regex.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing ReservedNameRule implementation.
 *
 * System:   namecheck: Naming Convention Checker
 * Language: C++
 *
 * @date September 17, 2013
 *
 * This file is part of namecheck
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "namecheck/ReservedNameRule.h"

namespace NSNamingChecker
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