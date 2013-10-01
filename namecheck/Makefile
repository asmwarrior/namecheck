ifneq (,)
    This makefile requires GNU Make.
endif

GXX=/usr/bin/g++
GXXPLUGINS_DIR= /usr/lib/gcc/x86_64-linux-gnu/4.6/plugin

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
		 -I../api/

LD_LIBRARY_PATH= -L. \
			     -L../traverser \
			     -L../api

LDFLAGS= -lboost_regex \
		 -ltraverser \
		 -lapi  

CXXFLAGS = $(INCPATH) -O0 -Wall -Wextra -pedantic -ansi -fPIC $(LD_LIBRARY_PATH) $(LDFLAGS)

compile: api traverser libnamecheck.so 

api:
	$(MAKE) -C ../api

traverser:
	$(MAKE) -C ../traverser

libnamecheck.so: $(PLUGIN_OBJECT_FILES) ../api/src/*.o ../traverser/src/*.o
	$(GXX) -shared $^ -o $@ $(CXXFLAGS) 

%.o: %.cpp $(PLUGIN_HEADERS)
	$(GXX) -c -o $@ $< $(CXXFLAGS) 

.PHONY: clean

clean: 
	rm -f src/*.o
	rm -f libnamecheck.so
	rm -f ../traverser/src/*.o
	rm -f ../traverser/libtraverser.so
	rm -f ../api/src/*.o
	rm -f ../api/libapi.so

# usr/bin/g++ -shared src/LowerCamelCaseRule.o src/LowerUnderscoreRule.o src/Namecheck.o
# src/NamingConventionPlugin.o src/RegexCollection.o src/Regex.o src/ReservedNameRule.o 
# src/RulesContainer.o src/UpperCamelCaseRule.o src/UpperUnderscoreRule.o -o libnamecheck.so
# -I./ -I/usr/lib/gcc/x86_64-linux-gnu/4.6/plugin/include/ -I./mili/ -I../traverser/ 
# -I../api/ -O0 -Wall -Wextra -pedantic -ansi -fPIC 
# -L. -L../traverser -L../api 
# -lboost_regex -ltraverser -lapi 

# g++ -o build/namecheck/namecheck/libnamecheck.so -shared -Wl,-rpath=/home/fgriberi/Desktop/fbuild/install/libs 
# build/namecheck/namecheck/src/LowerCamelCaseRule.os build/namecheck/namecheck/src/LowerUnderscoreRule.os
# build/namecheck/namecheck/src/Namecheck.os build/namecheck/namecheck/src/NamingConventionPlugin.os 
# build/namecheck/namecheck/src/Regex.os build/namecheck/namecheck/src/RegexCollection.os 
# build/namecheck/namecheck/src/ReservedNameRule.os build/namecheck/namecheck/src/RulesContainer.os 
# build/namecheck/namecheck/src/UpperCamelCaseRule.os build/namecheck/namecheck/src/UpperUnderscoreRule.os 
# -L/home/fgriberi/Desktop/fbuild/install/libs -L. -Lbuild/namecheck/traverser 
# -Lbuild/namecheck/api -lboost_regex -ltraverser -lapi
