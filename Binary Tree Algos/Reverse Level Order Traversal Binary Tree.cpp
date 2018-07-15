#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
	bool isdelim;
};
struct node *root=NULL;
void Insert(int value){
	node *temp=new node;
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	temp->isdelim=false;
	if(root==NULL){
		root=temp;
		cout<<"Root Inserted"<<endl;
	}
	else{
		queue <struct node*> q;
		node *current;
		q.push(root);
		while(!q.empty()){
			current=q.front();
			q.pop();
			if(current->left==NULL){
				current->left=temp;
				cout<<"Successfully Inserted"<<endl;
				break;
			}
			else{
				q.push(current->left);
			}
			if(current->right==NULL){
				current->right=temp;
				cout<<"Successfully Inserted"<<endl;
				break;
			}
			else{
				q.push(current->right);
			}
		}
	}
}
void Reverse_Levelorder_Traversal(node *root){
	queue <struct node*> q;
	stack <struct node*> s;
	q.push(root);
	node *temp=new node;
	temp->data=0;
	temp->isdelim=true;
	temp->left=NULL;
	temp->right=NULL;
	q.push(temp);
	while(!q.empty()){
		node *current;
		current=q.front();
		q.pop();
		if(current->isdelim==true){
			if(!q.empty()){
				q.push(current);
			}
		}
		s.push(current);
		if(current->right!=NULL){
			q.push(current->right);
		}
		if(current->left!=NULL){
			q.push(current->left);
		}
	}
	while(!s.empty()){
		node* value;
		value=s.top();
		s.pop();
		if(value->isdelim==true){
			cout<<endl;
		}
		else{
			cout<<value->data<<" ";
		}
	}
}
int main(){
	cout<<"Enter the total no. of nodes in Binary Tree:";
	int n;
	cin>>n;
	cout<<"Enter the node data:"<<endl;
	int value;
	int i=0; 
	while(i<n){
		cin>>value;
		Insert(value);
		i++;
	}
	Reverse_Levelorder_Traversal(root);
	return 0;
}
