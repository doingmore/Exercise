#include <iostream>


#include "LinkedList.h"  



void otherScope(LinkedList copy)
{
	LinkedList otherCopy;

	otherCopy = copy;

} 


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

    // we can also do that instantiate first element-head     LinkedList list{45};
    LinkedList list;

	for (int i = 0; i < 10; i++)
	{
		list.add(i+1);
	}
	list.print();
	LinkedList copy;
	copy = list;
	copy.insert_after_element(5,15);
	copy.print();
	copy.erase();
	return 0;
}
