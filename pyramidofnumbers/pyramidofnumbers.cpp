#include <iostream>
using namespace std;

int main()
{
	int number{ 0 };
	cin >> number;
	
	int curentNumber{ 0 };
	bool flag = false;

	for (int rows = 1 ; rows < number ; rows++)
	{
		for (int colum = 1; colum < number; colum++)
		{
			if (curentNumber >= number)
			{
				flag = true;
				break;
			}

			curentNumber++;
			cout << curentNumber << " ";

			if (colum==rows)
			{
				break;
			}

		}

		if (flag)
		{
			break;
		}
		cout<<'\n';
	}

	return 0;
}