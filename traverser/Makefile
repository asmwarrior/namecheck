SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/BasePlugin.cpp src/GenericTraverser.cpp

INCPATH= -I./ \
		 -I$(GXXPLUGINS_DIR)/include/ \
		 -I../api/

LD_LIBRARY_PATH= -L../api

CXXFLAGS = -O0 -Wall -Wextra -pedantic -ansi $(INCPATH) -fPIC $(LD_LIBRARY_PATH) -lapi

compile: api libtraverser.so

libtraverser.so: $(PLUGIN_SOURCE_FILES)
	 $(GXX) $^ -o $@ -shared $(CXXFLAGS) 

api: 
	$(MAKE) -C ../api

.PHONY: 
	clean

clean: 
	rm -f libtraverser.so
	rm -f ../api/libapi.so