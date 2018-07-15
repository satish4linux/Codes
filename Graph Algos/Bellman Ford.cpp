#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;
vector <pair<int, signed int> > *graph;
int dist[100];
int path[100];
void initialize(int node){
	graph=new vector<pair< int,signed int> >[node];
	for(int i=0;i<node;i++){
		dist[i]=INT_MAX;
	}
}
void addEdge(int x,int y,signed int weight){
	graph[x].push_back(make_pair(y,weight));
}
void Bellman_Ford(int n,int node){
	int source;
	queue <pair<int,signed int> > q;
	while(node>0){
		source=n;
		q.push(make_pair(source,0));
		dist[source]=n;
		path[source]=source;
		while(!q.empty()){
			pair<int,signed int> temp;
			temp=q.front();
			q.pop();
			int dest=temp.first;
			signed int weight=temp.second;
			for(int i=0;i<graph[dest].size();i++){
				int k=graph[dest][i].second;
				signed int m=graph[dest][i].first;
				if(dist[m]>dist[dest]+k){
					dist[m]=dist[dest]+k;
					path[m]=dest;
					q.push(make_pair(m,k));
				}
			}
		}
		node--;
	}
}
void pattern(int n){
	if(path[n]==n)
	cout<<n+1<<" ";
	while(path[n]!=n){
		cout<<path[n]+1<<" ";
		n=path[n];
	}
}
int main(){
	int node,edge;
	cout<<"Enter the no. of nodes and edges:";
	cin>>node>>edge;
	initialize(node);
	cout<<"Enter the edge pairs:"<<endl;
	while(edge>0){
		int x,y;
		signed int weight;
		cin>>x>>y>>weight;
		addEdge(x-1,y-1,weight);
		edge--;
	}
	cout<<"Enter the source node:";
	int n;
	cin>>n;
	Bellman_Ford(n-1,node);
	cout<<"Shortest distances are:"<<endl;
	for(int i=0;i<node;i++){
		cout<<i+1<<":"<<dist[i]<<endl;
	}
	cout<<"Shortest paths are:"<<endl;
	for(int i=0;i<node;i++){
		cout<<i+1<<":";
		pattern(i);
		cout<<endl;
	}
	return 0;
}
