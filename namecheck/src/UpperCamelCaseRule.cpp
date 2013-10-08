/*
 * @file     UpperCamelCaseRule.cpp
 * @brief    This is the implementation of UpperCamelCaseRule interface.
 *           It is a specific regex.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing UpperCamelCaseRule implementation.
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

#include "namecheck/UpperCamelCaseRule.h"

namespace NSNamingChecker
{

UpperCamelCaseRule::UpperCamelCaseRule() : RegexCollection(3)
{
    _regexs[0] = "^\\u.*?";
    _regexs[1] = "^_?[\\l\\u\\d]*$";
    _regexs[2] = ".*?[\\l\\d]$";

    _errmsgs[0] = gettext("should start with uppercase");
    _errmsgs[1] = gettext("should not be written using underscores, only one underscore is supported at the beginning");
    _errmsgs[2] = gettext("should end with lowercase or digit");
}

} //end namespace