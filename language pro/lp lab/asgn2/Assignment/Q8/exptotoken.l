

%{
	#include<bits/stdc++.h>
	using namespace std;
	set<string> keywords;					// to store all the keywords
	string word;
%}
%%
[a-zA-Z]+ 	{
			 word=yytext;					//getting the word from the file
			 if(keywords.find(word)!=keywords.end())
			 cout<<word<<" - keyword"<<endl;
			 else
			 cout<<word<<" - Identfier"<<endl;
			 } //checking for a word
[0-9]+		{cout<<yytext<<" - Constant";}	//matching numbers
[+*/=]		{/*cout<<"Operator";*/}			//matching openrator
. 			{/*"Special symbol";*/}			//special symbol
%%
int yywrap()
{
	return 1;
}
int main()
{
	
	ifstream fin("Keywords.txt",ios::in);			//opening c expression file

	while(!fin.eof())								//adding keywords to a set	
	{
		string str;
		getline(fin,str,' ');
		keywords.insert(str);
	}
	fin.close();
	yyin = fopen("file.txt", "r");
	yylex();
}