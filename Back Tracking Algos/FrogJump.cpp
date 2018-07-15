#include<iostream>
using namespace std;

int ans;
int m,n;

bool isSafe(int **arr,int x,int y){
	if(x>=0 && x<m && y>=0 && y<n && arr[x][y]==1)
		return true;
	else
		return false;
}

int min_Cost(int **arr,int x,int y){

	if(x==1 && y==3){
		return ans;
	}

	if(isSafe(arr,x,y)==true){
		

		int temp=min_Cost(arr,x+1,y)+1;

		int temp2=min_Cost(arr,x,y+1);

		int temp3=min_Cost(arr,x-1,y)+1;

		int temp4=min_Cost(arr,x,y-1);

		ans=min(min(temp,temp2),min(temp3,temp4));

	}

	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>m>>n;
	int **maze;
	maze=new int*[m];
	for(int i=0;i<m;i++)
		maze[i]=new int[n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>maze[i][j];



	int res=min_Cost(maze,0,0);
	cout<<res;
	return 0;
}