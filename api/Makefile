SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/GCCPluginAPI.cpp 

INCPATH= -I./ \
         -I$(GXXPLUGINS_DIR)/include/

CXXFLAGS = -fPIC -O0 -Wall -Wextra -pedantic -ansi $(INCPATH)

libapi.so: $(PLUGIN_SOURCE_FILES)
	 $(GXX) $^ -shared $(CXXFLAGS) -o $@	

.PHONY: 
	clean

clean: 
	rm -f libapi.so
