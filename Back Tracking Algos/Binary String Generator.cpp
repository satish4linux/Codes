#include<iostream>
using namespace std;
char arr[100];
void Generate_Strings(int n){
	if(n<1){
		cout<<arr<<" ";
	}
	else{
		arr[n-1]='0';
		Generate_Strings(n-1);
		arr[n-1]='1';
		Generate_Strings(n-1);
	}
}
int main(){
	int n;
	cout<<"Enter the no. of bits:";
	cin>>n;
	Generate_Strings(n);
	return 0;
}
