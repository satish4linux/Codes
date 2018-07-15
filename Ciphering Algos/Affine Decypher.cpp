#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Additive_Inverse(int x){
	return 256-x;
}

// Extended Euclidean's Algorithm

int Multiplicative_Inverse(int x){
	int a=256;
	int b=x;
	int r,q,t1=0,t2=1,t;
	while(b){
		r=a%b;
		q=a/b;
		a=b;
		b=r;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	t1=t1%256;
	if(t1<0) return 256+t1;
	else return t1;
}

// Affine Decyphering algorithm

string Affine(string str,int k1,int k2){
	vector <char> v;
	int temp;
	for(int i=0;i<str.size();i++){
		temp=(int)str[i];
		temp=(temp+Additive_Inverse(k2))*Multiplicative_Inverse(k1);
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
	//cout<<Multiplicative_Inverse(k1);
	return 0;
}