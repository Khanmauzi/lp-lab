%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void yyerror(char *);
int yywrap(void);
char getop(int);
#include "y.tab.h"

%}

%%
	/*Match numbers*/
[0-9]+		{
					yylval = atoi(yytext);
					return INTEGER;
			}

	/*Match operators*/
[-+*/]		{
				char ch = *yytext;
				
				yylval = *yytext;
				
				/*printf("Checking with the following operators\n");*/
				
				/*int opi;*/
				/*for(opi=0;opi<4;opi++)*/
				/*{*/
					/*printf("%d", opi);*/
					/*printf("%c\n", getop(opi));*/
				/*}*/
				
				
				
				if(ch==getop(0))
					return OP1;
				
				if(ch==getop(1))
					return OP2;
				
				if(ch==getop(2))
					return OP3;
				
				if(ch==getop(3))
					return OP4;
			}

\n			return *yytext;

	/*Match and ignore whitespace*/
[ \t]			;

	/*Match other(invalid) character and display error message*/
.				printf("\nInvalid character :%s\n", yytext);

%%

int yywrap(void)
{
	return 1;
}
