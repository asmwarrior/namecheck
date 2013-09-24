/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Exceptions.h
* @author      Franco Riberi
* @date        2013-09-19
* @brief       Header file for namecheck providing Exception handler.
*/

#ifndef NAMECHECK_EXCEPTIONS_H
#define NAMECHECK_EXCEPTIONS_H

#include <mili/mili.h>

namespace NamingChecker
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
