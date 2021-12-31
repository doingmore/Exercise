#include <iostream>
using namespace std;

int add(int x, int y)
{
		return x - y; // function is supposed to add, but it doesn't
}

int main()
{
 cout << add(5, 3); // should produce 8, but produces 2
	return 0;
}