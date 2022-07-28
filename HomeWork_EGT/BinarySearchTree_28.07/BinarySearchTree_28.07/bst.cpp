#include "bst.h"


BST::BST(const int& rootValue)
{
	root = new Node{ rootValue };
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{

}



void BST::insert(const int& key)
{
	if (root == NULL)
	{
		root = new Node{ key };
		return; // can I stop function like that ?? 
	}

	createNewNode(root, key);

}