#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> *graph;
int degree[100];
queue <int> temp;
void initialise(int node){
	graph=new vector<int>[node];
}
void addEdge(int x,int y){
	graph[x].push_back(y);
	degree[y]++;
}

void Topological_Sort(int node){
	int value;
	int i=0;
	while(i<node){
		if(degree[i]==0)
			temp.push(i);
		i++;
	}
	while(!temp.empty()){
		value=temp.front();
		cout<<value+1<<" ";
		temp.pop();
		for(int i=0;i<graph[value].size();i++){
			degree[graph[value][i]]--;
			if(degree[graph[value][i]]==0){
				temp.push(graph[value][i]);
			}
		}
	}
}
int main(){
	int node,edge;
	cout<<"Enter the no. of node and edge:";
	cin>>node>>edge;
	initialise(node);
	cout<<"Enter the edge pairs:"<<endl;
	while(edge>0){
		int x,y;
		cin>>x>>y;
		addEdge(x-1,y-1);
		edge--;
	}
	/*
	for(int i=0;i<node;i++){
		cout<<degree[i]<<" ";
	}
	*/
	cout<<"Topologically Sorted Sequence of vertices:";
	Topological_Sort(node);
	return 0;
}
