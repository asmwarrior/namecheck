/**
 * @file     GenericTraverser.h
 * @brief    Provides the interface to GenericTraverser class.
 *           This is traverses the AST tree.
 *
 * @author   Francisco Herrero
 * @email    francisco.herrero AT tallertechnologies.com
 *
 * @author   Marcos Diaz
 * @email    marcos.diaz AT tallertechnologies.com
 *
 * Contents: Header file for Explorer AST Tree providing GenericTraverser interface.
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

#ifndef PLUGIN_MEDIATOR_H
#define PLUGIN_MEDIATOR_H

#include <string>
#include "GenericVisitor.h"
#include "compilerapi/GenericTree.h"

namespace NSGppGeneric
{

class GenericTraverser;

/**
 * @brief Represents a traverser of the AST (Abstract Syntax Tree) for C++03.
 */
typedef GenericTraverser TraverserCppThree;

/**
 * @brief Represents a traverser of the AST for C++0x.
 */
typedef GenericTraverser TraverserCppEleven;

/**
 * @brief A class that traverses the AST tree.
 *
 */
class GenericTraverser
{
public:

    /**
     * @brief Sets the visitor and traverses the given namespace.
     *
     * @param ns this should be the global namespace to process.
     * @param visitor the visitor to set.
     */
    void traverse(const NSCompilerApi::GenericTree ns, IGenericVisitor* visitor);

private:
    
    /**
     *  @brief the visitor which will visit every type.
     *
     */
    IGenericVisitor* _visitor;

    /**
     * @brief Returns the name declared for this node.
     *
     * @param decl the tree node corresponding to the declaration from which we will get the name
     * @param name the name that will be returned
     */
    static void getName(const NSCompilerApi::GenericTree decl, std::string& name);

    /**
     * @brief this will return true if the node represents something declared as constant.
     *
     * @param decl the tree node corresponding to the declaration from which we will get if it is declared constant or not.
     * @return true if decl is a constant, otherwise false
     */
    static bool isConstant(const NSCompilerApi::GenericTree decl);

    /**
     * @brief Gets the name of the type declared for a variable.
     *
     * @param decl the tree node corresponding to the declaration from which we will get the type name.
     * @param return Name the name of the returned type 
     */
    static void getTypeName(const NSCompilerApi::GenericTree decl, std::string& returnName);

    /**
     * @brief Returns true if the node has a name that we dont want to process.
     *
     * @param decl the tree node corresponding to the declaration from which we will get the name to check.
     * @return true if decl is a reserved declaration, otherwise false
     */
    static bool isReservedDeclaration(const NSCompilerApi::GenericTree decl);

    /**
     * @brief Returns the visibility of a method or attribute (public, private or protected).
     *
     * @param decl the tree node corresponding to the declaration from which we will get the visibility.
     * @return the visibility of decl
     */
    static IGenericVisitor::AccessModifier getAccess(const NSCompilerApi::GenericTree decl);

