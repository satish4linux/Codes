#include<iostream>
#include<queue>
using namespace std;
vector <int> *graph;
signed int dist[100];
queue <int> temp;
int path[100];
void initialise(int node){
	graph=new vector<int>[node];
}
void addEdge(int x,int y){
	graph[x].push_back(y);
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
		cout<<endl;
	}
}
void Unweighted_Shortest_Path(int n,int node){
	int value;
	temp.push(n);
	for(int i=0;i<node;i++){
		dist[i]=-1;
	}
	dist[n]=0;
	path[n]=n;
	while(!temp.empty()){
		value=temp.front();
		temp.pop();
		for(int i=0;i<graph[value].size();i++){
			int k=graph[value][i];
			if(dist[k]==-1){
				dist[k]=dist[value]+1;
				path[k]=value;
				temp.push(k);
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
	cout<<"Enter the edge pairs:"<<endl;
	while(edge>0){
		int x,y;
		cin>>x>>y;
		addEdge(x-1,y-1);
		edge--;
	}
	cout<<"Enter the single source:";
	int n;
	cin>>n;
	Unweighted_Shortest_Path(n-1,node);
	//cout<<"Shortest path from"<<n<<":"<<endl;
	/*
	for(int i=0;i<node;i++){
		cout<<i+1<<":"<<path[i]+1<<endl;
	}
	*/
	return 0;
}
