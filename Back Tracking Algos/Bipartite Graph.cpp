#include<iostream>
using namespace std;

class Queue{

private:
	int *arr;
	signed int back;
	int cap;

public:
	Queue(int s){
		arr=new int[2*s];
		back=-1;
		cap=2*s;
	}

	bool push(int val){
		/*
		if((back+1)==cap){
			cout<<"Queue is full..";
			return false;
		}
		*/
		back++;
		arr[back]=val;
		return true;
	}

	int pop(){
		if(back==-1){
			cout<<"Queue is empty..";
		}
		else{
			int temp=arr[0];
			for(int i=0;i<back;i++)
				arr[i]=arr[i+1];
			back--;
			return temp;
		}
	}

	bool is_Empty(){
		if(back==-1)
			return true;
		return false;
	}
};

class Graph{

private:
	//int **arr;
	int *visited;
	int *color;
	int vertex;


public:

	int **arr;
	Graph(int v,int e){
		arr=new int*[v];
		for(int i=0;i<v;i++)
			arr[i]=new int[v];
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++)
				arr[i][j]=0;
		}

		visited=new int[v];
		for(int i=0;i<v;i++)
			visited[i]=false;

		color=new int[v];

		vertex=v;

	}

	void Insert(int x,int y){
		arr[x][y]=1;
		arr[y][x]=1;
	}

	void Display_Solution(){
		for(int i=0;i<vertex;i++)
			cout<<color[i]<<" ";
	}

	bool BFS(int n){
		Queue *q=new Queue(vertex);
		q->push(n);
		visited[n]=true;
		color[n]=0;
		int val;
		while(!q->is_Empty()){
			int temp=q->pop();
			cout<<temp<<"\n";

			for(int i=0;i<vertex;i++){
				if(arr[temp][i] && visited[i]==false ){
						color[i]=1-color[temp];
						visited[i]=true;
						q->push(i);
					}
					else if(arr[temp][i] && color[temp]==color[i]){
							return false;
					}
				}
			}
		Display_Solution();
		return true;
	}

	void Print_Graph(){
		for(int i=0;i<vertex;i++){
			for(int j=0;j<vertex;j++){
				cout<<this->arr[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

};

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int node,edge;
	cin>>node>>edge;

	Graph *g=new Graph(node,edge);
	int x,y;
	for(int i=1;i<=edge;i++){
		cin>>x>>y;
		g->Insert(x-1,y-1);

	}

	g->Print_Graph();

	if(g->BFS(0))
		cout<<"Graph is Bipartite";
	else
		cout<<"Graph is not Bipartite";

	return 0;
}