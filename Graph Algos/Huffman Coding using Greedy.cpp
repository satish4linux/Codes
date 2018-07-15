/*

Huffman Coding Algorithm using Greedy Approach

*/
#include<bits/stdc++.h>

using namespace std;
struct Node{
	char data;
	int freq;
	struct Node* left;
	struct Node* right;
	
	Node(char data, int freq){
		left=right=NULL;
		this->data=data;
		this->freq=freq;
	}
};

struct compare{
	bool operator()(struct Node *left,struct Node *right){
		return(left->freq > right->freq);
	}
};

//--------------------------------------------------------------

void DisplayCode(struct Node *temp, string str){				//prints the Huffman Code By Recursively visiting each node and its children nodes
	if(!temp)
	return;
	if(temp->data!='$')
	cout<<temp->data<<" "<<str<<endl;
	
	DisplayCode(temp->left,str+'0');
	DisplayCode(temp->right,str+'1');
}

//--------------------------------------------------------------
																
void CreateHuffmanTree(char data[],int freq[],int n){
	priority_queue < struct Node *, vector<struct Node *>, compare> pq;		// Huffman Tree Formation using Priority Queue of Vector
	for(int i=0;i<n;i++){
		struct Node *temp;
		temp=new Node(data[i],freq[i]);
		pq.push(temp);
	}
	while(pq.size()!=1){
		struct Node *min1,*min2,*sum;
		min1=pq.top();
		pq.pop();
		min2=pq.top();
		pq.pop();
		sum=new Node('$',min1->freq+min2->freq);
		sum->left=min1;
		sum->right=min2;
		pq.push(sum);
	}
	DisplayCode(pq.top(),"");
}

//--------------------------------------------------------------

int main(){
	cout<<"Enter total characters:";
	int n;
	cin>>n;
	char value[n];
	int frequency[n];
	//arr=new Node[n];
	cout<<"Enter the respective frequencies:"<<endl;
	char character;
	int freq;
	for(int i=0;i<n;i++){
		cin>>character;
		cin>>freq;
		value[i]=character;
		frequency[i]=freq;
	}
	CreateHuffmanTree(value,frequency,n);
}
