%{
	#include <string.h>
	#include <math.h>
	#include "y.tab.h"
%}
digit [0-9]
%%
{digit}+(\.{digit}+)?	{yylval.doubleval=atof(yytext);printf("%f fgfb\n",yylval.doubleval);return NUM;}
[-]		{return '-';}
[*]		{return '*';}
[+]		{return '+';}
[/]		{return '/';}
.	{return yytext;}
\n	{return 0;}

%%