#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

struct Sym {											// 
	string type;
	string value;
	Sym(string,string);									// <T:V> constructor
	Sym(string);										// sym:V constructor
	map<string,Sym*> attr;								// named attr{}ibutes
	vector<Sym*> nest;									// nest[]ed elements
	virtual string dump(int depth=0);
	virtual Sym* eval();
};

struct Env:Sym { Env(string V); };						// environment

extern Env* env;										// global env
extern void env_init();

struct Fn:Sym {											// VM function
	Fn(string V, void(*F)(void) );
	void(*fn)(void); };


extern int yylex();										// lexer get next token
extern int yylineno;									// current line number
extern char* yytext;									// current lexeme value
#define TOC(C,T) { yylval.o = new C(yytext); return T; }/* token macro */
extern int yyparse();									// parser
extern void yyerror(string);							// syntax error callback
#include "ypp.tab.hpp"									// token definitions

#endif // _H_HPP

