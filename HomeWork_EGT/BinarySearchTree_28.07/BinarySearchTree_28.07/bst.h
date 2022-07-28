#ifndef BST_H
#define BST_H

#include <string>

class BST
{
	class Node;
public:
	BST(const int& rootValue);
	BST();
	//
	BST(const BST& other) = delete;
	BST& operator= (const BST& other) = delete;
	~BST();
	//
	void insert(const int& key);

private:

	void createNewNode( Node* node , const int& key)
	{
		// if we already have that key 
		if (node->getKey() == key ) // do nothing , terminate insertion operation
		{
			return;
		}

		if (node->getLeft() == NULL && node->getRight() == NULL)
		{
			Node* temp = new Node{ key };
			node->setLeft(temp);
		}
		else
		{
			if (node->getLeft() == NULL) // that node have only right child
			{

			}
			else if (node->getRight() == NULL) // that node have only left child
			{

			}
			else // that node have two children
			{
				if (key > node->getKey())
				{
					createNewNode(node->getRight(), key);
				}
				else
				{
					createNewNode(node->getLeft(), key);
				}
			}
		}

	}

	class Node
	{
	public:
		void setLeft(Node* node) { m_left = node; }
		void setRight(Node* node) { m_right = node; }

		Node* getLeft() { return m_left; }
		Node* getRight() { return m_right; }

		int& getKey() { return m_key; }

		Node(const int& value) : m_key{ value }
		{
			m_left = NULL;
			m_right = NULL;
		}
	private:
		int m_key;
		Node* m_left;
		Node* m_right;
	};


	Node* root;
};


#endif // !BST_H
