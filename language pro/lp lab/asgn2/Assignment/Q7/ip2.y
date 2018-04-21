%{
#define YYSTYPE double

#include<stdio.h>
float value;

%}
%token NUM
%left '+' '-'
%left '*' '/'
%right NEGATIVE
%%
S:  E {value = $$;}
    ;
E:  E '+' E { $$ = $1 + $3;}
    |   E '*' E {$$ = $1 * $3;}
    |   E '-' E {$$ = $1 - $3;}
    |   E '/' E {$$ = $1 / $3;}
    |   '(' E ')' {$$ = $2 ;}
    |   '-' E %prec NEGATIVE {$$ = -$2;}
    |   NUM 
    ;
%%
#include "lex.yy.c"

int main(){
    yyparse();
    printf("val %f", value);
}
