#include <iostream>

#include "Stack.h"





int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Stack stack;

	for (int i = 0; i < 10; i++)
	{
		stack.push(i+1);
		std::cout <<i+1<<"th Push : "<< i + 1 << '\n';
	}

	Stack assignment;


	assignment.swap(stack);

	for (int i = 0; i < 10; i++)
	{
		std::cout << " Top : "<< assignment.top() << '\n';
		assignment.pop();
	}


    return 0;
}
