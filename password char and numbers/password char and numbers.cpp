#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Write a program that reads two integers n and l entered by the user and generates in alphabetical order
symbol 1: number from 1 to n.
symbol 2: number from 1 to n.
symbol 3: lowercase letter among the first l letters of the Latin alphabet.
symbol 4: lowercase letter among the first l letters of the Latin alphabet.
symbol 5: number from 1 to n, bigger than first two symbols.
*/

int main()
{
	int n{ 0 }, l{ 0 };
	cin >>n >> l;

	char charThird = 'a';
	char charFourth = 'a';

	for (int a = 1; a < n; a++)
	{
		for (int b = 1; b < n; b++)
		{		
			for (int c = 'a'; c < 'a'+l; c++)
			{
				
				for (int d = 'a'; d < 'a'+l; d++)
				{
					int maxnum = max(a, b);	

					for (int e = maxnum + 1 ; e <= n ; e++ )
					{
						cout << a << b << (char)c << (char)d << e << " ";
					}
				
				}
				
			}
			
		}

	}
	
	return 0;
}