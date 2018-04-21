%{
	#include<bits/stdc++.h>
	#include "y.tab.h"
	using namespace std;
	
	void yyerror(char *);
	
	char *getChars(char *str)
	{
		char *ans = new char[strlen(str)+1];
		strcpy(ans, str);
		
		return ans;
	}
%}

%%

[0-9]+							{ yylval.lstr = getChars(yytext); return NUM; }

"int"							{ yylval.lstr = getChars(yytext); return DATA_TYPE; }
"uint"							{ yylval.lstr = getChars(yytext); return DATA_TYPE; }
"bool"							{ yylval.lstr = getChars(yytext); return DATA_TYPE; }
"if"							{ yylval.lstr = getChars(yytext); return IF_KEY; }
"else"							{ yylval.lstr = getChars(yytext); return ELSE_KEY; }
"switch"						{ yylval.lstr = getChars(yytext); return SWITCH_KEY; }
"case"							{ yylval.lstr = getChars(yytext); return CASE_KEY; }
"default"						{ yylval.lstr = getChars(yytext); return DEFAULT_KEY; }
"while"							{ yylval.lstr = getChars(yytext); return WHILE_KEY; }
"break"							{ yylval.lstr = getChars(yytext); return BREAK_KEY; }

[a-zA-z][a-zA-z0-9]*			{ yylval.lstr = getChars(yytext); cout<<"\nReturning ID\n"; return ID; }

"+="							{ return ADDEQ; }
"-="							{ return SUBEQ; }
"*="							{ return MULEQ; }
"/="							{ return DIVEQ; }

"=="							{ return EQOP; }
"!="							{ return NEQOP; }
"<"							{ return LTOP; }
"<="							{ return LTEQOP; }
">"							{ return GTOP; }
">="							{ return GTEQOP; }
"||"							{ return BOROP; }
"&&"							{ return BANDOP; }
'^'							{ return BXOROP; }
"|"							{ return LOROP; }
"&"							{ return LANDOP; }
"~"							{ return LNOTOP; }
"!"							{ return BNOTOP; }

"@"							{ return EXPOP; }
[-=+/*();:{}]					{ cout<<"\nReturning "<<*yytext<<endl; return *yytext; }

[ \t\n]+						{ cout<<"\nIgnoring space\n";}

.								{ cout<<"\nNonthing matched returning +\n"; return '+'; }

%%

int yywrap()
{
	return 1;
}
