#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Vigenere Decyphering algorithm

string Vigenere(string str,int arr[]){
	vector <char> v;
	int n=6;
	int j=0,temp;

	for(int i=0;i<str.size();i++){
		if(j==n)
			j=0;
		if(str[i]==' ')v.push_back(str[i]);
		else{
			temp=(int)str[i];
			temp-=arr[j];
			if(temp<0) temp+=256;
			char c=(char)(temp);
			v.push_back(c);
			j++;
		}
	}
	string res(v.begin(),v.end());
	return res;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int arr[6]={2,3,1,6,4,5};
	string in_text;
	getline(cin,in_text);
	string out_text=Vigenere(in_text,arr);
	cout<<out_text;
	return 0;
}