#include <iostream>

#include "Queue.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
    Queue queue;

	for (size_t i = 0; i < 1; i++)
	{
		queue.push(i+1);
	}

	queue.rotation();

	size_t max{ queue.size() };
	for (size_t i = 0; i < 1; i++)
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}


    return 0;
}
