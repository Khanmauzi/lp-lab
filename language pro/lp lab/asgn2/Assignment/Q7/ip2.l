%{
	#include "y.tab.h"
	#include <stdlib.h>
	void yyerror(char *);
%}
%%
[0-9]+(\.[0-9]+)?  {yylval=atof(yytext); 
					return NUM;}
\n      return 0;
.       return *yytext;
%%

int yywrap(void){
	return 1;
}