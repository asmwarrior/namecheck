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

LD_LIBRARY_PATH= -L. \
			     -L../traverser \
			     -L../api

LDFLAGS=-lboost_regex 

CXXFLAGS = -O0 -Wall -Wextra -pedantic -ansi $(INCPATH) -fPIC $(LD_LIBRARY_PATH) $(LDFLAGS) -ltraverser -lapi 

compile: api traverser libnamecheck.so 

libnamecheck.so: $(PLUGIN_SOURCE_FILES) 
	$(GXX) $^ -o $@ -shared $(CXXFLAGS) 	

traverser:
	$(MAKE) -C ../traverser

api:
	$(MAKE) -C ../api

.PHONY: clean

clean: 
	rm -f libnamecheck.so
	rm -f ../traverser/libtraverser.so
	rm -f ../api/libapi.so
