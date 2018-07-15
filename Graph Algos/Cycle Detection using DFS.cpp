#include<iostream>
using namespace std;

class Stack{
private:
	int *st;
	int top;
	int capacity;

public:
	Stack(int n){
		st=new int[n];
		top=-1;
		for(int i=0;i<n;i++)
			st[i]=-1;
		capacity=n;
	}

	void push(int x){
		if(top+1==capacity){
			cout<<"Stack is full";
			return;
		}
		top++;
		st[top]=x;
	}

	void pop(){
		if(top==-1){
			cout<<"Stack is empty";
			return;
		}
		top--;
	}

	int get_top(){
		return st[top];
	}

	bool is_empty(){
		return (top==-1)?true:false;
	}
};

class Graph{
private:
	int **arr;
	int vertex;
	int *visited;

public:

	Graph(int v){
		arr=new int*[v];
		for(int i=0;i<v;i++)
			arr[i]=new int[v];

		visited=new int[v];
		for(int i=0;i<v;i++)
			visited[i]=-1;

		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				arr[i][j]=0;

		vertex=v;
	}

	void add_Edge(int x,int y){
		arr[x][y]=1;
	}

	bool is_Cycle(int v){

		Stack *s=new Stack(vertex);
		s->push(v);

		while(!s->is_empty()){
			int temp=s->get_top();
			visited[temp]=true;
			s->pop();

			for(int i=0;i<vertex;i++){
				if(arr[temp][i]==1){
					if(visited[i]==true)
						return true;
					else{
						s->push(i);
					}
				}
			}
		}
		return false;
	}

};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int node,edge,x,y;
	cin>>node>>edge;
	Graph *g=new Graph(node);

	for(int i=0;i<edge;i++){
		cin>>x>>y;
		g->add_Edge(x-1,y-1);
	}

	if(g->is_Cycle(0))
		cout<<"Cycle detected";
	else
		cout<<"No Cycle detected";

	return 0;
}