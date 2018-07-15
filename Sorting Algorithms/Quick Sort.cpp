#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
	int p=high;
	int i=low-1;
	
	for(int j=low;j<high;j++){
		if(arr[j]<=arr[p]){
			i++;
			int c=arr[i];
			arr[i]=arr[j];
			arr[j]=c;
		}
	}
	int c=arr[i+1];
	arr[i+1]=arr[p];
	arr[p]=c;
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n]={0};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	cout<<"Sorted Order"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
