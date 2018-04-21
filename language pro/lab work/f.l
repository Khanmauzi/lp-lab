%{
	#include<bits/stdc++.h>
	using namespace std;
	int f1(int a);
	int f2(int a,int b);
	int f3();
	vector<int> v;
	map<string,int> mp;
%}

%%
f1 {f1(2);}
f2 {f2(2,3);}
print {f3();}
[a-zA-Z]+	{printf("fucntion not called \n");}
%%

int f1(int a){
	printf("fucnction 1 is called \n");
	v.push_back(a);

}
int f2(int a,int b){
	printf("fucnction 2 is called \n");
	v.push_back(a);
	v.push_back(b);
}
int f3(){
	for(int i=0;i<v.size();i++){
		printf("%d \n",v[i]);
	}
}
int main(){
	yylex();
	return 0;
}