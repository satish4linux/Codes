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
int main(){
	string pattern;
	cin>>pattern;
	long int pre_arr[pattern.length()];
	initiate(pattern,pre_arr);
	for(int i=0; i<pattern.length();i++){
		cout<<pre_arr[i]<<" ";
	}
	return 0;
}
