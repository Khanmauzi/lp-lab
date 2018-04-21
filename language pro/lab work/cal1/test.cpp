#include<stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char s[100];
	cin>>s;
	cout<<strtol(s,NULL,10)<<endl;
	cout<<strtol(s,NULL,8)<<endl;
	cin>>s;
	cout<<atof(s);
}