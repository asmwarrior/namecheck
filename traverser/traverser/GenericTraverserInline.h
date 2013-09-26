/**
 * @file     GenericTraverserInline.h
 * @brief    Provides inline implementation of GenericTraverser
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for traverser providing GenericTraverser inline implementation.
 *
 * System:    traverser
 * Language:  C++
 *
 * @date      September 13, 2013
 *
 * This file is part of traverser.
 *
 * traverser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * traverser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with traverser. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GENERIC_TRAVERSER_INLINE_H
#error Internal header file
#endif

#include "GenericTraverser.h"

inline void GenericTraverser::traverse(const GenericTree ns, GenericVisitor* visitor)
{
    _visitor = visitor;
    traverse(ns);
}