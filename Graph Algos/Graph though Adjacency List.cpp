#include<bits/stdc++.h>
using namespace std;
vector <int> *graph;
void initialise(int n){
	graph=new vector<int>[n];
}
void addEdge(int x,int y){
	graph[x].push_back(y);
}
void Display_Graph(int n){
	for(int i=0;i<n;i++){
		cout<<i+1<<"->";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j]+1<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n,m;
	int x,y;
	cin>>n>>m;
	initialise(n);
	while(m>0){
		cin>>x>>y;
		addEdge(x-1,y-1);
		m--;
	}
	Display_Graph(n);
	return 0;
}
