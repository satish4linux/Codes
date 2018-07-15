#include<iostream>
using namespace std;
int LIS(int arr[],int n);
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int arr[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int val=LIS(arr,n);
	cout<<"Length of Longest Increasing Subsequence is "<<val;
}
int LIS(int arr[],int n){
	int temp[n];
	int max;
	for(int i=0;i<n;i++){
		if(i==0)
			temp[i]=1;
		else{
			int max_here=INT_MIN;
			for(int j=i-1;j>=0;j--){
				if(arr[j]<arr[i]){
					if(max_here<temp[j])
						max_here=temp[j];
				}
			}
			if(max_here==INT_MIN)
				temp[i]=1;
			else
				temp[i]=max_here+1;
		}
	}
	//cout<<n;
	//getting max of all l[]
	/*
	for(int i=0;i<n;i++){
		cout<<temp[i]<<" ";
	}
	*/
	max=temp[0];
	for(int i=0;i<n;i++){
		if(max<temp[i])
			max=temp[i];
	}
	return max;
}