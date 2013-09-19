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

} // end namespace
#endif
