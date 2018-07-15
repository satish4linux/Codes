#include<iostream>
using namespace std;

int getMaxCoin(int *arr,int n){
	int **tab=new int*[n];
	for(int i=0;i<n;i++)
		tab[i]=new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tab[i][j]=-1;

	for(int l=1;l<=n;l++){

		for(int i=0; i<=n-l;i++){
			int j=i+l-1;
			for(int k=i;k<=j;k++){
				int leftValue=1;
				int rightValue=1;
				if(i!=0){
					leftValue=arr[i-1];
				}
				if(j!=n-1){
					rightValue=arr[j+1];
				}

				int before=0;
				int after=0;
				if(i!=k){
					before=tab[i][k-1];
				}
				if(j!=k){
					after=tab[k+1][j];
				}
				if(leftValue==1 && rightValue==1)
					tab[i][j]=max(leftValue*arr[k]*rightValue + before + after, tab[i][j]);
				else
					tab[i][j]=max(leftValue*rightValue + before + after, tab[i][j]);

			}
		}
		
	}

	return tab[0][n-1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int *arr;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int res=getMaxCoin(arr,n);
	cout<<res<<"\n";
	return 0;
}