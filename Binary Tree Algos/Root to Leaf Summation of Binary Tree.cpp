#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector <int> v;
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
bool Summation(struct node*root,int value){
	if(root==NULL){
		return false;
	}
	if(root->left==NULL && root->right==NULL && root->data==value){
		return true;
	}
	else{
		return false;
	}
	value=value-root->data;
	Summation(root->left,value);
	Summation(root->right,value);
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
	int data;
	cout<<"Given Summation:";
	cin>>data;
	bool result=Summation(root,data);
	if(result){
		cout<<"Possible path is:"<<endl;
	}
	else{
		cout<<"Not Possible"<<endl;
	}
	return 0;
}
