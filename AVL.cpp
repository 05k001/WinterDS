// Avl Tree Implimentation and test

#include<stdio.h>
#include<stdlib.h>

//AVL tree node 

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
		};

//Utility function to get the height of the tree

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height; 
}

//Get the max of two ints
int max(int a, int b)
{
	return(a > b)? a : b;
}

// Allocate a new node with a given size (key)
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
					malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

//A right rotation function
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	//rotate 
	x->right = y;
	y->left =T2;

	//Update height

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;	
}


//A left rotate function
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	//perform rotation
	y->left = x;
	x->right = T2;

	//Update heights

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	//return new rootz

	return y;
}
	//Idk why but here is a function to get the balance factor of a node. Like I see its usefulness but....w/e

	int getBalance(struct Node *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left)-height(N->right);
	}

//Recursive Function to insert keys into AVL tree

	struct Node* insert(struct Node* node, int key)
{
	//Perform a BST insertion
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // They are equal
		return node;

	//Update the height of the ancestor node

	node->height = 1 + max(height(node->left),height(node->right));

	//Get the balance factor to check if unblaneced or not

	int balance = getBalance(node);

	//if its unbalanced then there are 4 possible outcomes

	//left left case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	//Right Right
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	//Left Right case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	//Right Left

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	//Return the node pointer
	return node;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}

	}
int main()
{
	//Lets test the program with some random data. First we make a node
	struct Node *root = NULL;

	root = insert(root,10);
	root = insert(root, 20);
  	root = insert(root, 30);
  	root = insert(root, 40);
  	root = insert(root, 50);
  	root = insert(root, 25);
  	root = insert(root, 26);
  	root = insert(root, 29);

  	printf("Preorder traversal of the constructed tree is \n");

  	preOrder(root);

  	return 0;
}




