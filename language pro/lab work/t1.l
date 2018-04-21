%{
	#include <stdio.h>
%}


%%
is |
are |
was |
were 	{printf("%s is a verb \n",yytext);}
[a-z A-Z]+ {printf("%s is not a verb \n",yytext);}
.	{printf("%s is a meta character. \n",yytext);}

%%

int main(){
	yylex();
	return 0;
}