    /**
     * @brief Processes and traverses the Parameters of a function or method
     *
     * @param decl the tree node corresponding to the function or method declaration we want to process.
     */
    void processParameters(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses the attributes of a class, struct or union
     *
     * @param decl the tree node corresponding to the class, struct or union declaration we want to process.
     */
    void processAttributes(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses the methods of a class ,struct or union
     *
     * @param decl the tree node corresponding to the class, struct or union declaration we want to process.
     */
    void processMethods(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and check an enum declaration or a typedef of an enum
     *
     * @param decl the tree node corresponding to the enum declaration we want to process.
     */
    void processEnumType(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses the values of an enum
     *
     * @param decl the tree node corresponding to the enum declaration we want to process.
     */
    void processEnumValues(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses any declaration
     *
     * This is the main function that checks the type of the declaration, and processes it.
     * It's called many times by other methods.
     * @param decl the tree node corresponding to the declaration we want to process.
     */
    void processDeclaration(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes statements, not declarations
     *
     * Not yet implemented.
     * @param decl the tree node corresponding to the statement we want to process.
     */
    void processStatement(const NSCompilerApi::GenericTree decl) const;

    /**
    * @brief Processes and traverses any Variable declaration
    *
    * Checks that this isn't an enum value(those are checked in the enum part), and then
    * separates between attributes(members of a class or a struct), union members, global constants, or common
    * variables.
    * @param decl the tree node corresponding to the variable declaration we want to process.
    */
    void processVariableDeclaration(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses a Template declaration
     *
     * First, it checks the templetized class or function, and then checks the templates parameters.
     * @param decl the tree node corresponding to the template declaration we want to process.
     */
    void processTemplateDeclaration(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes and traverses a Type declaration
     *
     * Here we separate between enum type declaration, typedef declared artificial (those are generated by the
     * compiler and includes class, struct and union declaration), and common typedefs.
     * @param decl the tree node corresponding to the type declaration we want to process.
     */
    void processType(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Separates between a Record declaration(struct or class), and a Union declaration
     *
     * @param decl the tree node corresponding to the union or record we want to process.
     * @param name the name declared.
     */
    void unionOrRecord(const NSCompilerApi::GenericTree decl, const NSCompilerApi::GenericTree type, std::string& name) const;

    /**
     * @brief Processes and traverses an artificial Type declaration
     *
     * First, it takes the declaration (to see if it is a union, a struct or a class), then checks if it is a
     * template parameter; if so, it treats the declaration as a typedef, it processes the attributes and methods otherwise.
     *
     * @param decl the tree node corresponding to the union or record we want to process.
     */
    void processTypeDeclArtificial(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Separates between a struct or class declaration and visits it.
     *
     * @param decl the tree node corresponding to the record declaration we want to process.
     */
    void processRecordDeclaration(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Separates between a function or method declaration and visits it.
     *
     * @param decl the tree node corresponding to the function or method declaration we want to process.
     * @param name the name declared
     */
    void functionOrMethod(const NSCompilerApi::GenericTree decl, std::string& name) const;

    /**
     * @brief Processes and traverses a function or method
     *
     * first we separate if its a function or method, then we process its parameters and its body.
     * @param decl the tree node corresponding to the function declaration we want to process.
     */
    void processFunction(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes the body of a function taking the declarations inside of it.
     *
     * @param decl the tree node corresponding to the function declaration we want to process.
     */
    void processFunctionBody(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Takes the subblocks of a block and processes them.
     *
     * @param Blocks the tree node corresponding to the block we want to process.
     */
    void processSubblocks(const NSCompilerApi::GenericTree block) const;

    /**
     * @brief Processes the block, the declarations inside them and the subblocks.
     *
     * @param decl the tree node corresponding to the block we want to process.
     */
    void processBlock(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Processes the declarations inside a block.
     *
     * @param decl the tree node corresponding to the block we want to process.
     */
    void processBlockVariables(const NSCompilerApi::GenericTree decl) const;

    /**
     * @brief Traverses the given namespace and separates the declaration of namespaces and the other declarations inside it
     *
     * @param ns the tree node we want to process.
     */
    void traverse(const NSCompilerApi::GenericTree ns) const;

    /**
     * @brief Processes the namespace's name and traverses it.
     *
     * @param level the tree node corresponding to the namespace we want to process.
     */
    void traverseNamespaces(const NSCompilerApi::GenericTree level) const;

    /**
     * @brief Takes the declarations in a namespace and processes them.
     *
     * @param level the tree node corresponding to the namespace we want to process.
     */
    void traverseDeclarations(const NSCompilerApi::GenericTree level) const;

    /**
     * @brief Checks if the declaration is of an array and add to the typename "_array", as many times
     * as dimensions has the array.
     *
     * @param decl the tree node corresponding to the declaration we want to process.
     * @param typeName the type name it could modify.
     */
    static void checkArrayTypeName(NSCompilerApi::GenericTree decl, std::string& typeName);

    /**
     * @brief Checks if the declaration is a reference and add to the typename "_ref".
     *
     * @param decl the tree node corresponding to the declaration we want to process.
     * @param typeName the type name it could modify.
     */
    static void checkReferenceTypeName(NSCompilerApi::GenericTree decl, std::string& typeName);

    /**
     * @brief Checks if the declaration is of pointer and add to the typename "_ptr", as many times
     * as indirections the variable has.
     *
     * @param decl the tree node corresponding to the declaration we want to process.
     * @param typeName the type name it could modify.
     */
    static void checkPointerTypeName(NSCompilerApi::GenericTree decl, std::string& typeName);
    
    static const std::string RESERVED_DECLARATION; 
};

#define GENERIC_TRAVERSER_INLINE_H
#include "GenericTraverserInline.h"
#undef GENERIC_TRAVERSER_INLINE_H

} // end namespace

#endif
