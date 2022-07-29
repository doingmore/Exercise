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


private:
	void createNewNode(Node* node, const int& key);
	void erase(Node* node);

	bool binary_search(Node* node, const int& element);
	bool DFS_search(Node* node, const int& element);
	bool BFS_search(Node* node, const int& element,std::queue<Node*>& q);

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
