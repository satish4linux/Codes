#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Vigenere Cyphering algorithm

string Vignere(string str,int arr[]){
	vector<char> v;
	int n=6;
	int j=0,temp;
	//for(int i=0;i<6;i++)cout<<arr[i];
	//cout<<str.size();
	for(int i=0;i<str.size();i++){
		if(j==n)
			j=0;
		if(str[i]==' ')v.push_back(str[i]);
		else{
			temp=(int)str[i];
			//cout<<temp<<"\n";
			temp+=arr[j];
			char c=(char)(temp%256);
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
	string in_text;
	getline(cin,in_text);
	int arr[6]={2,3,1,6,4,5};
	string out_text=Vignere(in_text,arr);
	cout<<out_text;
	return 0;
}