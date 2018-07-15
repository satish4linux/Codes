#include<bits/stdc++.h>
using namespace std;

void initialise(int n){
	
}
void addEdge(vector< pair<int,int> > arr[],int x,int y,int weight){
	arr[x].push_back(make_pair(weight,y));
	arr[y].push_back(make_pair(weight,x));
}

void PriorityQueue(vector< pair<int,int> > arr[],int n){
	priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++){
		pq.push(make_pair(i,INT_MAX));
	}
	while(!pq.empty()){
		pair <int,int> p1;
		p1=pq.top();
		pq.pop();
		cout<<p1.second<<" "<<p1.first<<endl;
	}
}
int main(){
	int node,edge;
	int x,y,weight;
	cout<<"Enter the no. of nodes and edges:";
	cin>>node>>edge;
	vector < pair<int,int> > arr[node];
	cout<<"Enter the edges along with weights:"<<endl;
	for(int i=1;i<=edge;i++){
		cin>>x>>y>>weight;
		addEdge(arr,x-1,y-1,weight);
	}
	cout<<"Enter the Single Source:";
	int n;
	cin>>n;
	PriorityQueue(arr,n);
	return 0;
}
