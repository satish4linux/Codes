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
bool isSame(node *root_1, node *root_2){
	if(root_1==NULL && root_2==NULL){
		return true;
	}
	if(root_1==NULL || root_2==NULL){
		return false;
	}
	return root_1->data==root_2->data && isSame(root_1->left,root_2->left) && isSame(root_1->right,root_2->right);
}
int main(){
	struct node *root_1=NULL;
	struct node *root_2=NULL;
	cout<<"Enter the no. of nodes in First Binary Tree:";
	int n;
	cin>>n;
	cout<<"Enter the node data:"<<endl;
	int value;
	int i=0; 
	while(i<n){
		cin>>value;
		root_1=Insert(value,root_1);
		i++;
	}
	cout<<"Enter the no. of nodes in Second Binary Tree:";
	cin>>n;
	cout<<"Enter the node data:"<<endl;
	int j=0;
	while(j<n){
		cin>>value;
		root_2=Insert(value,root_2);
		j++;
	}
	bool result=isSame(root_1,root_2);
	if(result){
		cout<<"Same Trees"<<endl;
	}
	else{
		cout<<"Not Same Trees"<<endl;
	}
	return 0;
}
