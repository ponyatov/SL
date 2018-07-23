#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

struct Sym {										// base symbol class
	string type;									// type tag
	string value;									// single value
	Sym(string,string);								// <T:V> constructor
	Sym(string);									// sym:V constructor

	map<string,Sym*> attr;							// named attr{}ibutes
	Sym* lookup(string name);

	vector<Sym*> nest;								// === nest[]ed elements
	void push(Sym*);								// push object
	Sym* pop();										// pop top object
	void flush();									// clean

	virtual string dump(int depth=0, string prefix=""); // dump in tree form
	virtual string head(string prefix="");
	string pad(int N);

	virtual string str();							// string representation
	virtual void exec();							// execute
};

struct Env:Sym { Env(string V); };					// environment

extern Env* env;									// global env
extern void init();

struct Fn:Sym {										// VM function
	Fn(string V, void(*F)() );
	void(*fn)();									// pointer to VM fn
	void exec();
};

struct Stack:Sym { Stack(string); };				// stack container

struct Map:Sym { Map(string); };					// associative container

													// === parser interface
extern int yylex();									// lexer get next token
extern int yylineno;								// current line number
extern char* yytext;								// current lexeme value
#define TOC(C,T) { yylval.o = new C(yytext); return T; } /* token macro */
extern int yyparse();								// parser
extern void yyerror(string);						// syntax error callback
#include "Parser.hpp"								// token definitions

/// Object Virtual Machine

extern Sym *Stack;									// shared data stack

/// commands

extern bool FIND(Sym *name);
extern void EXECUTE();

#endif // _H_HPP

