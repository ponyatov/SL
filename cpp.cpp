#include "hpp.hpp"

int main(int argc, char *argv[]) { env_init(); return yyparse(); }

#define YYERR "\n\n" << yylineno << ':' << msg << " [" << yytext << "]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }

Sym::Sym(string T, string V) { type = T; value = V; }
Sym::Sym(string V):Sym("sym",V) {}

string Sym::dump(int depth) { return "<"+type+":"+value+">"; }

Sym* Sym::eval() { return this; }

Env::Env(string V):Sym("env",V) {}

Env *env = new Env("global");

void dump(void) { cout << env->dump(); }

void env_init() {
	env->attr["?"] = new Fn("dump",dump);
}

