#include <iostream>

#include "bst.h"


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

    BST tree;
    
    tree.insert(10);
    tree.insert(16);
    tree.insert(8);
    tree.insert(6);
    tree.insert(4);
    tree.insert(17);
    tree.insert(5);
    tree.insert(7);
    
    if (tree.search(17))
    {
        std::cout << "Succeeded find element" << '\n';
    }
    else
    {
        std::cout << "Not succeeded searching element" << '\n';
    }

    return 0;
}
