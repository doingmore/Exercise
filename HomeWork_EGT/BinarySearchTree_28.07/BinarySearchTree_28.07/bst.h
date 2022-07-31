#ifndef BST_H
#define BST_H

#include <string>
#include <queue>
#include <iostream>

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
	bool search(const int& element);
	void deleteElement(const int& element);

private:
	void createNewNode(Node* node, const int& key);
	void erase(Node* node);
	Node* binary_search(Node* node, const int& element);
	bool BFS_search(Node* node, const int& element,std::queue<Node*>& q);
	bool DFS_search(Node* node, const int& element);  // return pointer to specific Node use in function delete 
	Node* getParent(Node* parent, Node* node);
	Node* getMinElement(Node* startNode);

	class Node
	{
	public:
		void setLeft(Node* node) { m_left = node; }
		void setRight(Node* node) { m_right = node; }
		bool isHaveNoChildren();
		bool oneChild();
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
