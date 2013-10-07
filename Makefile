ifneq (,)
    This makefile requires GNU Make.
endif

COMPILING_API="************ Compiling plugin **********************"
COMPILING_FINISHED="************ Compiling plugin finished *************"

compile: compileNamecheck cpLib

compileNamecheck:
	@echo $(COMPILING_PLUGIN)
	$(MAKE) -C namecheck	
	@echo $(COMPILING_FINISHED)

cpLib:
	$(shell cd namecheck; cp libnamecheck.so ..; cd ..)

.PHONY: clean

clean: 
	rm -f libnamecheck.so
	rm -f namecheck/libnamecheck.so
	rm -f namecheck/src/*.o
	rm -f traverser/libtraverser.so
	rm -f traverser/src/*.o	
	rm -f compilerapi/libapi.so
	rm -f compilerapi/src/*.o	
	clear