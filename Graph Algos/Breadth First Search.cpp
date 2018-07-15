#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> *graph;
queue <int> temp;
bool visited[100]={false};
void initialise(int node){
	graph=new vector<int>[node];
}
void addEdge(int x,int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}
void BFS(int n){
	int value;
	temp.push(n);
	visited[n]=true;
	while(!temp.empty()){
		value=temp.front();
		cout<<value+1<<" ";
		temp.pop();
		for(int i=0;i<graph[value].size();i++){
			if(visited[graph[value][i]]==false){
				temp.push(graph[value][i]);
				visited[graph[value][i]]=true;
			}
		}
	}
}
int main(){
	int node,edge;
	cout<<"Enter the no. of nodes and edges:";
	cin>>node>>edge;
	initialise(node);
	cout<<"Enter the edge pairs:"<<endl;
	while(edge>0){
		int x,y;
		cin>>x>>y;
		addEdge(x-1,y-1);
		edge--;
	}
	cout<<"Enter a node to BFS:";
	int n;
	cin>>n;
	cout<<"The BFS Sequence :";
	BFS(n-1);
	return 0;
}
