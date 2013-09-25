/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GenericTraverser.h
* @author      Fracisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing GenericTraverser class.
*/

#ifndef PLUGIN_MEDIATOR_H
#define PLUGIN_MEDIATOR_H

#include "Visitor/GenericVisitor.h"
#include "Traverser/GenericTree.h"
#include <string>

namespace GPPGeneric
{

/**
*  @brief A class that traverses the AST tree. 
*
*/
class GenericTraverser
{
public:
    /**
2   * @brief this sets the visitor and traverse the given namespace.
3   *
4   *
5   * @param ns this should be the global namespace to process.
6   * @param visitor the visitor to set.
7   */
    void traverse(const GenericTree ns, GenericVisitor* visitor);

private:
    /**
    *  @brief the visitor which will visit every type. 
    *
    */
    GenericVisitor* _visitor;

    /**
    *  @brief this returns the name declared for this node.
    * 
    *  @param decl the tree node corresponding to the declaration from which we will get the name
    *  @param name the name that will be returned
    */
    static void getName(const GenericTree decl, std::string& name);

    /**
    *  @brief this will return true if the node represents something declared as constant.
    * 
    *  @param decl the tree node corresponding to the declaration from which we will get if it is declared constant or not.
    */
    static bool isConstant(const GenericTree decl);

    /**
    *  @brief this gets the name of the type declared for a variable.
    * 
    *  @param decl the tree node corresponding to the declaration from which we will get the type name.
    *  @param returnName the name of the type returned
    */
    static void getTypeName(const GenericTree decl, std::string& returnName);

    /**
    *  @brief this returns true if the node has a name that we dont want to process.
    * 
    *  @param decl the tree node corresponding to the declaration from which we will get the name to check.
    */
    static bool isReservedDeclaration(const GenericTree decl);

    /**
    *  @brief this returns the visibility of a method or attribute (public, private or protected).
    * 
    *  @param decl the tree node corresponding to the declaration from which we will get the visibility.
    */
    static AccessModifier getAccess(const GenericTree decl);

    /**
    *  @brief this process and traverses the Parameters of a function or method
    * 
    *  @param decl the tree node corresponding to the function or method declaration we want to process.
    */
    void processParameters(const GenericTree decl) const;

    /**
    *  @brief this process and traverses the attributes of a class ,struct or union
    * 
    *  @param decl the tree node corresponding to the class, struct or union declaration we want to process.
    */
    void processAttributes(const GenericTree decl) const;

    /**
    *  @brief this process and traverses the methods of a class ,struct or union
    * 
    *  @param decl the tree node corresponding to the class, struct or union declaration we want to process.
    */
    void processMethods(const GenericTree decl) const;

    /**
    *  @brief this process and check an enum declaration or a typedef of an enum
    * 
    *  @param decl the tree node corresponding to the enum declaration we want to process.
    */
    void processEnumType(const GenericTree decl) const;

    /**
    *  @brief this process and traverses the values of an enum
    * 
    *  @param decl the tree node corresponding to the enum declaration we want to process.
    */
    void processEnumValues(const GenericTree decl) const;

    /**
    *  @brief this process and traverses any declaration
    * 
    *  This is the main function that check what type is the declaration, and process it.
    *  It's called many times from the other methods.
    *  @param decl the tree node corresponding to the declaration we want to process.
    */
    void processDeclaration(const GenericTree decl) const;

    /**
    *  @brief this process statements, not declarations
    * 
    *  Not yet implemented.
    *  @param decl the tree node corresponding to the statement we want to process.
    */
    void processStatement(const GenericTree decl) const;

    /**
    *  @brief this process and traverses any Variable declaration
    * 
    *  This checks that this isnt an enum value(those are checked in the enum part), and then
    *  separates between attributes(members of a class or a struct), union members, global constants, or common
    *  variables.
    *  @param decl the tree node corresponding to the variable declaration we want to process.
    */
    void processVariableDeclaration(const GenericTree decl) const;

    /**
    *  @brief this process and traverses a Template declaration
    * 
    *  First, this check the class or function templatized, and then checks the templates parameters.
    *  @param decl the tree node corresponding to the template declaration we want to process.
    */
    void processTemplateDeclaration(const GenericTree decl) const;

