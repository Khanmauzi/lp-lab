%{
	#include<bits/stdc++.h>
	using namespace std;
	map<string,pair<int,vector<int> > > mp;
	void addToTable(char *str);
	int lineno=1;
%}
%%
[a-zA-Z']+ 	{addToTable(yytext);}/*'*/
"\n"		{lineno++;}
%%
int yywrap()
{
	return 1;
}
void addToTable(char *str)
{
	string x=str;
	if(mp.find(x)!=mp.end())//found in table
	{
		pair<int,vector<int> > p=mp[x];
		int freq=p.first;
		vector<int> lines=p.second;
		freq+=1;
		if(lineno!=lines[lines.size()-1])//not the same line
		lines.push_back(lineno);
		mp[x]=make_pair(freq,lines);
	}
	else //first occurence of the word
	{
		vector<int> lines;
		lines.push_back(lineno);
		mp[x]=make_pair(1,lines);
	}
}
int main()
{
	yyin=fopen("file.txt","r");//open lex input file
	yylex();
	map<string,pair<int,vector<int> > >::iterator itr;
	cout<<"Word  \t Frequency  Line numbers"<<endl;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		cout<<itr->first<<" ";
		pair<int,vector<int> > p=itr->second;
		cout<<p.first<<"  [";
		vector<int> lines=p.second;
		//printing line numbers
		for(int i=0;i<lines.size();i++)
		{
			cout<<lines[i]<<" ";
		}
		cout<<"]"<<endl;
	}
	return 0;
}