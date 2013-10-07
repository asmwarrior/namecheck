ifneq (,)
    This makefile requires GNU Make.
endif

# Output messages
COMPILING_API="************ Compiling compilerapi **********************"
COMPILING_TRAVERSER="************ Compiling traverser ************************"
COMPILING_NAMECHECK="************ Compiling namecheck ************************"
COMPILATION_FINISHED="************ Compilation finished successfully **********"

#Necessary boost package
BOOST = if ! dpkg -l | grep libboost-regex-dev -c >>/dev/null; then sudo apt-get install libboost-regex-dev; fi

#Necessary plugin package
PLUGINGCC = if ! dpkg -l | grep gcc-4.6-plugin-dev -c >>/dev/null; then sudo apt-get install gcc-4.6-plugin-dev; fi 

GXX=/usr/bin/g++
#get the gcc version used
GCCVERSION = $(shell gcc --version | grep ^gcc | sed 's/^.* //g')

#get architecture
COMMAND= $(shell find /usr/lib/gcc/ -iname plugin.h | awk -F "/" '{ print $$5 }' OFS="/" | awk '!_[$$1]++')

#set plugin directory
ifeq "$(GCCVERSION)" "4.6.3"
    GXXPLUGINS_DIR= /usr/lib/gcc/$(COMMAND)/4.6/plugin
else
    GXXPLUGINS_DIR= /usr/lib/gcc/$(COMMAND)/4.7/plugin
endif

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

compile: packages api traverser libnamecheck.so finish

packages: 		
	$(BOOST); $(PLUGINGCC)

api:
	@echo $(COMPILING_API)
	$(MAKE) -C ../compilerapi

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
	rm -f ../compilerapi/src/*.o
	rm -f ../compilerapi/libapi.so
	clear