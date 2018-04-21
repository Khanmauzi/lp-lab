


%{
	#include <stdio.h>
	#include "y.tab.h"
 	double hexToDecimal(char *yytxt)
	{
		int hexNumber;
		int decimalPart;
		int i = 0;
		int flag = 0;
		while(yytxt[i]&&yytxt[i]!='.')
		{
			i++;
		}
		if(yytxt[i] && yytxt[i] == '.')
		{
			sscanf(yytxt + i + 1, "%x", &decimalPart);
			 printf("point  part %d\n", decimalPart);
			flag = 1;
		}
		yytxt[i] = '\0';
		sscanf(yytxt, "%x", &hexNumber);
		printf("number Part %d \n" , hexNumber);
		double number = hexNumber;
		if(flag)
		{
			double end = decimalPart;
			while(end > 1)
				end /=10;
			number+=end;

		}
		return number;
	}
%}
%%
[A-Fa-f0-9]+(\.[A-Fa-f0-9]+)?  {yylval = hexToDecimal(yytext); return NUM;}
\n      return 0;
.       return *yytext;
%%

