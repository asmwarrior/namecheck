/*
 * @file     LowerUnderscoreRule.cpp
 * @brief    This is the implementation of LowerUnderscoreRule interface.
 *           It is a specific regex.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing LowerUnderscoreRule implementation.
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

#include "namecheck/LowerUnderscoreRule.h"

namespace NamingChecker
{

LowerUnderscoreRule::LowerUnderscoreRule() : RegexCollection(3)
{
    _regexs[0] = "^_\\l.*?";
    _regexs[1] = "^_?[\\l\\u\\d]*$";
    _regexs[2] = ".*?[^\\u_\\d]\\l?$";

    _errmsgs[0] = "names should start with underscore followed by a lowercase";
    _errmsgs[1] = "names should not be written using underscore, only is supported one underscore at the beginning";
    _errmsgs[2] = "names should end with lowercase";
}

} //end namespace