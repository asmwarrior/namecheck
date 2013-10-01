/*
 * @file     RegexCollection.cpp
 * @brief    This is the implementation of RegexCollection interface.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing RegexCollection implementation.
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

#include "namecheck/RegexCollection.h"

namespace NSNamingChecker
{

RegexCollection::RegexCollection(const size_t length) : _regexs(length), _errmsgs(length)
{}

void RegexCollection::checkRule(const DeclName& declarationName, Result& result) const
{
    assert(_regexs.size() != 0);
    size_t i(0);
    do
    {
        result._match = boost::regex_match(declarationName, _regexs[i]);
        ++i;
    }
    while (result._match && i < _regexs.size());
    if (!result._match)
        result._message = _errmsgs[i - 1];
    else
        result._message.clear();
}

} //end namespace