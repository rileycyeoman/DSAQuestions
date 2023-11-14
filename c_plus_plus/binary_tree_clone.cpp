//Q: Given a binary tree with a parent and left and right node, clone the tree
//Method: Hashing

#include<iostream>
#include<unordered_map>
using namespace std;

//Struct to create node, will contain pointers to left and right node, as well as a pointer to
//a random node for purposes later
struct Node{
	int key;
	struct Node *left, *right, *random;
};
//Create helper function to allow us to create new nodes based on our hash key
Node* newNode(int key){
	Node* temp = new Node; //create node object
	temp-> key = key; //initializes node with given key
	temp->random = temp->right = temp->left = NULL; //empty child nodes
	return (temp); //return our temp node, parenthesis allow for easier referencing of our object address
}	
//Function for outputting our nodes inorder

void printInorder(Node* node){
	//empty tree case
	if (node == NULL)
		return;
	
	//Since this is a tree, this needs to be done recursively
	printInorder(node->left);
	
	cout << "Key: " << node->key << " - Value: ";
	if (node->random == NULL)
		cout<< "NULL.\n";
	else
		cout<<node->random->key << ".\n";
	printInorder(node->right);
}


//Function to copy keys as well as left and right nodes
Node* copyLeftRightNode(Node* treeNode, unordered_map<Node*, Node*> &mymap){
	//empty tree case
	if (treeNode == NULL)
		return NULL;
	Node* cloneNode = newNode(treeNode->key); //create copy of our node
	mymap[treeNode] = cloneNode; //map original node to new one
	cloneNode->left = copyLeftRightNode(treeNode->left, mymap); //go through left and right nodes to copy them as well
	cloneNode->right = copyLeftRightNode(treeNode->right, mymap);
	return cloneNode;
}
	
//Function to copy the random node in the tree by utilizing the hashmap
void copyRandom(Node* treeNode, unordered_map<Node *, Node *> &mymap){
	//empty tree case
	if (treeNode == NULL)
		return;
	mymap[treeNode]-> random = mymap[treeNode->random]; //Sets value of hashmap for random to value in the Tree Node
	copyRandom(treeNode->left, mymap); //go through left and right nodes
	copyRandom(treeNode->right, mymap);
}	

	
//Final function to copy tree
Node* cloneTree(Node* tree){
	//empty tree case
	if (tree == NULL)
		return NULL;
	unordered_map<Node*, Node*> mymap; //create map that takes and maps tree node to copy node
	Node* newTree = copyLeftRightNode(tree, mymap); 
	copyRandom(tree, mymap); 
	return newTree;
}


//Main program
int main(){
	
	//Test our copying 
	Node* tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
    	tree->left->right = newNode(5);
    	tree->random = tree->left->right;
    	tree->left->left->random = tree;
    	tree->left->right->random = tree->right;
	
	cout << "Inorder traversal of original binary tree is: \n";
    	printInorder(tree);
 
    	Node *clone = cloneTree(tree);
 
    	cout << "\n\nInorder traversal of cloned binary tree is: \n";
    	printInorder(clone);
	return 0;
}

