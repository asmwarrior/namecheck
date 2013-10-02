ifneq (,)
    This makefile requires GNU Make.
endif

# Output messages
COMPILING_API="************ Compiling api ******************************"
COMPILING_TRAVERSER="************ Compiling traverser ************************"
COMPILING_NAMECHECK="************ Compiling namecheck ************************"
COMPILATION_FINISHED="************ Compilation finished successfully **********"

# Compiling
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/LowerCamelCaseRule.cpp src/LowerUnderscoreRule.cpp src/Namecheck.cpp \
					 src/NamingConventionPlugin.cpp src/RegexCollection.cpp src/Regex.cpp src/ReservedNameRule.cpp \
					 src/RulesContainer.cpp src/UpperCamelCaseRule.cpp src/UpperUnderscoreRule.cpp

PLUGIN_HEADERS= traverser/*.h \
                $(GXXPLUGINS_DIR)/include/*.h

PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))

INCPATH= -I./ \
		 -I$(GXXPLUGINS_DIR)/include/ \
         -I./mili/ \
		 -I../traverser/ \
		 -I../api/

LD_LIBRARY_PATH= -L. \
			     -L../traverser \
				 -Wl,-rpath=$(shell pwd)/../traverser \
			     -L../api \
				 -Wl,-rpath=$(shell pwd)/../api

LDFLAGS= -lboost_regex \
		 -ltraverser \
		 -lapi  

CXXFLAGS = $(INCPATH) -O0 -Wall -Wextra -pedantic -ansi -fPIC $(LD_LIBRARY_PATH) $(LDFLAGS) 

compile: api traverser libnamecheck.so finish

api:
	@echo $(COMPILING_API)
	$(MAKE) -C ../api

traverser:
	clear
	@echo $(COMPILING_API)
	@echo $(COMPILING_TRAVERSER)
	$(MAKE) -C ../traverser

libnamecheck.so: $(PLUGIN_OBJECT_FILES) 
	clear
	@echo $(COMPILING_API)
	@echo $(COMPILING_TRAVERSER)
	@echo $(COMPILING_NAMECHECK)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) 

finish:
	clear
	@echo $(COMPILING_API)
	@echo $(COMPILING_TRAVERSER)
	@echo $(COMPILING_NAMECHECK)
	@echo $(COMPILATION_FINISHED)

.PHONY: clean

clean: 
	rm -f src/*.o
	rm -f libnamecheck.so
	rm -f ../traverser/src/*.o
	rm -f ../traverser/libtraverser.so
	rm -f ../api/src/*.o
	rm -f ../api/libapi.so
	clear