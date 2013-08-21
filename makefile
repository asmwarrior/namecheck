SHELL = /bin/sh
GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6.3/plugin

PLUGIN_SOURCE_FILES= src/namecheck.cpp src/GenericTraverser.cpp src/NamingConventionPlugin.cpp \
                     src/BasePlugin.cpp src/GCCPluginAPI.cpp

PLUGIN_HEADERS= namecheck/*.h \
		$(GXXPLUGINS_DIR)/include/*.h

PLUGIN_OBJECT_FILES= $(patsubst %.cpp,%.o,$(PLUGIN_SOURCE_FILES))
CXXFLAGS = -I$(GXXPLUGINS_DIR)/include -fPIC -O0 -ggdb3

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) -I./namecheck

namecheck.so: $(PLUGIN_OBJECT_FILES)
	$(GXX) -shared $^ -o $@ $(CXXFLAGS)

.PHONY: clean

clean:
	@rm -f src/*.o *.so
