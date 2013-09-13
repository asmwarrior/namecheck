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

#include "GenericVisitor.h"
#include "GenericTree.h"
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
#include "GenericTraverserInline.h"

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

    
    void processVariableDeclaration(const GenericTree decl) const;
    void processTemplateDeclaration(const GenericTree decl) const;
    void processType(const GenericTree decl) const;
    void unionOrRecord(const GenericTree decl, const GenericTree type, std::string& name) const;
    void processTypeDeclArtificial(const GenericTree decl) const;
    void processRecordDeclaration(const GenericTree decl) const;
    void functionOrMethod(const GenericTree decl, std::string& name) const;
    void processFunction(const GenericTree decl) const;
    void processFunctionBody(const GenericTree decl) const;
    void processSubblocks(const GenericTree block) const;
    void processBlock(const GenericTree decl) const;
    void processBlockVariables(const GenericTree decl) const;
    void traverse(const GenericTree ns) const;
    void traverseNamespaces(const GenericTree level) const;
    void traverseDeclarations(const GenericTree level) const;
    static void checkArrayTypeName(GenericTree decl, std::string& typeName);
    static void checkReferenceTypeName(GenericTree decl, std::string& typeName);
    static void checkPointerTypeName(GenericTree decl, std::string& typeName);

};

} // end GPPGeneric

#endif