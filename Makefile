.PHONY: all
all: ./configure
#	rm -rf build ; mkdir build ; cd build ; ../configure
	autoreconf --install
	
./configure: configure.ac Makefile.am src/Makefile.am
	autoconf

.PHONY: clean
clean:
	rm -rf build 
	