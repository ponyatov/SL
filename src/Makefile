.PHONY: all
all: log.log

log.log: src.src ./exe.exe
	./exe.exe < $< > $@ && tail $(TAIL) $@

C = cpp.cpp ypp.tab.cpp lex.yy.cpp
H = hpp.hpp ypp.tab.hpp

CXXFLAGS += -DWX $(shell wx-config --cxxflags)
L += $(shell wx-config --libs core)

CXXFLAGS += -std=gnu++11

./exe.exe: $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C) $(L)

ypp.tab.hpp: ypp.tab.cpp
ypp.tab.cpp: ypp.ypp
	bison -o $@ $<

lex.yy.cpp: lpp.lpp
	flex -o $@ $<
