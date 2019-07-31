#include <iostream>

using namespace std;

enum traversal_t { inorder, preorder, postorder};

struct Node{
	int data;
	Node* left;
	Node* right;
	//constructor
	Node(int val): data(val), left(NULL), right(NULL) {}
};

class BST{
	private:
		Node* treeRoot;
		Node* insert(Node* root, int data);
		void postorder_trav(Node* root);
		void inorder_trav(Node* root);
		void preorder_trav(Node* root);
	public:
		//constructor 
		BST(){
			treeRoot = NULL;
		}

		void insert(int data);		
		void print(traversal_t val);
	
		Node* getRoot() {
			return treeRoot;
		}
		
};

void BST::insert(int data){
	if(treeRoot == NULL){
		treeRoot = new Node(data);
	}
	else{
		this->insert(treeRoot, data);
	} 
}

Node* BST::insert(Node* root, int data){

	if(root == NULL){
		root = new Node(data);
	}
	else if(data <= root->data){
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}	
	return root;
}

void BST::print(traversal_t val){
	
	switch(val) {
		case inorder:
			cout << "printing inorder" << endl;
			inorder_trav(treeRoot);
			cout << endl;
		break;
		case preorder: 
			cout << "printing preorder" << endl;
			preorder_trav(treeRoot);
			cout << endl;
			break;
		case postorder:
			cout << "printing postorder" << endl;
			postorder_trav(treeRoot);
			cout << endl;
			break;
	}	

} 

void BST::postorder_trav(Node* root){
	if(root == NULL)
		return;

	postorder_trav(root->left);
	postorder_trav(root->right);
	cout << root->data << " ";
}

void BST::inorder_trav(Node* root){
	if(root == NULL)
		return;	

	inorder_trav(root->left);
	cout << root->data << " ";
	inorder_trav(root->right);
}

void BST::preorder_trav(Node* root){
	if (root == NULL)
		return;
	
	cout << root->data << " ";
	preorder_trav(root->left);
	preorder_trav(root->right);
}




int main(){
	
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(1);
	tree.insert(15);
	
	tree.print(postorder);
	tree.print(preorder);
	tree.print(inorder);
}	
