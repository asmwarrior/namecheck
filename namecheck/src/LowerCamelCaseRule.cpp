/*
 * @file     LowerCamelCaseRule.cpp
 * @brief    This is the implementation of LowerCamelCaseRule interface.
 *           It is a specific regex.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing LowerCamelCaseRule implementation.
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

#include "namecheck/LowerCamelCaseRule.h"

namespace NSNamingChecker
{

LowerCamelCaseRule::LowerCamelCaseRule() : RegexCollection(3)
{
    _regexs[0] = "^\\l.*?";
    _regexs[1] = "^_?[\\l\\u\\d]*$";
    _regexs[2] = ".*?[\\l\\d]$";

    _errmsgs[0] = gettext("should start with lowercase");
    _errmsgs[1] = gettext("should not be written using underscores, only one underscore at the beginning is supported");
    _errmsgs[2] = gettext("should end with lowercase or digit");
}

} //end namespace