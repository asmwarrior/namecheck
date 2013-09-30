SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/LowerCamelCaseRule.cpp src/LowerUnderscoreRule.cpp src/Namecheck.cpp \
					 src/NamingConventionPlugin.cpp src/RegexCollection.cpp src/Regex.cpp src/ReservedNameRule.cpp \
					 src/RulesContainer.cpp src/UpperCamelCaseRule.cpp src/UpperUnderscoreRule.cpp

INCPATH= -I./ \
         -I$(GXXPLUGINS_DIR)/include/ \
         -I./mili/ \
         -I../traverser/ \
         -I../api/

LD_LIBRARY_PATH= -L../traverser/traverser.so \
 				 -L../api/api.so 

LDFLAGS=-lboost_regex 

CXXFLAGS = -fPIC -O0 -ggdb3 -Wall -Wextra -pedantic -ansi $(INCPATH) $(LD_LIBRARY_PATH) $(LDFLAGS)

compile: namecheck.so traverser api 

namecheck.so: $(PLUGIN_SOURCE_FILES) 
	$(GXX) $^ -shared -o $@ $(CXXFLAGS) 	

traverser:
	$(MAKE) -C ../traverser

api:
	$(MAKE) -C ../api

.PHONY: clean

clean: 
	rm -f namecheck.so
	rm -f ../traverser/traverser.so
	rm -f ../api/api.so