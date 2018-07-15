#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Autokey Decyphering algorithm

int Additive_Inverse(int k){
	return 256-k;
}

string Autokey(string str,int k){
	vector <char> v;
	//int temp=(int)str[0];
	char c=(char)(((int)str[0]+Additive_Inverse(k))%256);
	cout<<c;
	v.push_back(c);
	k=(int)c;
	for(int i=1;i<str.size();i++){
		//temp=(int)str[i];
		c=(char)(((int)str[i]+Additive_Inverse(k))%256);
		cout<<c;
		v.push_back(c);
		k=(int)c;
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
	//cout<<out_text;
	return 0;
}