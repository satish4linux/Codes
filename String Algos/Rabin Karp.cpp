/*
	Rabin Karp String Search Algorithm
	
	Complexity : O(m*n)
	
	m : length of text ; n : length of pattern
*/
#include<iostream>
#include<math.h>
#define BASE 3
using namespace std;
string text;
string pattern;
int createHash(string str,int n){
	int hash=0;
	for(int i=0;i<n;i++){
		hash+=(str[i]-'a')*pow(BASE,i);
	}
	return hash;
}
int recreateHash(int text_hash,int l,int n){
	int hash=0;
	hash=text_hash-(text[l-1]-'a');
	hash/=BASE;
	hash+=(text[l+n-1]-'a')*pow(BASE,n-1);
	return hash;
}
int main(){
	cout<<"Enter the text:";
	cin>>text;
	cout<<"Enter the pattern:";
	cin>>pattern;
	int flag=0;
	if(text.length()<pattern.length()){
		cout<<"Invalid Input";
	}
	else{
		int n=text.length();
		int m=pattern.length();
		int patt_hash=createHash(pattern,m);//cout<<patt_hash<<endl<<endl;
		int text_hash=createHash(text,m);//cout<<text_hash<<endl;
		if(patt_hash==text_hash){
			int i=0;
			int k=i;
			for(i=0;i<m && (pattern[i]==text[i]);i++){
				continue;
			}
			if(i==m) cout<<"Match found at index "<<k;
		}
		else{
			for(int i=1;i<=n-m+1;i++){
				text_hash=recreateHash(text_hash,i,m);//cout<<text_hash<<endl;
				if(patt_hash==text_hash){
					int k=i;
					int j;
			for(j=0;j<m && (pattern[j]==text[i+j]);j++){
				continue;
			}
			if(j==m){
				flag=1;
				cout<<"Match found at index "<<k;
				break;
			}
		}
			}
			if(flag==0) cout<<"No match found";
		}
	}
	return 0;
}
