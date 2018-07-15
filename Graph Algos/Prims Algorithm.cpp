#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <pair<signed int,int> > *graph;
void initialize(int node){
	graph=new vector<pair<signed int,int> >[node];
}
map <int, string> path;
bool flag[100];
void addEdge(int x,int y,signed int weight){
	graph[x].push_back(make_pair(weight,y));
}
void Prims(int n,int node){
	int source=n;
	priority_queue< pair<signed int,int>, vector<pair <signed int,int> >, greater< pair<signed int,int> > > pq;
	pq.push(make_pair(0,source));
	while(!pq.empty()){
		pair<signed int,int> temp;
		temp=pq.top();
		flag[temp.second]=true;
		pq.pop();
		cout<<path[temp.second]<<",";
		for(int i=0;i<graph[temp.second].size();i++){
			pair <signed int,int> pp;
			pp=graph[temp.second][i];
			if(flag[pp.second]==false){
				string edge=temp.second+"-"+pp.second;
				pq.push(make_pair(pp.first,pp.second));
				path.insert(pair<int, string>(pp.second,edge));
			}
		}
	}
}
int main(){
	int node,edge;
	cout<<"Enter the no. of nodes and edges:";
	cin>>node>>edge;
	initialize(node);
	memset(flag,false,sizeof(flag));
	cout<<"Enter edge pairs:"<<endl;
	while(edge>0){
		int x,y;
		signed int weight;
		cin>>x>>y>>weight;
		addEdge(x-1,y-1,weight);
		edge--;
	}
	cout<<"Enter the root node:";
	int n;
	cin>>n;
	Prims(n-1,node);
	return 0;
}
