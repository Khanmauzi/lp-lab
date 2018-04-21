%{
	
	#include <stdio.h>
	float value;
%}

%token NUM

%left '+' '-'
%right '*' '/'

%%
start :exp {value=$$;}
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