SHELL=/bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

PLUGIN_SOURCE_FILES= src/GCCPluginAPI.cpp 

PLUGIN_HEADERS= api/*.h \
                $(GXXPLUGINS_DIR)/include/*.h

PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))

INCPATH= -I$(GXXPLUGINS_DIR)/include/

CXXFLAGS = $(INCPATH) -fPIC -O0 -Wall -Wextra -pedantic -ansi 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) -I./

libapi.so: $(PLUGIN_OBJECT_FILES)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 	

.PHONY: 
	clean

clean: 
	rm -f src/*.o
	rm -f libapi.so
