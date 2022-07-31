#include <iostream>

#include "bst.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

    BST tree;
    
    tree.insert(60);
    tree.insert(50);
    tree.insert(70);
    tree.insert(65);
    tree.insert(80);
    tree.insert(40);
    tree.insert(75);
    tree.insert(55);
    tree.insert(63);
    tree.insert(68);
    tree.insert(90);
    tree.insert(30);
    tree.insert(45);
    tree.insert(53);
    tree.insert(58);
    
    tree.deleteElement(60);
    
    if (tree.search(58))
    {
        std::cout << "Succeeded find element" << '\n';
    }
    else
    {
        std::cout << "Not succeeded searching element" << '\n';
    }

    return 0;
}
