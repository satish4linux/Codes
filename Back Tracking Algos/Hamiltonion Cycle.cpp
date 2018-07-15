#include<iostream>
using namespace std;

class Graph{

private:
	int **arr;
	int vertex;
	int *path;
	bool *visited;

	bool is_Safe(int curr_node,int prev_node){

		if(arr[curr_node-1][prev_node]==0)
			return false;

		if(visited[curr_node]==false)
			return true;
		else
			return false;
	}

	bool Ham_Cycle_Util(int v){

		if(v==vertex){
			if(arr[v-1][path[0]]==1)
				return true;
			else
				return false;
		}

		for(int n=1;n<vertex;n++){
			if(is_Safe(n,v)==true){

				path[v]=n;
				visited[v]=true;

				if(Ham_Cycle_Util(v+1)==true)
					return true;

				path[v]=-1;
			}
		}

		return false;
	}

	void Print_Sol(){
		for(int i=0;i<vertex;i++){
			cout<<path[i]<<" ";
		}
	}

public:
	Graph(int v){
		arr=new int*[v];

		for(int i=0;i<v;i++)
			arr[i]=new int[v];

		vertex=v;

		visited=new bool[v];

		for(int i=0;i<v;i++)
			visited[i]=false;
	}

	void Insert(int x,int y){
		arr[x][y]=1;
		arr[y][x]=1;
	}

	bool Hamiltonion_Cycle(int v){
		path=new int[v];
		for(int i=0;i<v;i++){
			path[i]=-1;
		}

		path[0]=0;
		visited[0]=true;
		if(Ham_Cycle_Util(1)==false){
			cout<<"Cycle does not exist";
			return false;
		}

		Print_Sol();
		return true;
	}


};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int node,edge;
	cin>>node>>edge;
	Graph *g=new Graph(node);

	int x,y;
	for(int i=1;i<=edge;i++){
		cin>>x>>y;
		g->Insert(x-1,y-1);
	}

	g->Hamiltonion_Cycle(node);
	return 0;

}