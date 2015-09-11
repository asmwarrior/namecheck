# Namecheck: USER DOCUMENTATION #

# Description #
This plugin is a shared library (.so file). It is compiled using gcc 4.6 or gcc 4.7.

# Example Commands #
## Command to use the plugin for one file ##
```
g++ -fplugin=fudepan-build/install/libs/libnamecheck.so(path to the Plugin) -c file.cpp -fplugin-arg-libnamecheck-path=../../configurationFile.csv(configuration path file)
```

# Adding new rules #
The Configuration File: all rules are defined in a configuration file in Comma Separated Value (csv) format.
**Configuration file line format:**
```
  declaration type,rule type,regex,error message
```

**declaration type** must be one of the following:

```
ClassDeclaration 

VariableDeclaration 

EnumTypeDeclaration 

EnumValueDeclaration 

FunctionDeclaration 

ParameterDeclaration 

TypeDeclaration 

StructDeclaration 

UnionDeclaration 

UnionValueDeclaration 

MethodDeclaration 

AttributeDeclaration

NamespaceDeclaration 

GlobalConstDeclaration 

TemplateTypeParameterDeclaration
```

**“rule type”** is a number that specifies
which validation is to be performed.

It must be one of the following:

```
0- regex (new regex)

1- UpperCamelCase

2- lowerCamelCase

3- UPPER_UNDERSCORE_SCORED

4- lower_underscore_scored

5- ReservedNames
```

The options 1, 2, 3, 4 and 5 are predefined rules in the plugin. If you use rule type regex (option 0) you must define both the arguments and the error message.

There must not be any blank spaces before or after the comma.
The regexes must be written using Perl Regular Expression Syntax (http://www.boost.org/doc/libs/1_54_0/libs/regex/doc/html/boost_regex/syntax/perl_syntax.html)

# Example configuration file #
```
ClassDeclaration,0, ^\u\u.`*`?, should begin with double uppercase   
VariableDeclaration,2
EnumTypeDeclaration,1
EnumValueDeclaration,1
FunctionDeclaration,2
ParameterDeclaration,2
TypeDeclaration,1
StructDeclaration,1
UnionDeclaration,1
UnionValueDeclaration,1
MethodDeclaration,2
AttributeDeclaration,4
NamespaceDeclaration, 0,^N\u.`*`?,  should begin with N. 
GlobalConstDeclaration,3
TemplateTypeParameterDeclaration,2
```

# Known Issues #
- Forward declared classes that are not defined later in the code are parsed and analyzed as Structs.

- The plugin does not differentiate between interfaces' definitions and concrete classes' definitions.