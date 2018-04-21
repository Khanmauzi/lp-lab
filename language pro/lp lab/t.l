%{
	int cnt;
%}

%%
"hello world"   printf("hii there \n");
.				printf("try again\n");
[0-9]+			{	cnt++;
					printf("cool %d\n",cnt);
				}

%%
