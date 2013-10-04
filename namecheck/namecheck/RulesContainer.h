/**
 * @file     RulesContainer.h
 * @brief    Provides the interface to check naming convention.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing RulesContainer class.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 17, 2013
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

#ifndef RULES_CONTAINER_H
#define RULES_CONTAINER_H


#include <vector>
#include <string>
#include "Rule.h"
#include "Exceptions.h"

namespace NSNamingChecker
{

/**
 * @brief Represents a checker of Naming conventions.
 *
 */
class RulesContainer
{
public:

    /**
     * @brief Represents the statements to check
     */
    enum DeclarationToCheck
    {
        ClassDeclaration,
        VariableDeclaration,
        EnumTypeDeclaration,
        EnumValueDeclaration,
        FunctionDeclaration,
        ParameterDeclaration,
        TypeDeclaration,
        StructDeclaration,
        UnionDeclaration,
        UnionValueDeclaration,
        PublicMethodDeclaration,
        PrivateMethodDeclaration,
        ProtectedMethodDeclaration,
        PublicAttributeDeclaration,
        PrivateAttributeDeclaration,
        ProtectedAttributeDeclaration,
        NamespaceDeclaration,
        GlobalConstDeclaration,
        TemplateTypeParameterDeclaration,
        CheckCount
    };

    /**
     * @brief Match between string and declaration to check
     */
    typedef std::map<std::string, DeclarationToCheck> DeclarationMap;

    /**
     * @brief Represents a configuration file
     *
     */
    typedef std::string FileName;
    typedef std::vector<std::string> StringVector;

    /**
     * @brief Constructor of class
     *
     */
    RulesContainer();

    /**
     * @brief Destructor of class
     *
     */
    ~RulesContainer();

    /**
     * @brief This checks a declarationName with all the rules corresponding to statement
     *
     * @param decl statement to check
     * @param declarationName name to check
     * @param result to fill with the result
     */
    void check(const DeclarationToCheck& decl, const IRule::DeclName& declarationName, IRule::Result& result) const;

    /**
     * @brief This initializes the vector of rules corresponding to each declaration types.
     *
     * @param fileName configuration name file
     */
    void load(const FileName& fileName);

private:

    /**
     * @brief Represents rule types
     */
    enum RuleType
    {
        SpecificRegex,
        UpCamelCaseRule,
        LowCamelCaseRule,
        UpUnderscoreRule,
        LowUnderscoreRule,
        ReservNameRule
    };

    /**
     * @brief Create a specific rule
     *
     * @param rule corresponds a specific rule
     * @return specific rule
     */
    static IRule* createNewRule(const RuleType& rule, const StringVector& fileLine);

    /**
     * @brief This initializes process the vector corresponding to a line in the config file.
     *
     * @param fileLine the vector representing the line of the file to process
     */
    void process(const StringVector& fileLine);

    /**
     * @brief Check line data
     *
     * @param line input line from file
     */
    void checkLine(const StringVector& line);

    DeclarationMap _declarationMap;
    typedef std::list<IRule*> Rules;
    std::vector<Rules> _rules;

    /**
     * @brief To avoid magic numbers
     */
    static const size_t REGEX_SIZE = 4;
    static const size_t DEFAULT_SIZE = 2;
    static const size_t DECLARATION_NAME = 0;
    static const size_t RULE_TYPE = 1;
    static const size_t SPECIFIC_REGEX = 2;
    static const size_t ERROR_MESSAGE = 3;
    static const std::string REGEX;
};

} // end namespace

#endif
