#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector <int> *graph;
stack <int> temp;
bool visited[100]={false};
void initialise(int node){
	graph=new vector<int>[node];
}
void addEdge(int x,int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}
void DFS(int n){
	int value;
	temp.push(n);
	visited[n]=true;
	while(!temp.empty()){
		value=temp.top();
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
void Print_Graph(int node){
	for(int i=0;i<node;i++){
		cout<<i+1<<":";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j]+1<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cout<<"Enter no. of nodes and edges:";
	int node,edge;
	cin>>node>>edge;
	initialise(node);
	cout<<"Enter the edges:"<<endl;
	while(edge>0){
		int x,y;
		cin>>x>>y;
		addEdge(x-1,y-1);
		edge--;
	}
	int n;
	cout<<"Enter a vertex to start DFS:";
	cin>>n;
	cout<<"DFS Sequence is :";
	DFS(n-1);
	//Print_Graph(node);
	return 0;
}
