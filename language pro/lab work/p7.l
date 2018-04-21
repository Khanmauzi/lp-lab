%{
	#include <stdio.h>
	int cnt=0;
	FILE *fptr;
   

%}

%%
" "|"\t"  ;
"char"   |
"int"    |
"float"  |
"string" {
	fprintf(fptr,"%c",yytext);
	char ch;
	ch=input();

	while(1){
		printf("%c \n",ch);
	fprintf(fptr,"%c",ch);
		if(ch==',')
		cnt++;
		if(ch==';'){
			cnt++;
			break;
		}
		if(ch=='\n')
		break;
		ch=input();
	}
}

%%
int yywrap(){
	return 1;
}
int main(){
	fptr = fopen("output.txt","w");
	yyin=fopen("f7.txt","r");
	yylex();
	printf("number of identifier is %d \n:",cnt );
	return 0;
}