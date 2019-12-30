#----- Colors -----
BLACK	= "\033[1;30m"
RED	 	= "\033[1;31m"
GREEN	= "\033[1;32m"
YELLOW	= "\033[1;33m"
BLUE	= "\033[1;34m"
MAGENTA	= "\033[1;35m"
CYAN	= "\033[1;35m"
PURPLE	= "\033[1;36m"
WHITE	= "\033[1;37m"
EOC	 	= "\033[0;0m"
RESET	= "\x1b[0m"
#==================

.PHONY: all
all: test

.PHONY: clean
clean:
	rm -rf build/

.PHONY: fclean
	rm -rf build/
	rm -rf test

.PHONY: re
re: clean all

build/Makefile: CMakeLists.txt
	@mkdir -p build
	@(cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..)


.PHONY: test
test: build/Makefile
	@echo $(YELLOW)"\nCompiling $@ \n"$(RESET)
	@(cd build && cmake --build . -- -j)