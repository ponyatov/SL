.PHONY: all
all: ./configure
	rm -rf build ; mkdir build ; cd build ; ../configure && make -j4
	
./configure: configure.ac Makefile.am src/Makefile.am Makefile
	autoreconf --install

.PHONY: clean
clean:
	rm -rf build configure aclocal.m4 *.in missing depcomp compile install-sh
	