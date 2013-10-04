/*
 * @file     UpperUnderscoreRule.cpp
 * @brief    This is the implementation of UpperUnderscoreRule interface.
 *           It is a specific regex.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing UpperUnderscoreRule implementation.
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

#include "namecheck/UpperUnderscoreRule.h"

namespace NSNamingChecker
{

UpperUnderscoreRule::UpperUnderscoreRule() : RegexCollection(3)
{
    _regexs[0] = "^\\u.*?";
    _regexs[1] = "[\\u_]*?";
    _regexs[2] = ".*?\\u$";

    _errmsgs[0] = gettext("should start with uppercase");
    _errmsgs[1] = gettext("should be written with uppercase and underscore");
    _errmsgs[2] = gettext("should end with uppercase");
}

} //end namespace