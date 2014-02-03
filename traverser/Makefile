ifneq (,)
    This makefile requires GNU Make.
endif

GXX=/usr/bin/g++

#get the gcc version used
GCCVERSION = $(shell gcc --version | grep ^gcc | sed 's/^.* //g' | cut -d. -f-2)

#get architecture
COMMAND= $(shell uname -a | awk -F " " '{ print $$12 }' OFS=" ")

#set plugin directory
GXXPLUGINS_DIR= /usr/lib/gcc/$(COMMAND)-linux-gnu/$(GCCVERSION)/plugin

#set source code
PLUGIN_SOURCE_FILES= src/BasePlugin.cpp src/GenericTraverser.cpp

#set headers
PLUGIN_HEADERS= traverser/*.h \
                $(GXXPLUGINS_DIR)/include/*.h

#object files
PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))

#set necessary includes
INCPATH= -I$(GXXPLUGINS_DIR)/include/ \
		 -I../compilerapi/ \
		 -I./

#set necessary library
LD_LIBRARY_PATH= -L../compilerapi -Wl,-rpath=$(shell pwd)/../compilerapi

#set compilation flags
CXXFLAGS = $(INCPATH) -Wall -Wextra -pedantic -ansi -fPIC $(LD_LIBRARY_PATH) -lapi

compile: api libtraverser.so

api: 
	$(MAKE) -C ../compilerapi

libtraverser.so: $(PLUGIN_OBJECT_FILES)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) 

.PHONY: 
	clean

clean: 
	rm -f src/*.o
	rm -f libtraverser.so
	rm -f ../compilerapi/libapi.so
