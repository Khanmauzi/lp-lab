#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int>s;
	s.insert(10);
	s.insert(5);
	s.insert(25);
	s.insert(20);
	s.insert(35);
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<"   ";
	}
	return 0;
}