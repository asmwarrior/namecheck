ifneq (,)
    This makefile requires GNU Make.
endif

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

#set source code
PLUGIN_SOURCE_FILES= src/GCCPluginAPI.cpp 

#set headers
PLUGIN_HEADERS= compilerapi/*.h \
                $(GXXPLUGINS_DIR)/include/*.h

#object files
PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))

#set necessary includes
INCPATH= -I$(GXXPLUGINS_DIR)/include/ \
		 -I./ 

#set compilation flags
CXXFLAGS = $(INCPATH) -fPIC -O0 -Wall -Wextra -pedantic -ansi 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) 

libapi.so: $(PLUGIN_OBJECT_FILES)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 	

.PHONY: 
	clean

clean: 
	rm -f src/*.o
	rm -f libapi.so