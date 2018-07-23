bin_PROGRAMS = ScriptLayer
BUILT_SOURCES = Parser.cpp Lexer.cpp
ScriptLayer_SOURCES = ObjectEngine.cpp ${BUILT_SOURCES}

Parser.hpp: Parser.cpp 
Parser.cpp: Parser.yacc
	${BISON} -o $@ $<
Lexer.cpp: Lexer.lex
	${FLEX} -o $@ $<
