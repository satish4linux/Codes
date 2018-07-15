#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int k;
	cin>>t;
	while(t){
		cin>>k;
		char str[4096];
		fflush(stdin);
		cin>>str;
		int n=strlen(str);
		//cout<<n;
		int count=0;
		int sum=0;
		
		for(int i=0;i<n-1;i++){
			if(str[i]=='('){
				count++;
				if(count==k+1 && str[i+1]!=')' ){
					int j=i+1;
					char temp[5];
					temp[0]=str[i+1];
					int k=1;
					while(str[j+1]!=')'){
						temp[k]=str[j+1];
						k++;
						j++;
					}
					sum+=atoi(temp);
					//cout<<sum<<"\n";
				}
			}
			else if(str[i]==')'){
				count--;
			}
		}
		cout<<sum<<"\n";
		t--;
	}
	return 0;
}