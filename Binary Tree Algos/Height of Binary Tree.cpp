#include<iostream>
#include<queue>
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
int Height(struct node *root){
	if(root==NULL){
		return 0;
	}
	int left=Height(root->left);
	int right=Height(root->right);
	return 1+max(left,right);
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
	cout<<"Height of the Binary Tree is:"<<Height(root);
	return 0;
}
