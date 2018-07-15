#include<iostream>
#include<queue>
using namespace std;
vector < pair<int,int> > *graph;
int dist[100];
int path[100];
//bool visited[100]={false};
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
void initialise(int node){
	graph=new vector< pair<int,int> >[node];
}
void addEdge(int x,int y,int weight){
	graph[x].push_back(make_pair(weight,y));
}
void getPath(int desired_node){
	int i=desired_node;
	if(path[i]==i) cout<<i+1;
	else{
	while(path[i]!=i){
		cout<<path[i]+1<<" ";
		i=path[i];
	}		
	}

}
void Display_Path(int node){
	for(int i=0;i<node;i++){
		cout<<i+1<<":";
		if(dist[i]==-1){
			cout<<"Not reacheable";
		}
		else{
			getPath(i);
		}
		cout<<" weight:"<<dist[i];
		cout<<endl;
	}
}
void Dijkstra(int n,int node){
	pair <int,int> value;
	for(int i=0;i<node;i++){
		dist[i]=-1;
	}
	pq.push(make_pair(0,n));
	dist[n]=0;
	path[n]=n;
	//visited[n]=true;
	while(!pq.empty()){
		value=pq.top();
		int top_vertex=value.second;
		int top_weight=value.first;
		pq.pop();
		for(int i=0;i<graph[top_vertex].size();i++){
			pair <int,int> k=graph[top_vertex][i];
			if(dist[k.second]==-1){
				dist[k.second]=top_weight+k.first;
				path[k.second]=top_vertex;
				pq.push(make_pair(dist[k.second],k.second));
				//visited[k.second]=true;
			}
			else{
				if(dist[k.second]>top_weight+k.first){
					dist[k.second]=top_weight+k.first;
					path[k.second]=top_vertex;
					pq.push(make_pair(dist[k.second],k.second));
				}
			}
		}
	}
	Display_Path(node);
}
int main(){
	int node,edge;
	cout<<"Enter the no. of nodes and edges:";
	cin>>node>>edge;
	initialise(node);
	cout<<"Enter the edge pairs and their weights:"<<endl;
	while(edge>0){
		int x,y,weight;
		cin>>x>>y>>weight;
		addEdge(x-1,y-1,weight);
		edge--;
	}
	cout<<"Enter the single source:";
	int n;
	cin>>n;
	Dijkstra(n-1,node);
	/*
	for(int i=0;i<node;i++){
		cout<<dist[i]<<" ";
	}
	*/
	return 0;
}
