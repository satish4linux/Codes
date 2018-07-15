#include<iostream>
#include<string>
using namespace std;
int min(int x,int y){
	return (x>=y)?y:x;
}
int Min_Operations(string str1,string str2,int a,int b){
	int arr[a+1][b+1];

	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			arr[i][j]=0;
		}
	}

	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			if(i==0)
				arr[i][j]=j;
			else if(j==0)
				arr[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				arr[i][j]=arr[i-1][j-1];
			else
				arr[i][j]=1+min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1]);
		}
	}

	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return arr[a][b];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str1,str2;
	cin>>str1>>str2;
	int a=str1.size();
	int b=str2.size();
	//cout<<a<<" "<<b;
	int res=Min_Operations(str1,str2,a,b);
	cout<<"Minimum Operations (Insert,Replace,Remove) required are "<<res;
	return 0;
}