#include<iostream>
#include<algorithm>
#define val 5
using namespace std;
int main(){
	int arr[val];
	cout<<"Enter the values in the array."<<endl;
	int j=0;
	while(j<val){
		cin>>arr[j];
		j++;
	}
	sort(arr,arr+val);
	/*
	for(int k=0;k<val;k++){
		cout<<arr[k]<<" ";
	}
	*/
	for(int i=0;i<val-1;i++){
		if(arr[i]^arr[i+1]==0)
		continue;
		else{
			if(i==0){
				cout<<arr[i];
				break;
			}
			if(i+1==val-1){
				cout<<arr[i+1];
				break;
			}
			else{
				if(arr[i+1]^arr[i+2]!=0){
					cout<<arr[i];
					break;
				}
				else
				continue;
			}
		}
	}
	return 0;
}
