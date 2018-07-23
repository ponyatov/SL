bin_PROGRAMS = ScriptLayer
BUILT_SOURCES = ypp.tab.cpp lex.yy.cpp
ScriptLayer_SOURCES = cpp.cpp ${BUILT_SOURCES} wx.cpp

ypp.tab.hpp: ypp.tab.cpp 
ypp.tab.cpp: ypp.ypp
	${BISON} -o $@ $<
lex.yy.cpp: lpp.lpp
	${FLEX} -o $@ $<
