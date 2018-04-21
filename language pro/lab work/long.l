/* programm to find the longest word in the given file */

%{ 
	#include <stdio.h>
	#include <string.h>
	int longest=0;
	char word[60];
%}

%%
[a-zA-Z]+	{if(yyleng>longest){
			longest=yyleng;
			strcpy(word,yytext);
			}
		}
.	|
\n	;		
%%

int main(){
	yyin=fopen("f1.txt","r");
	yylex();
	printf("longest word is %s and length is %d \n ",word,longest);
	return 0;
}