#include<iostream>
#include<queue>
using namespace std;
struct node{
	unsigned int data;
	node *left;
	node *right;
};
class BST{
	public:
	node *root=NULL;
	public:
	void Initiate(int value){
		if(root==NULL){
			node *temp=new node;
			temp->data=value;
			temp->left=NULL;
			temp->right=NULL;
			root=temp;
			cout<<"Tree is initiated."<<endl;
		}
		else{
			cout<<"Tree is already initiated."<<endl;
		}
	}
	void Insertion(int value){
		if(root==NULL){
			node *temp=new node;
			temp->data=value;
			temp->left=NULL;
			temp->right=NULL;
			root=temp;
			cout<<"Tree is initiated."<<endl;
		}
		else{
			node *current, *parent;
			current=root;
			while(current!=NULL){
				parent=current;
				if(current->data<=value){
					current=current->right;
				}
				else{
					current=current->left;
				}
			}
			node *temp=new node;
			temp->data=value;
			temp->left=NULL;
			temp->right=NULL;
			if(parent->data<=value){
				parent->right=temp;
			}
			else{
				parent->left=temp;
			}
			cout<<"Data Successfully Inserted."<<endl;
		}
	}
	void Search(int value){
		if(root==NULL){
			cout<<"BST is empty"<<endl;
		}
		else{
			node *current;
			bool flag=false;
			current=root;
			while(current!=NULL){
				if(current->data==value){
					cout<<"Data found in BST"<<endl;
					flag=true;
					break;
				}
				else{
					if(current->data<value){
						current=current->right;
					}
					else{
						current=current->left;
					}
				}
			}
			if(flag==false){
				cout<<"Data not found"<<endl;
			}
		}
	}
	void Inorder_Traversal(node *root){
		node *current;
		current=root;
		if(current==NULL){
			return;
		}
		Inorder_Traversal(current->left);
		cout<<current->data<<" ";
		Inorder_Traversal(current->right);
	}
	void Preorder_Traversal(node *root){
		node *current;
		current=root;
		if(current==NULL){
			return;
		}
		cout<<current->data<<" ";
		Preorder_Traversal(current->left);
		Preorder_Traversal(current->right);
	}
	void Postorder_Traversal(node *root){
		node *current;
		current=root;
		if(current==NULL){
			return;
		}
		Postorder_Traversal(current->left);
		Postorder_Traversal(current->right);
		cout<<current->data<<" ";
	}
	void Levelorder_Traversal(node *root){
		if(root==NULL){
			cout<<"BST is empty"<<endl;
		}
		else{
			queue <struct node*> q;
			q.push(root);
			while(!q.empty()){
				node *temp;
				temp=q.front();
				q.pop();
				cout<<temp->data<<" ";
				if(temp->left!=NULL){
					q.push(temp->left);
				}
				if(temp->right!=NULL){
					q.push(temp->right);
				}
			}
		}
	}
	void Delete(int value){
		node *temp;
		temp=root;
		
	}
};
int main(){
	BST obj;
	cout<<"Binary Search Tree:"<<endl;
	while(1){
	cout<<"Choose one option:"<<endl;
	cout<<"1. Initiate the tree."<<endl;
	cout<<"2. Insert a node"<<endl;
	cout<<"3. Delete a node"<<endl;
	cout<<"4. Search an element in BST"<<endl;
	cout<<"5. Inorder Traversal"<<endl;
	cout<<"6. Preorder Traversal"<<endl;
	cout<<"7. Postorder Traversal"<<endl;
	cout<<"8. Levelorder Traversal"<<endl;
	cout<<"9. Exit"<<endl;
	cout<<"Enter choice:";
	int ch,flag=0;
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter the element:";
			int value;
			cin>>value;
			obj.Initiate(value);
			break;
		case 2:
			cout<<"Enter the element:";
			int val;
			cin>>val;
			obj.Insertion(val);
			break;
		case 3:
			cout<<"Enter the element:";
			int b;
			cin>>b;
			obj.Delete(b);
			break;
		case 4:
			cout<<"Enter the element:";
			int a;
			cin>>a;
			obj.Search(a);
			break;
		case 5:
			obj.Inorder_Traversal(obj.root);
			break;
		case 6:
			obj.Preorder_Traversal(obj.root);
			break;
		case 7:
			obj.Postorder_Traversal(obj.root);
			break;
		case 8:
			obj.Levelorder_Traversal(obj.root);
			break;
		case 9:
			flag=1;
			break;
	}
	if(flag==1){
		break;
	}
	}
	return 0;

}
