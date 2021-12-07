#include <iostream>
#include <vector>

using namespace std;

/*
Write a program, use vector( Matrix ) that finds the sum of numbers ABOVE the diagonal.
*/

void Problem3()
{
	int sizeMatrix{ 0 };
	cout << "Enter size of matrix: ";
	cin >> sizeMatrix;
	vector<vector<int> > matrix;
	int inputSymbol{ 0 };
	vector<int> myVector;
	for (int row = 0; row < sizeMatrix; row++)
	{
		for (int i = 0; i < sizeMatrix; i++)
		{
			cin >> inputSymbol;
			myVector.push_back(inputSymbol);
		}
		matrix.push_back(myVector);
		myVector.clear();
	}
	int sum{ 0 };
	for (int passRow = 0; passRow < sizeMatrix; passRow++)
	{
		for (int passCol = 0; passCol < sizeMatrix; passCol++)
		{
			if (passCol > passRow)
			{
				sum += matrix[passRow][passCol];
			}
		}
	}
	cout << "The sum of numbers above diagonal is: " << sum << '\n';
}