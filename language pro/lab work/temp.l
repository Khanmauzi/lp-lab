%{
	#include<bits/stdc++.h>
	using namespace std;
	int k;
	void word(char *str);
	void number(char *str);
	string encrypt(string x,int k);
	map<string,int> mp;//stores all the special words
	ofstream fout("output.txt",ios::out);
%}
%%
[a-zA-Z]+ 	{word(yytext);} //checking for a word
[0-9]+		{number(yytext);} //for number
[ ]+		{fout<<" ";} //replacing multiple W's by single space
. 			{fout<<yytext;} //leaving special characters
"\n"		{fout<<"\n";}
%%
int yywrap()
{
	return 1;
}

//encrypts the given word by k cyclic rotations
string encrypt(string x,int k)
{
	string result="";
	for(int i=x.size()-1;i>=0;i--)//processing right to left
	{
		char ch=x[i];
		if(ch>=97&&ch<=122)//lower character
		{
			if((ch+k)>122)
				ch=(ch+k)%122+97;
			else
				ch=(ch+k);
		}
		else //Uppercase characters
		{
			if((ch+k)>90)
				ch=(ch+k)%90+65;
			else
				ch=(ch+k);
		}
		result+=ch;
	}
	return result;
}

void word(char *str)
{
	string x=str;
	if(mp.find(x)!=mp.end())//checking if the given word is special word or not
	{
		string z=encrypt(x,2);
		fout<<z; 
	}
	else
	{
		string z=encrypt(x,k);
		fout<<z;
	}	
}
void number(char *str)
{
	string result;
	string x=str;
	int len=x.size();
	int half=x.size()/2;
	if(len%2==0)//even number of digits
	{
		string first=x.substr(0,half);
		string second=x.substr(half,half);
		result=second+first;
	}
	else
	{
		string first=x.substr(0,half);
		string second=x.substr(half+1,half);
		result=second+x[half]+first;	
	}
	fout<<result;
}

int main()
{

	cout<<"Enter the value for k for k-cyclic rotations : "<<endl;
	cin>>k;
	ifstream fin("specialWords.txt",ios::in);
	//saving special words in map
	string str;
	while(!fin.eof())
	{
		getline(fin,str,' ');
		mp[str]=1;
	}

	fin.close();
	yyin=fopen("file4.txt","r");//open lex input file
	yylex();
	return 0;
}