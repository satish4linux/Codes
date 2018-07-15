#include<iostream>
#include<queue>
#define MIN -1e5
#define MAX 1e5
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
void Insert(int value){
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
}
bool isBST(node *temp,int min,int max){
	if(temp==NULL){
		return true;
	}
	if(temp->data<max && temp->data>=min){
		return true;
	}
	else{
		return false;
	}
	return isBST(temp->left,min,temp->data) && isBST(temp->right,temp->data,max);
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
	bool result;
	result=isBST(root,MIN,MAX);
	if(result){
		cout<<"This Binary Tree is a BST"<<endl;
	}
	else{
		cout<<"Not a BST"<<endl;
	}
	return 0;
}
