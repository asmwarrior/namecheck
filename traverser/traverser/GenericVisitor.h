/**
 * @file     GenericVisitor.h
 * @brief    Provide an interface for exploring the statements of AST
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for traverser providing GenericVisitor struct.
 *
 * System:    traverser
 * Language:  C++
 *
 * @date      September 06, 2013
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

#ifndef GPP_GENERIC_VISITOR_H
#define GPP_GENERIC_VISITOR_H

#include <string>
#include "api/GenericTree.h"

namespace GPPGeneric
{

/**
* @brief This has the three possible Access states of a member.
*
*
*/
enum AccessModifier
{
    AccessPublic,
    AccessProtected,
    AccessPrivate
};

typedef std::string DeclarationName;

/**
*  @brief The interface for the visitor of the traverser
*
*
*/
struct GenericVisitor
{
    virtual void visitStringLiteral(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitVariableDeclaration(const Api::GenericTree decl, const DeclarationName& name, bool isConst, const std::string& typeName) = 0;
    virtual void visitEnumTypeDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitEnumValueDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitFunctionDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitParameterDeclaration(const Api::GenericTree decl, const DeclarationName& name, bool isConst) = 0;
    virtual void visitTypeDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitClassDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitStructDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitUnionDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitUnionValueDeclaration(const Api::GenericTree decl, const DeclarationName& name, bool isConst, const std::string& typeName) = 0;
    virtual void visitMethodDeclaration(const Api::GenericTree decl, const AccessModifier access, const DeclarationName& name, bool isConst) = 0;
    virtual void visitAttributeDeclaration(const Api::GenericTree decl, const AccessModifier access, const DeclarationName& name, bool isConst, const std::string& typeName) = 0;
    virtual void visitNamespaceDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitGlobalConstDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
    virtual void visitTemplateTypeParameterDeclaration(const Api::GenericTree decl, const DeclarationName& name) = 0;
};

} // end GPPGeneric

#endif
