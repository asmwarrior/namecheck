SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/BasePlugin.cpp src/GCCPluginAPI.cpp \
					 src/GenericTraverser.cpp

INCPATH= -I./ \
         -I$(GXXPLUGINS_DIR)/include/

CXXFLAGS = -fPIC -O0 -ggdb3 -Wall -Wextra -pedantic -ansi $(INCPATH)

traverser.so: $(PLUGIN_SOURCE_FILES)
	 $(GXX) $^ -shared -o $@ $(CXXFLAGS)

.PHONY: 
	clean

clean: 
	rm -f traverser.so