/* program to distinquish between keyword and identifier */

%{
	#include <stdio.h>
	enum {INTEGER,FLOAT,IDENTIFIER,OPERATOR,COMMENT};
%}
digit [0-9]
word [a-zA-Z]

%%
" "|"\t" ;
{digit}+	{return INTEGER;}
{digit}+\.{digit}+ {return FLOAT;}
"+" |
"-" |
"*" |
"/"  {return OPERATOR;}
{word}({word}|{digit})* {return IDENTIFIER;}
"/*" {return COMMENT;}
%%

int main(){
	int result;
	int running=1;
	while(running){
		result=yylex();
		switch(result){
			case INTEGER: printf("integer ");break;
			case FLOAT: printf("FLOAT ");break;
			case IDENTIFIER: printf("identifier ");break;
			case OPERATOR: printf("OPERATOR ");break;
			case COMMENT: printf("COMMENT ");break;
		}
	}
	return 0;
}