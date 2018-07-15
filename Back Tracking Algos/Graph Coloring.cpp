#include<iostream>
using namespace std;
class Graph{

private:

	int *color;
	int vertex;

	bool is_Safe(int v,int c){

		for(int i=0;i<vertex;i++){
			if(arr[v][i] && c == color[i])
				return false;
		}
		return true;
	}

	bool graph_Coloring_Utils(int m,int v){

		if(v==vertex)
			return true;

		for(int i=1;i<=m;i++){

			if(is_Safe(v,i)){	
				color[v]=i;

				if(graph_Coloring_Utils(m,v+1)==true)
					return true;

				color[v]=0;
			}
		}

		return false;
	}

	void Display_Solution(){
		for(int i=0;i<vertex;i++){
			cout<<color[i]<<" ";
		}
	}


public:

		int **arr;
	Graph(int v){
		this->arr=new int*[v];							//creating a 2D array
		for(int i=0;i<v;i++)
			arr[i]=new int[v];

		this->vertex=v;
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				arr[i][j]=0;
			}
		}
	}

	bool graph_Coloring(int m){
		color=new int[vertex];
		for(int i=0;i<vertex;i++)
			color[i]=0;

		if(graph_Coloring_Utils(m,0)==false){
			cout<<"No Solutions"<<"\n";
			return false;
		}

		Display_Solution();
		return true;
	}

};

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int edge,node;
	cin>>node>>edge;

	int x,y;
	Graph *g=new Graph(node);			// instantiating a graph
	for(int i=1;i<=edge;i++){
		cin>>x>>y;
		g->arr[x-1][y-1]=1;
		g->arr[y-1][x-1]=1;
	}

	int m;								// minimum number of colors required
	cin>>m;

	g->graph_Coloring(m);
	return 0;
}