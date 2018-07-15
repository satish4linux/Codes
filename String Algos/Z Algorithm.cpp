#include<bits/stdc++.h>
using namespace std;
int main(){
	string text;
	string pattern;
	cout<<"Enter the text:";
	cin>>text;
	cout<<"Enter the pattern:";
	cin>>pattern;
	string str=pattern+'$'+text;
	int l=pattern.length();
	
	//------------------------------------------------------------------------
	
	int z[str.length()]={0};									//Z Algorithm Starts here for creating the Z Array
	for(int i=1;i<str.length();){
		int j=0;
		int count=i;
		while(str[j]==str[count]){
			j++;
			count++;
			z[i]++;
		}
		if(z[i]>0){
			int m=1;
			int k=i+1;
			while(k<z[i]+i){
				z[k]=z[m];
				k++;
				m++;
			}
			i=k;
		}
		else{
			i++;
		}
	}															//Z Algorithm Ends here
	
	//---------------------------------------------------------------------
	
	/*
	for(int i=0;i<str.length();i++){
		cout<<z[i]<<" ";
	}
	*/
	cout<<"The pattern matches at indices :";
	for(int i=0;i<str.length();i++){
		if(z[i]==l){
			cout<<i-l-1<<" ";
		}
	}
	return 0;
}
