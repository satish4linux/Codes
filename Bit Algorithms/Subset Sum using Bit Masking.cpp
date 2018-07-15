#include<bits/stdc++.h>
using namespace std;
int Subset_Sum(vector <int> nums){
	int n=nums.size();
	int res[(1<<n)];
	memset(res,0,sizeof(res));
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				res[i]+=nums[j];
			}
		}
	}
	
	int sum=0;
	for(int i=0;i<(1<<n);i++){
		sum+=res[i];
	}
	return sum;
}
int main(){
	vector <int> nums;
	cout<<"How many numbers you want to enter?";
	int n;
	cin>>n;
	cout<<"Enter the numbers:"<<endl;
	int value;
	while(n>0){
		cin>>value;
		nums.push_back(value);
		n--;
	}
	int result=Subset_Sum(nums);
	cout<<"Subset Summation:"<<result;
	return 0;
}
