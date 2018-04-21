// CYK ALGORITHM IMPLEMENTATION
/*
	NAME : MOJAMMIL	
	CLASS : III YEAR, CSE
	ROLL : 157238
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>



using namespace std;
struct production{
	string ch;
	string s;
	
};


void display(vector<production>v){
	cout<<"Productions rule are : "<<endl;
	for(int i=0;i<v.size();i++){
		production p=v[i];
		cout<<p.ch<<"      "<<p.s<<endl;
	}
}


string getdata(string base[],vector<production>v,int j){
	string s="";
	for(int i=0;i<v.size();i++){
		production p=v[i];
		if(p.s==base[j]){
			s=s+p.ch;
		}
		
	}
	if(s==""){
		s=s+"^";
	}
	return s;
	
}

vector<string> getdata1(string s1,string s2){
	vector<string>v1;
	for(int i=0;i<s1.length();i++){
		string s="";
		if(s1=="^"){
			s=s1;
			break;
		}
		for(int j=0;j<s2.length();j++){
			s=s1[i];										//making all the possible combination
			s=s+s2[j];
			v1.push_back(s);
		}
	}
	
	return v1;
}
string getval(vector<string>s,vector<production>v){
	string res="";
	for(int i=0;i<v.size();i++){
		production p=v[i];
		if(find(s.begin(),s.end(),p.s)!=s.end()){
			res=res+p.ch;
			//cout<<p.s<<"       "<<p.ch<<endl;
		}
	}
	if(res==""){
		res="^";
	}
	 return res;
}

void print(vector<string>v,int i,int j){
	cout<<"i : "<<i<<" j : "<<j<<endl;
	for(int k=0;k<v.size();k++){
		cout<<v[k]<<"  ";
	}
	cout<<endl;
}


bool check(char ch,string s){
	for(int i=0;i<s.length();i++){
		if(s[i]==ch)
			return true;
	}
	return false;
}

int main(){
	vector<production>v;
	while(1){
		string ch;
		string s;
		cout<<"Enter starting production : (. to stop)";
		cin>>ch;
		if(ch==".")
		break;
		cout<<"Enter the production (^ for null production): ";
		cin>>s;
		production p;
		p.ch=ch;
		p.s=s;
		v.push_back(p);
	}
	display(v);
	
	string l;
	cout<<"enter the language : ";
	cin>>l;
	int n=l.length();
	string base[n];
	for(int i=0;i<n;i++){
		base[i]=l[i];
	}
	string a[n][n];
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-cnt;j++){
			if(i==n-1){
				string s=getdata(base,v,j);
				a[i][j]=s;
			
			}
			else if(i==n-2){
				vector<string>s=getdata1(a[i+1][j],a[i+1][j+1]);
			//	print(s,i,j);
				string s1=getval(s,v);
			//	cout<<" i : "<<i<<" j : "<<j<<"  " <<s1<<endl;
				a[i][j]=s1;
		}
			else {
				//cout<<cnt<<endl;
				int c1=n-1;
				int c2=j;
				int c3=i;
				string s1="";
				while(c1!=i){
					//cout<<"C1 : "<<c1<<endl;
					vector<string>s=getdata1(a[c1][j],a[c3+1][c2+1]);
					string t=getval(s,v);
					if(t!="^"){
		
						s1=s1+t;
					}
					//cout<<"S1 : "<<s1<<endl;
					c1--;
					c2++;
					c3++;
				}
				if(s1==""){
					s1="^";
				}
				set<char>st;
				for(int temp=0;temp<s1.size();temp++){
					st.insert(s1[temp]);
				}
				s1="";
				set<char>::iterator it;
				set<char>::iterator it1;
				it1=st.end();
				it1--;
				s1=s1+*it1;
				for(it=st.begin();it!=it1;it++){
					s1=s1+*it;
				}
				a[i][j]=s1;
                
 			}
		}
		cnt++;
	}
	cnt=0;
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-cnt;j++){
				cout<<a[i][j];
				cout<<"    ";
		}
		cout<<endl;
		cnt++;
	}
	
	
	if(check('S',a[0][0])){
		cout<<l<<" is in language of given grammer : "<<endl;
	}
	else{
		cout<<l<<" is not in language of given grammer : "<<endl;
	}
	
	
	
return 0;	
	
}
