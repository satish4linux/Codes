#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Autokey Cypher algorithm

string Autokey(string str,int k){
	vector <char> v;
	v.push_back((char)(((int)str[0]+k)%256));
	k=(int)str[0];
	//cout<<k<<"\n";
	for(int i=1;i<str.size();i++){
		v.push_back((char)(((int)str[i]+k)%256));
		k=(int)str[i];
		//cout<<k<<"\n";
	}
	string res(v.begin(),v.end());
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string in_text;
	getline(cin,in_text);
	int k=5;
	string out_text=Autokey(in_text,k);
	cout<<out_text;
	return 0;
}