    /**
    *  @brief this process and traverses a Type declaration
    * 
    *  Here we separate between enum type declaration, typedef declared artificial (those are generated by the
    *  compiler and includes class, struct and union declaration), and common typedefs.
    *  @param decl the tree node corresponding to the type declaration we want to process.
    */
    void processType(const GenericTree decl) const;

    /**
    *  @brief this separates between a Record declaration(struct or class), and a Union declaration
    * 
    *  @param decl the tree node corresponding to the union or record we want to process.
    *  @param name the name declared.
    */
    void unionOrRecord(const GenericTree decl, const GenericTree type, std::string& name) const;

    /**
    *  @brief this process and traverses an artificial Type declaration
    *
    *  this first take the declaration(and see if it is a union, struct or class), then we check, if its a
    *  template parameter, the function treat the declaration as a typedef, if not we process the attributes
    *  and methods  
    *  @param decl the tree node corresponding to the union or record we want to process.

    */
    void processTypeDeclArtificial(const GenericTree decl) const;

    /**
    *  @brief this separates between a struct or class declaration and visits it.
    * 
    *  @param decl the tree node corresponding to the record declaration we want to process.
    */
    void processRecordDeclaration(const GenericTree decl) const;

    /**
    *  @brief this separates between a function or method declaration and visits it.
    * 
    *  @param decl the tree node corresponding to the function or method declaration we want to process.
    *  @param name the name declared
    */
    void functionOrMethod(const GenericTree decl, std::string& name) const;

    /**
    *  @brief this processes and traverses a function or method
    *
    *  first we separate if its a function or method, then we process its parameters and its body. 
    *  @param decl the tree node corresponding to the function declaration we want to process.
    */
    void processFunction(const GenericTree decl) const;

    /**
    *  @brief this process the body of a function taking the declarations inside of it.
    * 
    *  @param decl the tree node corresponding to the function declaration we want to process.
    */
    void processFunctionBody(const GenericTree decl) const;
    
    /**
    *  @brief this takes the subblocks of a block and process them.
    * 
    *  @param block the tree node corresponding to the block we want to process.
    */
    void processSubblocks(const GenericTree block) const;

    /**
    *  @brief this process the block, the declarations inside them and the subblocks.
    * 
    *  @param decl the tree node corresponding to the block we want to process.
    */
    void processBlock(const GenericTree decl) const;

    /**
    *  @brief this process the declarations inside a block.
    * 
    *  @param decl the tree node corresponding to the block we want to process.
    */
    void processBlockVariables(const GenericTree decl) const;

    /**
    *  @brief this traverse the given namespace and separates the declaration of namespaces and the other declarations inside it
    *  
    * 
    *  @param decl the tree node corresponding to the namespace we want to process.
    */
    void traverse(const GenericTree ns) const;

    /**
    *  @brief this process the namespace's name and traverses it.
    * 
    *  @param decl the tree node corresponding to the namespace we want to process.
    */
    void traverseNamespaces(const GenericTree level) const;

    /**
    *  @brief this takes the declarations in a namespace and process them.
    * 
    *  @param decl the tree node corresponding to the namespace we want to process.
    */
    void traverseDeclarations(const GenericTree level) const;

    /**
    *  @brief this checks if the declaration is of an array and add to the typename "_array", as many times
    *  as dimensions has the array.
    * 
    *  @param decl the tree node corresponding to the declaration we want to process.
    *  @param typeName the type name it could modify.
    */
    static void checkArrayTypeName(GenericTree decl, std::string& typeName);

    /**
    *  @brief this checks if the declaration is a reference and add to the typename "_ref".
    * 
    *  @param decl the tree node corresponding to the declaration we want to process.
    *  @param typeName the type name it could modify.
    */
    static void checkReferenceTypeName(GenericTree decl, std::string& typeName);

    /**
    *  @brief this checks if the declaration is of pointer and add to the typename "_ptr", as many times
    *  as indirections the variable has.
    * 
    *  @param decl the tree node corresponding to the declaration we want to process.
    *  @param typeName the type name it could modify.
    */
    static void checkPointerTypeName(GenericTree decl, std::string& typeName);
};

#define GENERIC_TRAVERSER_INLINE_H
#include "GenericTraverserInline.h"
#undef GENERIC_TRAVERSER_INLINE_H

} // end GPPGeneric

#endif