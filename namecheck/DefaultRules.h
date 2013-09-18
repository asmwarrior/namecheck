/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        DefaultRules.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing DefaultRules class.
*/

#ifndef DEFAULT_RULES_H
#define DEFAULT_RULES_H

#include "Rule.h"

namespace NamingChecker
{

class DefaultRules : public Rule
{
public:

    DefaultRules(const size_t length);

private:

    virtual void checkRule(const std::string& declarationName, Result& result) const;

protected:

    typedef std::vector<BoostRegex> Regexs;
    typedef std::vector<Message> ErrorMsgs;

    Regexs _regexs;
    ErrorMsgs _errmsgs;
};

} //end namespace

#endif