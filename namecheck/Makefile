ifneq (,)
    This makefile requires GNU Make.
endif

# Output messages
COMPILING_API="************ Compiling compilerapi **********************"
COMPILING_TRAVERSER="************ Compiling traverser ************************"
COMPILING_NAMECHECK="************ Compiling namecheck ************************"
COMPILATION_FINISHED="************ Compilation finished successfully **********"

GXX=/usr/bin/g++
#get the gcc version used
GCCVERSION = $(shell gcc --version | grep ^gcc | sed 's/^.* //g'  | cut -d. -f-2)

#get architecture
COMMAND= $(shell uname -a | awk -F " " '{ print $$12 }' OFS=" ")

#set plugin directory
GXXPLUGINS_DIR= /usr/lib/gcc/$(COMMAND)-linux-gnu/$(GCCVERSION)/plugin

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
		 -I../compilerapi/

LD_LIBRARY_PATH= -L. \
			     -L../traverser \
				 -Wl,-rpath=$(shell pwd)/../traverser \
			     -L../compilerapi \
				 -Wl,-rpath=$(shell pwd)/../compilerapi

LDFLAGS= -lboost_regex \
		 -ltraverser \
		 -lapi  

CXXFLAGS = $(INCPATH) -O0 -Wall -Wextra -pedantic -ansi -fPIC $(LD_LIBRARY_PATH) $(LDFLAGS) 

compile: api traverser libnamecheck.so finish

api:
	@echo $(COMPILING_API)
	$(MAKE) -C ../compilerapi

traverser:	
	@echo $(COMPILING_TRAVERSER)
	$(MAKE) -C ../traverser

libnamecheck.so: $(PLUGIN_OBJECT_FILES) 	
	@echo $(COMPILING_NAMECHECK)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) 

finish:		
	@echo $(COMPILATION_FINISHED)

.PHONY: 
	clean

clean: 
	rm -f src/*.o
	rm -f libnamecheck.so
	rm -f ../traverser/src/*.o
	rm -f ../traverser/libtraverser.so
	rm -f ../compilerapi/src/*.o
	rm -f ../compilerapi/libapi.so
	
