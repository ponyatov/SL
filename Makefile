.PHONY: all
all: ./configure
	mkdir build ; cd build ; ./configure
	
./configure: configure.in Makefile.am src/Makefile.am
	autoconf

.PHONY: clean
clean:
	rm -rf build 
	