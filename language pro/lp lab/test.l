digit     [0-9]
letter    [A-Za-z]
%{s 
    int count;
%}
%%
    /* match identifier */
{letter}({letter}|{digit})*    count++;
%%
int main(void) {
	yyin=fopen("abc.txt","r");
    yylex();
    printf("number of identifiers = %d\n", count);
    return 0;
}