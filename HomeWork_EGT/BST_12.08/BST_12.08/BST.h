#ifndef BST_H
#define BST_H

#include <cstddef>

class BST final
{
	class Node;
public:
	BST();
	BST(const int& value);

	//
	BST(const BST& other) {}
	BST& operator= (const BST& other) {}
	~BST() {}
	//
	//
	BST(BST&& other) {}
	BST& operator= (BST&& other) {}
	//

	void insert(const int& newVelue)
	{
		if (m_root==NULL)
		{
			m_root = new Node{ newVelue };
		}
		else
		{
			insertNewNode(m_root, newVelue);
		}
	}


private:
	void insertNewNode(Node* node,const int& newVelue)
	{
		if (node == NULL) // for stop and go back
		{
			return;
		}
		else if (node->getValue() == newVelue) // if already have that value terminate insertion
		{
			return;
		}

		if (node->getValue() < newVelue)
		{
			insertNewNode(node->getRight(), newVelue);
			if (node->getRight() == NULL )
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

	class Node
	{
	public:
		Node(const int& value)
			: m_value{ value }
		{
			m_left = NULL;
			m_right = NULL;
		}
		void setValue(const int& newValue) { m_value = newValue; }
		int getValue() const { return m_value; }

		void setLeft(Node* newLeft) { m_left = newLeft; }
		Node* getLeft() const { return m_left; }

		void setRight(Node* newRight) { m_right = newRight; }
		Node* getRight() const { return m_right;}

	private:
		int m_value;
		Node* m_left;
		Node* m_right;
	};

	Node* m_root;

};


#endif //!BST_H