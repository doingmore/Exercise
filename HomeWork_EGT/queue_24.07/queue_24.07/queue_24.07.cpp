#include <iostream>

#include "Queue.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
    Queue queue;

	for (size_t i = 0; i < 5; i++)
	{
		queue.push(i+1);
	}

	Queue copy;
	copy = queue;

	for (size_t i = 0; i < 5; i++)
	{
		queue.push(i + 6);
	}

	copy.swap(queue);

	size_t max{ copy.size() };
	for (size_t i = 0; i < max; i++)
	{
		std::cout << copy.front() << " ";
		copy.pop();
	}


    return 0;
}
