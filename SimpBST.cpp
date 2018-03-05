//Lab 3 Simple BST......wont get more simple than this
//Andrew Jordan

//Still working on the Iterator and Inorder list

#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

struct BstNode{
	int data;
	struct BstNode *left;
	struct BstNode *right;
	struct BstNode *parent;

};


BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right =NULL;
	return newNode;

}

BstNode* Insert(BstNode* root, int data){
	if(root == NULL){ //empty tree
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = Insert(root->left,data);
	}

	else {
		root->right = Insert(root->right,data);		
	}
	return root;

}

bool member(BstNode* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if (data <= root->data) return member(root->left, data);
	else return member(root->right, data);
}

bool empty(BstNode* root){
	if(root == NULL) return true;
	else return false;
}

int FindMin(BstNode* root){
	if(root == NULL){
		cout << "Tree is empty bra\n";
		return -1;
	}
	else if(root->left == NULL){
		return root->data;
	}
	return FindMin(root->left);
}

struct BstNode* FindMinNode(BstNode* root){
	if(root == NULL){
		cout << "Tree is empty bra\n";
		return root;
	}
	else if(root->left == NULL){
		return root;
	}
	return FindMinNode(root);
}

int FindMax(BstNode* root){
	if(root == NULL){
		cout << "Tree be empty bra\n";
		return -1;	
	}
	else if(root->right == NULL){
		return root->data;
	}
	return FindMax(root->right);
}

struct BstNode* Delete(struct BstNode *root, int data)
{
	if (root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else // Target aquired
	{
		//Case 1: No children....DOA

		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}

		//Case 2: One Child....We will need to relink the node

		else if(root->left == NULL){
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}

		//Case 3: Two children....

		else {
			struct BstNode *temp = FindMinNode(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

int height(struct BstNode* root){

	if(root == NULL)
		return -1;
	else if (height(root->left) > height(root->right))
		return height(root->left) +1;
	else return height(root->right) +1;
}

std::list<int> inOrder(struct BstNode* root){

	std::list<int> listbro;

	if(root == NULL)
		return listbro;

	//First Recursive call to left child
	inOrder(root->left);
	listbro.push_back(root->data);
	inOrder(root->right);

	return listbro;

}
//So my list is being weird so here is a straight print function

void printInOrder(struct BstNode* root){

	if(root == NULL)
		return;
	printInOrder(root->left);
	cout << root->data << " ";

	printInOrder(root->right);
}






int main () {
	BstNode * groot = NULL; //Create empty tree named groot

	cout << empty(groot) << "\n";

	groot = Insert(groot, 15);

	cout << empty(groot) << "\n";


	int number = 15;

	if (member(groot, number) == true) cout << "Found: " << number << "\n";
	else cout << "Sum ting wong \n";

	groot = Insert(groot, 23);
	groot = Insert(groot, 18);

	for(int i = 0; i < 10; i++){
		groot = Insert(groot, i);
			if (member(groot, i) == true) cout << "Found: " << i << "\n";
			else cout << "Sum ting wong \n";
	}

	groot = Delete(groot,4);
	if (member(groot, 4) == true) cout << "Found: " << 4 << "\n";
	else cout << "Delete Successful \n";

	groot = Delete(groot,3);
	if (member(groot, 3) == true) cout << "Found: " << 3 << "\n";
	else cout << "Delete Successful \n";

	for(int i = 0; i < 10; i++){
		if (member(groot, i) == true) cout << "Found: " << i << "\n";
		else cout << "Something wrong \n";
	}

	cout << "The Max of groot is: " << FindMax(groot) << "\n";
	cout << "The Min of groot is: " << FindMin(groot) << "\n";

	cout << "The height of groot is: " << height(groot) << "\n";

	for(auto v : inOrder(groot))
		cout << v << "\n";

	printInOrder(groot);


	return 0;

}	