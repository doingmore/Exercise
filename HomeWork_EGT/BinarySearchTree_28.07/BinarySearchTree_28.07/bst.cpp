#include "bst.h"
#include <queue>
#include <iostream>

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
	if (root) // if root bind to NULL, NULL return false if delete NUll I will get error
	{  // no need set pointers to NULL, after delete;
		erase(root);
	}
}
void BST::insert(const int& key)
{
	if (root == NULL)
	{
		root = new Node{ key };
		return; // if else or just interrupt function here
	}
	createNewNode(root, key);
}
void BST::createNewNode(Node* node, const int& key) // the control path has only one option 
{
	// if we already have that key
	if (node->getKey() == key) // do nothing , terminate insertion operation
	{
		return;
	}
	else if (node->getKey() > key) // first check direction
	{
		if (node->getLeft() == NULL) // second check for child if do not have a child just create, or go on position at that child
		{
			node->setLeft(new Node{ key });
			return;   // again if else or just interrupt function here
		}
		createNewNode(node->getLeft(), key);
	}
	else
	{
		if (node->getRight() == NULL)
		{
			node->setRight(new Node{ key });
			return;
		}
		createNewNode(node->getRight(), key);
	}
}
void BST::erase(Node* node) // BFS => standart postorder traversal
{
	if (node == NULL)
	{
		return;
	}
	erase(node->getLeft());
	erase(node->getRight());
	delete node;
}

bool BST::search(const int& element)
{
	if (root == NULL)
	{
		return false;
	}
	
	
	// return binary_search(root, element); // most power for BST ! ready

	// return DFS_search(root, element); // ready
	std::queue<Node*> q;
	return BFS_search(root, element,q);
}

bool BST::binary_search(Node* node, const int& element)
{
	if (node->getKey() == element)
	{
		return true;
	}

	if (element < node->getKey() )
	{
		return binary_search(node->getLeft(), element);
	}
	else
	{
		return binary_search(node->getRight(), element);
	}
}

bool BST::DFS_search(Node* node, const int& element)
{
	if (node == NULL)
	{
		return false;
	}
	if (node->getKey() == element)
	{
		return true;
	}

	return ( DFS_search(node->getLeft(), element) ||
		DFS_search(node->getRight(), element));
}

bool BST::BFS_search(Node* node, const int& element, std::queue<Node*>& q)
{
	q.push(node); // start with push root

	while (!q.empty())
	{
		if (q.front()->getKey() == element)
		{
			return true;
		}
		else
		{
			std::cout << "Node " << q.front()->getKey() << " have been checked" << '\n';

			if (q.front()->getLeft())
			{
				q.push(q.front()->getLeft());
			}
			if (q.front()->getRight())
			{
				q.push(q.front()->getRight());
			}
			q.pop();
		}
	}
	return false;
}
