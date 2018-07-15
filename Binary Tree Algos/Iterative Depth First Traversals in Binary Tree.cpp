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
void Inorder_Traversal(node *root){
	stack <struct node*> s;
	node *current;
	s.push(root);
	while(!s.empty()){
		if(s.top()!=NULL){
			current=s.top();
			s.push(current->left);
		}
		else{
			s.pop();
			if(s.empty()){
				break;
			}
			else{
			current=s.top();
			s.pop();
			cout<<current->data<<" ";
			s.push(current->right);
			}
		}
	}
}
void Preorder_Traversal(node *root){
	stack <struct node*> s;
	node *current;
	s.push(root);
	while(!s.empty()){
		if(s.top()!=NULL){
			current=s.top();
			cout<<current->data<<" ";
			s.push(current->left);
		}
		else{
			s.pop();
			if(s.empty()){
				break;
			}
			else{
			current=s.top();
			s.pop();
			s.push(current->right);
			}
		}
	}
}
void Postorder_Traversal(node *root){
	stack <struct node*> s1,s2;
	s1.push(root);
	while(!s1.empty()){
		node *current;
		current=s1.top();
		s1.pop();
		s2.push(current);
		if(current->left!=NULL){
			s1.push(current->left);
		}
		if(current->right!=NULL){
			s1.push(current->right);
		}
	}
	while(!s2.empty()){
		node *current;
		current=s2.top();
		s2.pop();
		cout<<current->data<<" ";
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
	cout<<"Inorder Traversal:";
	Inorder_Traversal(root);
	cout<<endl<<"Preorder Traversal:";
	Preorder_Traversal(root);
	cout<<endl<<"Postorder Traversal:";
	Postorder_Traversal(root);
	return 0;
}
