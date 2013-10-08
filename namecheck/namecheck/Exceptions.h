/**
 * @file     Exceptions.h
 * @brief    This header defines all namecheck exceptions
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing exceptions definitions.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 19, 2013
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

#ifndef NAMECHECK_EXCEPTIONS_H
#define NAMECHECK_EXCEPTIONS_H

#include <mili/mili.h>

namespace NSNamingChecker
{

struct NamecheckExceptionHierarchy {};
typedef mili::GenericException<NamecheckExceptionHierarchy> NamecheckException;

//State exception
class StateException: public NamecheckException
{
public:
    StateException(const std::string& description): NamecheckException(description) {}
};

//File exceptions
DEFINE_SPECIFIC_EXCEPTION_TEXT(FileNotFound, NamecheckExceptionHierarchy, "The configuration file not found.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(InvalidFormatFile, NamecheckExceptionHierarchy, "The configuration file does not have the appropriate format.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(NotDefinedRegex, NamecheckExceptionHierarchy, "Should define a regex.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(NotDefinedErrorMessage, NamecheckExceptionHierarchy, "Should define a error message.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(InvalidRegex, NamecheckExceptionHierarchy, "Invalid regex defined.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(InvalidDeclaration, NamecheckExceptionHierarchy, "Invalid name declaration.");
DEFINE_SPECIFIC_EXCEPTION_TEXT(InvalidRuleType, NamecheckExceptionHierarchy, "Rule type invalid.");

} // end namespace
#endif
