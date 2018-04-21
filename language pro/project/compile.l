%{
#include<bits/stdc++.h>
#include "compile.tab.h"
using namespace std;
%}
%%
"if" 				 {return IF;}
"while" 			 {return WHILE;}
"else"				 {return ELSE;}
"{"				 {return yytext[0];}
"}"				 {return yytext[0];}
"int "				 { return INT;}
"uint "				 { return UINT;}
"bool "				 { return BOOL;}
"true"   			 {yylval.str = (char*)malloc(yyleng);sprintf(yylval.str,"%s",yytext); return TR;}
"false"   			 {yylval.str = (char*)malloc(yyleng);sprintf(yylval.str,"%s",yytext); return FL;}
[0-9]+  			 {yylval.str = (char*)malloc(yyleng);sprintf(yylval.str,"%s",yytext); return NUM;}
[a-zA-Z][a-zA-Z0-9]* 		 {yylval.str = (char*)malloc(yyleng);sprintf(yylval.str,"%s",yytext); return ID;}
[-=+/*();]			 {return yytext[0];}
[|&~^]				 {return yytext[0];}
"+=" 				 {return PLEQ;}
"-=" 				 {return SBEQ;}
"*=" 				 {return MLEQ;}
"/=" 				 {return DVEQ;}
"||" 				 {return LOR;}
"&&" 				 {return LAND;}
"!" 				 {return LNOT;}
">=" 				 {return GREQ;}
"<=" 				 {return LSEQ;}
"<" 				 {return LSTH;}
">" 				 {return GRTH;}
"==" 				 {return EQEQ;}
"!=" 				 {return NOTEQ;} 
[\n]				 {/*cout<<"Returning EOL\n";*/}


              

[ \t] 			 	{/*cout<<"Ignoring Spaces and Newline\n";*/ }

. 			        {/*cout<<"Nothing Matched Returnig # \n";*/ return '#';}

%%

int yywrap()
{
	return 1;
}
