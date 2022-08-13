#ifndef BST_H
#define BST_H
#include <queue>
#include <cstddef>
#include <iostream>

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
	int find(const int& number) const;
	friend std::ostream& operator<< (std::ostream& stream,const BST& tree);
	void remove(const int& deleteValue);

private:
	int getMin(Node* node) const;
	Node* getParent(Node* node, Node* child);
	void insertNewNode(Node* node, const int& newVelue);
	void deallocateALL(Node* node);
	Node* binarySearch(Node* node , const int& key) const;

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

		bool haveNoChild();
		bool haveOneChild();

	private:
		int m_value;
		Node* m_left;
		Node* m_right;
	};

	Node* m_root;

};


#endif //!BST_H6666
