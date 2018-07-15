#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Affine Cyphering algorithm

string Affine(string str,int k1,int k2){
	vector <char> v;
	int temp;
	for(int i=0;i<str.size();i++){
		temp=(int)str[i];
		temp=temp*k1 +k2;
		v.push_back((char)temp%256);
	}
	string res(v.begin(),v.end());
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string in_text;
	getline(cin,in_text);
	int k1=3;
	int k2=6;
	string out_text=Affine(in_text,k1,k2);
	cout<<out_text;
	return 0;
}