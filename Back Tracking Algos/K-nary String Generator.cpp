#include<iostream>
using namespace std;
char arr[100];
void Generate_Strings(int n,int k){
	if(n<1){
		cout<<arr<<endl;
	}
	else{
		for(int i=0;i<k;i++){
			arr[n-1]='0'+i;
			Generate_Strings(n-1,k);
		}
	}
}
int main(){
	int k,n;
	cout<<"Enter the base value:";
	cin>>k;
	cout<<"Enter the no. of bits:";
	cin>>n;
	Generate_Strings(n,k);
	return 0;
}
