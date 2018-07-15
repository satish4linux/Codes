#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* Insert(int value, struct node *root){
	node *temp=new node;
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
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
	return root;
}
int Summation(struct node *root){
	if(root==NULL){
		return 0;
	}
	return root->data+Summation(root->left)+Summation(root->right);
}
int main(){
	struct node *root=NULL;
	cout<<"Enter the no. of nodes in Binary Tree:";
	int n;
	cin>>n;
	cout<<"Enter the node data:"<<endl;
	int value;
	int i=0; 
	while(i<n){
		cin>>value;
		root=Insert(value,root);
		i++;
	}
	int result=Summation(root);
	cout<<"Root to Leaf Summation of Tree is:"<<result<<endl;
	return 0;
}
