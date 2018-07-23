.PHONY: all
all: ./configure
	./configure
	
./configure: configure.in Makefile.am src/Makefile.am
	autoconf
