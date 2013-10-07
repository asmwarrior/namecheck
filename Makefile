ifneq (,)
    This makefile requires GNU Make.
endif

COMPILING_API="************ Compiling plugin **********************"
COMPILING_FINISHED="************ Compiling plugin finished *************"

compileNamecheck:
	@echo $(COMPILING_PLUGIN)
	$(MAKE) -C namecheck
	$(shell cd namecheck; cp libnamecheck.so ..; cd ..)
	@echo $(COMPILING_FINISHED)

.PHONY: clean

clean: 
	rm -f namecheck/libnamecheck.so
	rm -f namecheck/src/*.o
	rm -f traverser/libtraverser.so
	rm -f traverser/src/*.o	
	rm -f compilerapi/libapi.so
	rm -f compilerapi/src/*.o	
	clear