#include <iostream>


int main()
{
	int a{ 0 }, b{ 0 };
	std::cin >> a >> b;

	int andOperator{ a & b };
	int result{ 0 };
	if (andOperator)
	{
		while (andOperator)
		{
			a = (a ^ b);   // new a 
			b = (andOperator << 1);  // new b
			andOperator = (a & b); // new & 
		}
		result = (a ^ b);
	}
	else
	{
		result = (a ^ b);          // if first & operation return 0 that mean my answer is XOR operator and no necessary << 
	}

	return 0;
}
