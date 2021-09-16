#include <iostream>
#include <sstream>

using namespace std;


int main()
{
	string number;

	int sumPrime{ 0 };
	int sumNonprime{ 0 };
	bool flag = false;
	bool prime = true;

	for (int i = 0; i < 1; )
	{
		cin >> number;

		if (number == "end")
		{
			flag = true;
		}
		if (flag)
		{
			break;
		}

		int digit = stoi(number);

		for (int j = 2; j < digit; j++)
		{
			prime = true;
			if (digit % j == 0)
			{
				cout << "nonprime" << '\n';
				sumNonprime = sumNonprime + digit;
				prime = false;
				break;
			}

		}
		if (prime)
		{
			cout << "prime" << '\n';
			sumPrime=sumPrime + digit;
		}
		
	}
	cout << "sum of all prime number is: " << sumPrime << '\n' << "sum of all nonprime numbers is: " << sumNonprime << '\n';

	
return 0;
}