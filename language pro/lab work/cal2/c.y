%{
	#include <stdio.h>
	#include <string.h>
	float value=0;

%}

%union { int intval; double doubleval; }
%token <doubleval> NUM
%type <doubleval> startterm
%type <doubleval> exp
%left '+' '-'
%right '*' '/'

%%
startterm :exp {value=$$;}
	exp: exp'+'exp		{$$=$1+$3;}
	|exp'-'exp		{$$=$1-$3;}
	|exp'*'exp		{$$=$1*$3;}
	|exp'/'exp		{
		if($3==0){
		yyerror("error");
		}
		else {
		$$=$1/$3;
		}
	}
	|'('exp')'	{$$=$2;}
	|NUM 	{$$=$1;}
	;

%%
int main(){
	printf("enter the expression :\n");
	if(yyparse()==0){
	printf("success \n");
	printf("%f : \n",value);
	}
}
int yywrap(){
	return 1;
}
yyerror(){
	printf("error");
}