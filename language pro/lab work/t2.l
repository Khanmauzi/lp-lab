%{
	#include <stdio.h>
	int lines=0;
	int word=0;
	int lc=0;
	int uc=0;
	int digits=0;
	int num=0;
	int spc=0;
%}

%%
[\n]	{lines++;word++;}
[ ]+   {word++;}
[a-z]	{lc++;}
[A-Z]	{uc++;}
[0-9]+	{num++;digits=digits+yyleng;}
.	{spc++;}
%%
int main(){
	yyin=fopen("f1.txt","r");
	yylex();
	printf("number of lines are %d : \n",lines);
	printf("number of word are %d : \n",word);
	printf("number of lower char are %d : \n",lc);
	printf("number of upper char %d : \n",uc);
	printf("number of num are %d : \n",num);
	printf("number of digits are %d : \n", digits);
	printf("number of special characters are %d:\n",spc);

	return 0;
}
