SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/BasePlugin.cpp src/GenericTraverser.cpp

INCPATH= -I./ \
		 -I$(GXXPLUGINS_DIR)/include/ \
		 -I../api/

LD_LIBRARY_PATH= -L../api/api.so 

CXXFLAGS = -fPIC -O0 -ggdb3 -Wall -Wextra -pedantic -ansi $(INCPATH) $(LD_LIBRARY_PATH)

traverser.so: $(PLUGIN_SOURCE_FILES) $(api)
	 $(GXX) $^ -shared -o $@ $(CXXFLAGS)

api: 
	$(MAKE) -C ../api

.PHONY: 
	clean

clean: 
	rm -f traverser.so
	$(MAKE) -C ../api/make clean
