#include<iostream>
using namespace std;

class Graph{

private:
	int **arr;
	int vertex;
	bool *visited;
	bool *recstack;

public:

	Graph(int v){
		arr=new int*[v];
		for(int i=0;i<v;i++)
			arr[i]=new int[v];

		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				arr[i][j]=0;

		visited=new bool[vertex];
		recstack=new bool[vertex];

		for(int i=0;i<v;i++){
			visited[i]=false;
			recstack[i]=false;
		}
		vertex=v;
	}

	void addEdge(int x,int y){
		arr[x][y]=1;
	}

	bool Util(int v){

		if(visited[v]==false){

			visited[v]=true;
			recstack[v]=true;

			for(int i=0;i<vertex;i++){
				if(arr[v][i]==1){
					if(!visited[i] && Util(i) )
						return true;
					else if(recstack[i])
						return true;
				}
			}
		}

		recstack[v]=false;
		return false;
	}

	bool isCycle(){

		for(int i=0;i<vertex;i++){
			if(Util(i))
				return true;
		}

		return false;

	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int node,edge;
	cin>>node>>edge;

	Graph *g=new Graph(node);
	int x,y;

	for(int i=0;i<edge;i++){
		cin>>x>>y;
		g->addEdge(x-1,y-1);
	}

	if(g->isCycle())
		cout<<"cyclic";
	else
		cout<<"not cyclic";

	return 0;
}