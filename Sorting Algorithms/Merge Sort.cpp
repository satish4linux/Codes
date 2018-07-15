#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
	int n_l=mid-low+1;
	int n_r=high-mid;
	int left[n_l],right[n_r];
	for(int i=0;i<n_l;i++){
		left[i]=arr[low+i];
	}
	for(int i=0;i<n_r;i++){
		right[i]=arr[mid+1+i];
	}
	int i=0;
	int j=0;
	int k=low;
	while(i<n_l && j<n_r){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			i++;
		}
		else{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n_l){
		arr[k]=left[i];
		k++;
		i++;
	}
	while(j<n_r){
		arr[k]=right[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int low,int high){
	if(low<high){
		int mid=(high+low)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	cout<<"Sorted Order"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
