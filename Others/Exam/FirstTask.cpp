#include <iostream>

int main()
{
	unsigned int a{0};
	std::cin>>a;

	for (int i = 1; i <= a; i++)
	{
        if (a % i == 0)
		{
            std::cout <<" " << i;
		}
	}

	return 0;
}
