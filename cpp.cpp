#include "hpp.hpp"

int main(int argc, char *argv[]) { return yyparse(); }

#define YYERR "\n\n" << yylineno << ':' << msg << " [" << yytext << "]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }

Sym::Sym(string T, string V) { type = T; value = V; }
Sym::Sym(string V):Sym("sym",V) {}

string Sym::dump(int depth) { return "<"+type+":"+value+">"; }

