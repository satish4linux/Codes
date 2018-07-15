#include<iostream>
using namespace std;

struct Edge{
	int src;
	int dest;
};

class Graph{

private:

	struct Edge *arr;
	int edge;
	int vertex;


public:

	Graph(int e,int v){
		arr=new Edge[e];
		edge=e;
		vertex=v;
	}

	void addEdge(int i,int src,int dest){
		arr[i].src=src;
		arr[i].dest=dest;
	}

	int find(int parent[], int x){
		if(parent[x]==-1)
			return x;
		find(parent,parent[x]);
	}

	void Union(int parent[],int x,int y){
		int src=find(parent,x);
		int dest=find(parent,y);
		parent[dest]=src;
	}

	bool isCycle(){

		int *parent=new int[vertex];
		for(int i=0;i<vertex;i++)
			parent[i]=-1;

		for(int i=0;i<edge;i++){
			int x=find(parent, arr[i].src);
			int y=find(parent, arr[i].dest);

			if(x==y)
				return 1;
			else
				Union(parent,x,y);
		}

		return 0;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int node,edge;
	cin>>node>>edge;

	Graph *g=new Graph(edge,vertex);
	int x,y;

	for(int i=0;i<edge;i++){
		cin>>x>>y;
		g->addEdge(i,x-1,y-1);
	}

	if(g->isCycle())
		cout<<"cyclic";
	else
		cout<<"not cyclic";

	return 0;
}