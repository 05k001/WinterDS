#include"AvlTree.h"

int main()
{
	AvlTree<int> Tree;
	Tree.insert(10);
	//Tree.printTree();
	Tree.insert(20);
	Tree.insert(25);
	Tree.insert(45);
	Tree.insert(5);
	Tree.insert(21);
	Tree.insert(44);
	Tree.printTree();
	cout << Tree.findMin() << "\n";
	cout << Tree.findMax() << "\n";
	Tree.remove(5);
	Tree.remove(45);
	Tree.printTree();
	cout << Tree.findMin() << "\n";
	cout << Tree.findMax() << "\n";
	return 0;
}