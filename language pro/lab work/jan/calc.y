%{

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void yyerror(char *);
int yylex(void);

char ops[4];

char getop(int);

int operation(int a, int b, int op)
{
	char ch = ops[op];
	
	if(ch=='+')
		return a+b;
	
	if(ch=='-')
		return a-b;
	
	if(ch=='*')
		return a*b;
	
	if(ch=='/')
		return a/b;
	
	return -999;
}

%}

%token	INTEGER 
%left  OP4
%left  OP3 
%left  OP2
%left  OP1

%%
	/*Program is a sequence of expressions*/
program:
		program expr '\n'		{	printf("%d\n", $2); }
		|
		;
	/*Expression productions in increasing order of priority*/
expr:   expr OP4 expr			{ $$ = operation($1, $3, 3); }
		| expr OP3 expr			{ $$ = operation($1, $3, 2); }
		| expr OP2 expr			{ $$ = operation($1, $3, 1); }
		| expr OP1 expr			{ $$ = operation($1, $3, 0); }
		| INTEGER					{ $$ = $1; }
		;
%%

void yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
}

char getop(int opi)
{
	return ops[opi];
}

int main(void)
{
	printf("\nEnter the 4 operators in the order of their precedence (e.g. -*/+ ):\n");
	
	int i;
	
	
	scanf("%c%c%c%c", &ops[0], &ops[1], &ops[2], &ops[3]);
	
	char nlch;
	
	scanf("%c", &nlch);
	
	yyparse();
	
	return 0;
}
