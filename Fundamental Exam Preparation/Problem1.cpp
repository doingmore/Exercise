#include <iostream>
#include <set>

using namespace std;

/*
Write a program, use arrays that for given numbers inputed in the array, sorts them in DESCENDING Order.
WARNING: The numbers should NOT be repeated, the numbers should be ONLY POSITIVE
WARNING: DO NOT USE std::sort !
*/

void Problem1()
{
	int countNumbers{ 0 };
	cin >> countNumbers;
	int inputNumber{ 0 };
	set<int> myList;

	while (countNumbers--)
	{
		cin >> inputNumber;
		myList.insert(inputNumber);
	}

	set<int>::iterator it = myList.end();
	it--;
	for (unsigned int i = 0; i < myList.size(); i++)
	{
		cout << *it << " ";

		if (it==myList.begin())
		{
			break;
		}
		else
		{
		it--;
		}
	}
}
	
