ifneq (,)
    This makefile requires GNU Make.
endif

GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/BasePlugin.cpp src/GenericTraverser.cpp

PLUGIN_HEADERS= traverser/*.h \
                $(GXXPLUGINS_DIR)/include/*.h

PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))

INCPATH= -I$(GXXPLUGINS_DIR)/include/ \
		 -I../api/

LD_LIBRARY_PATH= -L../api -Wl,-rpath=$(shell pwd)/../api

CXXFLAGS = $(INCPATH) -O0 -Wall -Wextra -pedantic -ansi -fPIC $(LD_LIBRARY_PATH) -lapi

compile: api libtraverser.so

api: 
	$(MAKE) -C ../api

libtraverser.so: $(PLUGIN_OBJECT_FILES)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) -I./	

.PHONY: 
	clean

clean: 
	rm -f src/*.o
	rm -f libtraverser.so
	rm -f ../api/libapi.so