#include <iostream>
#include <vector>

using namespace std;

/*
Write a program, use vector( Matrix ) that finds the sum of numbers ABOVE the diagonal.
*/

void Problem3()
{
	int sizeMatrix{ 0 };
	cin >> sizeMatrix;
	vector<int> matrix[100][100];
	int inputSymbol{ 0 };
		for (unsigned int row = 0; row < sizeMatrix; row++)
		{
			for (unsigned int col = 0; col < sizeMatrix; col++)
			{
				cin >> inputSymbol;
				matrix[row][col].push_back(inputSymbol);
			}
		}

}