#include <iostream>
#include <vector>

using namespace std;

void Problem2()
{
	int sizeOfMatrix{ 0 };
	cin >> sizeOfMatrix;
	vector<vector<int> > matrix;
	vector<int> myVector;
	int inputNumber{ 0 };
	int sumOfOddNumbers{ 0 };
	for (int row = 0; row < sizeOfMatrix; row++)
	{
		for (int col = 0; col < sizeOfMatrix; col++)
		{
			cin >> inputNumber;
			myVector.push_back(inputNumber);
		}
		matrix.push_back(myVector);
		myVector.clear();
	}

	for (int passRow = 0; passRow < matrix.size(); passRow++)
	{
		for (int passCol = 0; passCol < matrix.size(); passCol++)
		{
			//two cheks for diagonals
			if (passRow == passCol)
			{
				//do nothing
			}
			else if ((passRow + passCol) == (sizeOfMatrix - 1))
			{
				//do nothing
			}
			//chek for odd
			else if ((matrix[passRow][passCol]%2) != (0))
			{
				sumOfOddNumbers += matrix[passRow][passCol];
			}
		}
	}

	cout << "The sum is: " << sumOfOddNumbers << '\n';

}