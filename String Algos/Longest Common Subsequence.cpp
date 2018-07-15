#include<iostream>
using namespace std;
int arr[100][100];
void initialize(int x,int y){
	for(int i=0;i<y;i++){
		arr[0][i]=0;
	}
	for(int j=1;j<x;j++){
		arr[j][0]=0;
	}
}
int max_val(int a,int b){
	return (a>b)?a:b;
}
void Longest_Common_Subsequence(string str1,string str2){
	int x=str1.length();
	int y=str2.length();
	initialize(x,y);
	for(int i=1;i<y;i++){
		for(int j=1;j<x;j++){
			if(str2[j-1]==str2[x-1]){
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else{
				arr[i][j]=max_val(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	cout<<"Length of Longest Common Subsequence is "<<arr[x-1][y-1]<<endl;
}
int main(){
	string str1,str2;
	cin>>str1>>str2;
	Longest_Common_Subsequence(str1,str2);
	return 0;
}
