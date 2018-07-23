%{
#include "ScriptLayer.hpp"
%}
										/* avoid yywrap() function */
%option noyywrap
										/* automatically count line number */
%option yylineno

%%
\#[^\n]*			{}						// line comment

[a-zA-Z0-9_\?\.]+	TOC(Sym,SYM)			// generic symbol

[ \t\r\n]+			{}						// drop spaces
.					{ yyerror("lexer"); }	// syntax error on undetected char