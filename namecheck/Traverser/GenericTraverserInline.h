/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionCheckerInline.h
* @author      Franco Riberi
* @date        2013-09-13
* @brief       Header file for namecheck providing GenericTraverser inline implementation.
*/

#ifndef GENERIC_TRAVERSER_INLINE_H
#error Internal header file
#endif

#include "Traverser/GenericTraverser.h"

inline void GenericTraverser::traverse(const GenericTree ns, GenericVisitor* visitor)
{
    _visitor = visitor;
    traverse(ns);
}