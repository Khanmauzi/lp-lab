/* programm to count the frequcy of inputs */

%{
	int lc=0;
	int uc=0;
	int num=0;
	int digits=0;
	int words=0;
	int ch=0;
	int line=0;
	int spl=0;


%}


%%
[a-z]		{
			lc++;
			//printf("number of lowercase alphabet are : %d\n",lc);
		}

[A-Z]		{
			uc++;
			//printf("number of upperrcase alphabet are : %d\n",uc);
		}

[0-9]*		{
			num++;
			//printf("number of numbers are : %d\n",num);
		}

[0-9]		{
		digits++;
		//printf("%d",digits);
}
[ \t\n]    {
	words++;
}



%%


int main(void){
	yyin=fopen("abc.txt","r");
	yylex();
	printf("number of lowercase alphabet are : %d\n",lc);
	printf("number of upperrcase alphabet are : %d\n",uc);
	printf("number of numbers are : %d\n",num);
	printf("number of digit are : %d\n",digits);
	printf("number of words are : %d\n",words);
	//printf("number of lines are : %d\n",line);
	//printf("number of special character are : %d\n",spl);

	return 0;
}