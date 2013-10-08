/**
 * @file     RegexCollection.h
 * @brief    Provides the interface to represents a default regexs
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing RegexCollection class.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 17, 2013
 *
 * This file is part of namecheck.
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DEFAULT_RULES_H
#define DEFAULT_RULES_H

#include <libintl.h>
#include "Rule.h"

namespace NSNamingChecker
{

/**
 * @brief Specific Rules
 *
 * This class represents a default rule, composed by many regexes.
 */
class RegexCollection : public IRule
{
protected:

    /**
     * @brief Constructor of class
     *
     * @param length amount of regexes in the rule.
     */
    RegexCollection(const size_t length);

    /**
     * @brief Represents a collection of regex
     */
    typedef std::vector<RegexType> Regexs;

    /**
     * @brief Represents a message to show
     */
    typedef std::vector<NSCompilerApi::IPluginApi::Message> ErrorMsgs;

    /**
     * @brief To load the regex
     */
    Regexs _regexs;

    /**
     * @brief To load the message error. One message for each regex
     */
    ErrorMsgs _errmsgs;

private:

    virtual void checkRule(const DeclName& declarationName, Result& result) const;
};

} //end namespace

#endif
