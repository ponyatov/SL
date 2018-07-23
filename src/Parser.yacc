%{
#include "ScriptLayer.hpp"
%}

%defines %union { Sym* o; }            /* we work only with Symbolic objects */

                          /* but can process some literal types individually */
%token <o> SYM					

%%											  
REPL :
	 | REPL SYM { if (FIND($2)) EXECUTE();	  /* it's a smell of fried FORTH */
	 			  else yyerror(Stack->pop()->value); }
%%
