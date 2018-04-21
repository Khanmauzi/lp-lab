
lower [a-z]
upper [A-Z]

%{
	
	
	int lett=0;
	int oth=0;
%}


%%
({upper}|{lower})({lower})* {
			lett++;
}
		
.   {oth++;
	}


%%


int main(){
	yyin=fopen("abc.txt","r");
	yylex();
	printf("%d \n",lett);
	printf("%d \n",oth);
	return 0;
}
