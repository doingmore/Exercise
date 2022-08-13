#include "BST.h"

// ======================== Constructors ========================
BST::BST()
	: m_root{ NULL }
{}

BST::BST(const int& value)
{
	m_root = new Node{ value };
}

// ======================== Constructors ========================
// 
// ======================== Rule Of three - Copy CTR and assignemnt operator ========================
// = delete
BST::~BST()
{
	deallocateALL(m_root);
}
// ======================== Rule Of three - Copy CTR and assignemnt operator ========================
// 
// ======================== Move Semantics ========================
BST::BST(BST&& other)
{
	m_root = other.m_root;
	other.m_root = NULL;
}
BST& BST::operator= (BST&& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (this->m_root != NULL)
	{
		deallocateALL(this->m_root);
		m_root = NULL;
	}

	this->m_root = other.m_root;
	other.m_root = NULL;

	return *this;
}
// ======================== Move Semantics ========================




void BST::insert(const int& newVelue)
{
	if (m_root == NULL)
	{
		m_root = new Node{ newVelue };
	}
	else
	{
		insertNewNode(m_root, newVelue);
	}
}


void BST::insertNewNode(Node* node, const int& newVelue)
{
	if (node == NULL) // for stop and go back
	{
		return;
	}
	else if (node->getValue() == newVelue) // if already have that value terminate insertion go back
	{
		return;
	}

	if (node->getValue() < newVelue)
	{
		insertNewNode(node->getRight(), newVelue);
		if (node->getRight() == NULL)
		{
			Node* newNode = new Node{ newVelue };
			node->setRight(newNode);
		}
		// else go back
	}
	else
	{
		insertNewNode(node->getLeft(), newVelue);
		if (node->getLeft() == NULL)
		{
			Node* newNode = new Node{ newVelue };
			node->setLeft(newNode);
		}
		// else go back
	}
}

void BST::deallocateALL(Node* node) // post travel
{
	if (node == NULL)
	{
		return;
	}

	deallocateALL(node->getLeft());
	deallocateALL(node->getRight());
	delete node;
}

int BST::find(const int& number) const
{
	Node* returnresult = binarySearch(m_root,number);
	if (returnresult == NULL)
	{
		return -1;
	}
	return returnresult->getValue();
}

BST::Node* BST::binarySearch(Node* node, const int& key) const
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->getValue() == key)
	{
		return node;
	}
	else if (node->getValue() < key)
	{
		return binarySearch(node->getRight(),key);
	}
	else
	{
		return binarySearch(node->getLeft(), key);
	}

}

std::ostream& operator<< (std::ostream& stream,const BST& tree)
{
	// BreadthFirstSearch
	std::queue<BST::Node*> que;
	if (tree.m_root == NULL)
	{
		return stream;
	}

	que.push(tree.m_root);

	while (!que.empty())
	{
		stream << que.front()->getValue() << ' ';

		if (que.front()->getLeft() != NULL)
		{
			que.push(que.front()->getLeft());
		}
		if (que.front()->getRight() != NULL)
		{
			que.push(que.front()->getRight());
		}
		que.pop();
	}

	return stream;
}

bool BST::Node::haveNoChild()
{
	if ( this->getLeft() == NULL && this->getRight() == NULL )
	{
		return true;
	}
	return false;
}
bool BST::Node::haveOneChild()
{
	if (   (this->getLeft() != NULL && this->getRight() == NULL)
		|| (this->getLeft() == NULL && this->getRight() != NULL) )
	{
		return true;
	}
	return false;
}

BST::Node* BST::getParent(Node* node , Node* child)
{
	if (node == NULL) // for return back
	{
		return NULL;
	}

	if (node->getLeft() == child)
	{
		return node;
	}
	if (node->getRight() == child)
	{
		return node;
	}

	if (node->getValue() > child->getValue())
	{
		return getParent(node->getLeft(), child);
	}
	else
	{
		return getParent(node->getRight(), child);
	}
	return NULL;
}

void BST::remove(const int& deleteValue)
{
	Node* nodeForDelete = binarySearch(m_root, deleteValue);

	if ( nodeForDelete->haveNoChild() ) // first case delete leaf
	{
		if (m_root == nodeForDelete) // case when delete m_root with no children
		{
			delete m_root;
			m_root = NULL;
		}
		else
		{
			Node* parent = getParent(m_root,nodeForDelete);
			if (parent->getLeft() == nodeForDelete)
			{
				parent->setLeft(NULL);
			}
			else
			{
				parent->setRight(NULL);
			}
		}
	}
	else if (nodeForDelete->haveOneChild()) // second case delete node with one child
	{
		if (m_root == nodeForDelete) // case when delete m_root with one child
		{
			if (nodeForDelete->getLeft() == NULL)
			{
				m_root = nodeForDelete->getRight();
			}
			else
			{
				m_root = nodeForDelete->getLeft();
			}
		}
		else
		{
			Node* parent = getParent(m_root, nodeForDelete);

			if (parent->getLeft() == nodeForDelete) // nodeForDelete is left child
			{
				if (nodeForDelete->getLeft() == NULL) // have right child
				{
					parent->setLeft(nodeForDelete->getRight());
				}
				else // have left child
				{
					parent->setLeft(nodeForDelete->getLeft());
				}
			}
			else // nodeForDelete is right child
			{
				if (nodeForDelete->getLeft() == NULL) // have right child
				{
					parent->setRight(nodeForDelete->getRight());
				}
				else // have left child
				{
					parent->setRight(nodeForDelete->getLeft());
				}
			}
		}
	}
	else // third case delete node with two children
	{
		if (m_root == nodeForDelete)
		{
			int minValueRightSubT{getMin(m_root->getRight())};
			this->remove(minValueRightSubT); // can be only first case or second case !! 
			m_root->setValue(minValueRightSubT);
			nodeForDelete = NULL;
		}
		else
		{
			int minValueRightSubT{ getMin(nodeForDelete->getRight()) };

			this->remove(minValueRightSubT); // can be only first case or second case !! 

			nodeForDelete->setValue(minValueRightSubT);

			nodeForDelete = NULL;
		}
	}
	if (nodeForDelete != NULL) { delete nodeForDelete; }
}
int BST::getMin(Node* node) const
{
	if (node == NULL)
	{
		return -1 ;
	}

	if (node->getLeft() != NULL)
	{
		return getMin(node->getLeft());
	}
	else
	{
		return node->getValue();
	}
}
