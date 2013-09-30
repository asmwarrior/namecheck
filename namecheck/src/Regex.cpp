/*
 * @file     Regex.cpp
 * @brief    This is the implementation of Regex interface.
 *           It is a specific rule.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing Regex implementation.
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

#include <iostream>
#include "namecheck/Regex.h"

namespace NamingChecker
{

Regex::Regex(const std::string& reg, const std::string& msg): _regex(reg), _errmsg(msg)
{}

void Regex::checkRule(const std::string& declarationName, Result& result) const
{
    result._match = boost::regex_match(declarationName, _regex);
    if (!result._match)
        result._message = _errmsg;
    else
        result._message.clear();
}

} // end namespace