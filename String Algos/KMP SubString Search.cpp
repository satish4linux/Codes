#include<iostream>
using namespace std;
void initiate(string pattern,long int arr[]){
	long int n=pattern.length();
	arr[0]=0;
	long int i;
	for(long int j=0;i<n;){
		for(i=1;i<n;){
			if(pattern[j]==pattern[i]){
				arr[i]=j+1;
				j++;
				i++;
			}
			else{
				if(j!=0){
					j=arr[j-1];
				}
				else{
					arr[i]=0;
					i++;
				}
			}
		}
	}
}
int KMP_Search(string str, string pattern, long int arr[]){
	long int count=0;
	long int m=str.length();
	long int n=pattern.length();
	for(long int i=0;i<m;){
		long int j;
		for(j=0;;){
			if(str[i]==pattern[j]){
				i++;
				j++;
			}
			else{
				if(j!=0){
					j=arr[j-1];
				}
				else{
					i++;
				}
			}
		}
		if(j==n-1){
			 count++;
			 j=0;
		}
	}
	return count;
	}
int main(){
	string str,pattern;
	cin>>str;
	cin>>pattern;
	long int pre_arr[pattern.length()];
	initiate(pattern,pre_arr);
	int count = KMP_Search(str,pattern,pre_arr);
	cout<<count;
	return 0;
}
