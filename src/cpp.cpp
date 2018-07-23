#include "hpp.hpp"

// very simple system start: just run interpreter
int main(int argc, char *argv[]) { init(); return yyparse(); }

/// syntax error template
#define YYERR "\n\n" << yylineno << ": " << msg << " [" << yytext << "]\n\n"
/// syntax error callback
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }

Sym::Sym(string T, string V)    { type = T; value = V; }
Sym::Sym(string V):Sym("sym",V) {}

Sym* Sym::lookup(string name) {
	auto found = attr.find(name);
	if (found == attr.end())	return NULL;
	else						return found->second;
}

void Sym::push(Sym*o)	{ nest.push_back(o); }
Sym* Sym::pop()			{ Sym*o = nest.back(); nest.pop_back();	return o; }
void Sym::flush()		{ nest.clear(); }

string Sym::str()		{ return value; }

string Sym::dump(int depth, string prefix) {
	string S = pad(depth) + head(prefix);
	for (auto i = attr.begin(), e = attr.end(); i != e; i++)
		S += i->second->dump(depth + 1, prefix = i->first + " = ");
	return S;
}

string Sym::head(string prefix) {
	ostringstream os;
	os << prefix << '<' << type << ':' << str() << "> @" << this;
	return os.str();
}

string Sym::pad(int N) {
	string S; S += '\n';
	for (int i = 0; i < N; i++) S += '\t';
	return S;
}

void Sym::exec() { Stack->push(this); }

Env::Env(string V):Sym("env",V) {}

Env *env = new Env("global");

void DUMP() {
	cout << env->dump();
	cout << Stack->dump();
}

Fn::Fn(string V, void(*F)()):Sym("fn",V) { fn = F; }

void Fn::exec() { fn(); }

Sym *Stack = new Sym("stack","DATA");

bool FIND(Sym* name) {
	Sym* found = env->lookup(name->str());
	if (found) {
		Stack->push(found); return true;
	} else {
		Stack->push(name); return false;
	}
}

void EXECUTE() { Stack->pop()->exec(); }

void DROPALL() { Stack->flush(); }

void init() {
	env->attr["?"] = new Fn("dump",DUMP);
	env->attr["."] = new Fn("dropall",DROPALL);
}
