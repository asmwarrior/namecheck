# namecheck: Internal Documentation #

# Stakeholders #
```
- Taller Technologies Special Projects Division (spd@tallertechnologies.com)

- Daniel Gutson (daniel.gutson@tallertechnologies.com)
```

# References #
```
* Namecheck Architecture: https://docs.google.com/a/tallertechnologies.com/presentation/d/1RQecz47vOGjm9FPnOW4abD4m-YnoC7q0ykvkm-u5lQI/edit#slide=id.p

* GCC Internals (Chapter 23: “Plugins”): http://gcc.gnu.org/onlinedocs/gcc-4.5.0/gccint/Plugins.html#Plugins

* GCC Internals (Chapter 11: “GENERIC”): http://gcc.gnu.org/onlinedocs/gcc-4.5.0/gccint/GENERIC.html#GENERIC

* Parsing C++ with GCC Plugins: 

    1- Creation of the plugin infrastructure and identification of the point in the compilation sequence where we can perform our own processing.	
       http://codesynthesis.com/~boris/blog/2010/05/03/parsing-cxx-with-       gcc-plugin-part-1/==

    2- How to work with the GCC AST (abstract syntax tree) in order to 
       access the parsed C++ representation.
       http://codesynthesis.com/~boris/blog/2010/05/10/parsing-cxx-with-gcc-plugin-part-2/==

    3- How to access various parts of a class definition, such as its 
       bases, member variables, member functions, nested type 
       declarations, and others. 
       http://codesynthesis.com/~boris/blog/2010/05/17/parsing-cxx-with-gcc-plugin-part-3/

* GCC AST tree, in files of the gcc plugin library: 

    /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin/include/cp/cp-tree.def

    /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin/include/tree.def

* GCC 4.7: http://charette.no-ip.com:81/programming/2011-12-24_GCCv47/

* C++11 FAQ: http://www.stroustrup.com/C++11FAQ.html

* C++11 support in GCC: here you can find C++11 features supported in GCC 4.6: http://gcc.gnu.org/projects/cxx0x.html

* Macros: http://gcc.gnu.org/onlinedocs/gcc-3.0.1/gcc_18.html

* Regular Expressions: http://www.boost.org/doc/libs/1_54_0/libs/regex/doc/html/boost_regex/syntax/perl_syntax.html

* GNU Gettext: http://www.gnu.org/software/gettext/manual/gettext.html
```

# Compiling the plugin with Fbuild #
```
1. Download Fbuild                 : https://code.google.com/p/fudepan-build/

2. Install Fbuild                  : http://code.google.com/p/fudepan-build/wiki/README_English#Usage

3. Download namecheck using Fbuild : fbuild namecheck:checkout

4a. Compile namecheck              : fbuild namecheck
OR
4b. Test namecheck                 : fbuild namecheck:test
```

# Command to debug #
```
LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 gdb --args 
g++ -fplugin=pathOfPlugin -c file.cpp -fplugin-arg-libnamecheck-path=confiPathFile

set follow-fork-mode child *(required)*

p debug_tree(tree)   * to see the current tree (AST) *
```

# Multi-language support #
Steps:

**1-** Use the gettext function on all those chains which want to translate
```
     Example: 
               #include <libintl.h>
               ...
               const std::string message = gettext("Hello world");
               std::cout << message << std::endl;
```

**2-** Generate a template portable object (.pot file)
```
xgettext --c++ --package-name namecheck --default-domain namecheck -o namecheck.pot sources
```

**3-** Generate a specific portable object (one .po file by language)
```
msginit --no-translator --locale es -o es.po -i namecheck.pot
```

**4-** Generate a binary file (.mo file)
```
msgfmt -c -v -o es.mo es.po
```

**5-** Copy binary file
```
cd /usr/shared/locale/es/LC_MESSAGES/
sudo ln ~/Desktop/fbuild/projects/namecheck/namecheck/src/es.mo namecheck.mo
```

**6-** To update existing PO files use msgmerge invocation
```
     msgmerge [option] def.po ref.pot
```

![http://upload.wikimedia.org/wikipedia/commons/6/6b/Gettext.svg](http://upload.wikimedia.org/wikipedia/commons/6/6b/Gettext.svg)

For more information see: http://www.gnu.org/software/gettext/manual/gettext.html