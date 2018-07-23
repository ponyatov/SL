.PHONY: all
all: ./configure
	rm -rf build ; mkdir build ; cd build ; ../configure
	
./configure: configure.ac Makefile.am src/Makefile.am
	autoreconf --install
#	autoconf

.PHONY: clean
clean:
	rm -rf build 
	