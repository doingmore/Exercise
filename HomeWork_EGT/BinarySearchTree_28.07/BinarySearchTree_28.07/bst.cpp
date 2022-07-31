#include "bst.h"
#include <queue>
#include <iostream>

//
// ==================================================== Class Node =================================================
// start

bool BST::Node::isHaveNoChildren()
{
	if (this->getLeft() == NULL && this->getRight() == NULL)
	{
		return true;
	}
	return false;
}

bool BST::Node::oneChild()
{
	if ( (this->getLeft() == NULL && this->getRight() != NULL) || 
		 (this->getLeft() != NULL && this->getRight() == NULL) )
	{
		return true;
	}
	return false;
}

// end
// ==================================================== Class Node =================================================
//
// 
// ==================================================== Class BST ==================================================
// start

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
		return; 
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
	
	// return DFS_search(Node* node, const int& element);

	std::queue<Node*> q;
	return BFS_search(root, element,q);
}
BST::Node* BST::binary_search(Node* node, const int& element)
{
	if (node->getKey() == element)
	{
		return node;
	}

	if (element < node->getKey() )
	{
		return binary_search(node->getLeft(), element);
	}
	else
	{
		return binary_search(node->getRight(), element);
	}

	return NULL;
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

	return (DFS_search(node->getLeft(), element) ||
		DFS_search(node->getRight(), element));
}

BST::Node* BST::getParent(Node* parent, Node* node)
{
	if (parent == NULL)
	{
		return NULL; // for recursion
	}
	else if (parent == node)
	{
		return NULL;
	}
	else if(parent->getLeft() == node)
	{
		return parent;
	}
	else if (parent->getRight() == node)
	{
		return parent;
	}
	else if (node->getKey() < parent->getKey())
	{
		return getParent(parent->getLeft() , node);
	}
	else 
	{
		return getParent(parent->getRight(), node);
	}
	return NULL;
}

BST::Node* BST::getMinElement(Node* startNode)
{
	if (startNode->getLeft() != NULL)
	{
		return getMinElement(startNode->getLeft());
	}
	else
	{
		return startNode;
	}
}

void BST::deleteElement(const int& element)
{
	Node* nodeForDel= binary_search(root,element);
	if (nodeForDel == NULL)
	{
		// that element is not at that tree and do nothing
		return;
	}

	if ( nodeForDel->isHaveNoChildren() ) // case 1 - no have children that mean that node is leaf
	{
		Node* parent = getParent(root, nodeForDel);
		
		if (parent == NULL) // if parent is NULL here ( no parent and no children ), that mean my node for delete is  the root ( for  tree ) 
		{
			root = NULL;
		}
		else if (parent->getLeft() == nodeForDel) // left child on parent
		{
			parent->setLeft(NULL);
		}
		else // right child
		{
			parent->setRight(NULL);
		}
	}
	else if ( nodeForDel->oneChild() ) // case 2 - with one child
	{
		Node* parent = getParent(root,nodeForDel);
		if (parent == NULL) // if parent is NULL here ( no parent ), but have one child that mean nodeForDelete is root and his child will become root on tree
		{
			if (nodeForDel->getLeft() == NULL) // have right child
			{
				root=nodeForDel->getRight();
			}
			else // have left child
			{
				root=nodeForDel->getLeft();
			}
		}
		else if (parent->getLeft() == nodeForDel) // work with left child on parent
		{
			if (nodeForDel->getLeft() == NULL) // have right child
			{
				parent->setLeft( nodeForDel->getRight() );
			}
			else // have left child
			{
				parent->setLeft(nodeForDel->getLeft());
			}
		}
		else // here work with parent right child
		{
			if (nodeForDel->getLeft() == NULL) // have right child
			{
				parent->setRight(nodeForDel->getRight());
			}
			else // have left child
			{
				parent->setRight(nodeForDel->getLeft());
			}
		}
	}
	else // case 3 - with two child
	{
		// quick recap key elements of this case
		// most small element at binary search tree( or subtree ) is a node( with no children or one right children )
		// when we delete element with two children we must replace his position with most small element from RIGHT subtree
		// that case will use recursion to first or second case( delete node with no children and delete node with one children ) 
		Node* minElement = getMinElement(nodeForDel->getRight()); // get minimum element from RIGHT subtree ! 
		Node* parent = getParent(root,nodeForDel);

		Node* newElement = new Node{ minElement->getKey() }; // get data from min Element
		
		this->deleteElement(minElement->getKey()); // delete min element 
		minElement = NULL;
		
		newElement->setLeft(nodeForDel->getLeft());
		newElement->setRight(nodeForDel->getRight());

		if (parent == NULL ) // case when delete element is root for tree
		{
			root = newElement;
		}
		else if (parent->getLeft() == nodeForDel)
		{
			parent->setLeft(newElement);
		}
		else
		{
			parent->setRight(newElement);
		}
	}
	delete nodeForDel;
}

// end
// ==================================================== Class BST =================================================
// 
