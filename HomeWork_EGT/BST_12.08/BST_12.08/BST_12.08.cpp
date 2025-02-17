#include <iostream>

#include "BST.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

	BST tree{};
	tree.insert(60);
	tree.insert(30);
	tree.insert(90);
	tree.insert(15);
	tree.insert(45);
	tree.insert(10);
	tree.insert(20);
	tree.insert(20);
	tree.insert(35);
	tree.insert(50);
	tree.insert(80);
	tree.insert(100);
	tree.insert(70);
	tree.insert(85);
	tree.insert(95);
	tree.insert(110);

	BST copy{ std::move(tree) };


	return 0;
}
