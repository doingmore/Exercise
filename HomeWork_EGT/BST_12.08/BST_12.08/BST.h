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
	BST(const BST& other) = delete;
	BST& operator= (const BST& other) = delete;
	~BST();
	//
	//
	BST(BST&& other);
	BST& operator= (BST&& other);
	//

	void insert(const int& newVelue);


private:
	void insertNewNode(Node* node, const int& newVelue);
	void deallocateALL(Node* node);


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
		Node* getRight() const { return m_right; }

	private:
		int m_value;
		Node* m_left;
		Node* m_right;
	};

	Node* m_root;

};


#endif //!BST_H6666
