#include <iostream>
#include <vector>
#include <string>
#include <stack>


/*
You are given a N by M matrix (N and M are two integers entered on the console), in which the cells contain single characters – either a . (dot),
or a ! (exclamation mark) – representing "empty" or "mined" positions. Write a program that prints a N by M matrix, where each cell contains
a number, representing how many adjacent cells, including itself, are "mined". Each cell in a matrix has at most 8 adjacent cells
– the cells directly above, below, to the left, to the right, as those diagonally – to the left and above, to the right and above, to the right and below and to the left and below.

		5 5
		.....
		...!.
		.....
		.....
		.....
 second test input
		5 8
		........
		...!....
		....!...
		........
		...!....
*/

void readMatrix(std::vector<std::string>& matrix)
{
	int row;
	int col;
	std::cin >> row >> col;
	matrix.resize(row);

	for (size_t i = 0; i < row; i++)
	{
		matrix[i].resize(col);
	}
}

void fillMatrix(std::vector<std::string>& matrix)
{
	char symbol;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			std::cin >> symbol;
			matrix[i][k]= symbol;
		}

	}
	// transform '.' to zero '0'
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			if (matrix[i][k] == '.')
			{
				matrix[i][k] = '0';
			}
		}
	}

}

bool findMine(int& r,int& c,std::vector<std::string>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			if (matrix[i][k] == '!')
			{
				r = i;
				c = k; 
				matrix[i][k] = 48;
				return true;
			}
		}

	}
	return false;
}

void explodeMines(std::vector<std::string>& matrix)
{
	int coordinatRow{0};
	int coordinatCol{0};
	std::vector<std::pair<int, int> > coordinatesMines;

	while (findMine(coordinatRow, coordinatCol, matrix))
	{
		matrix[coordinatRow][coordinatCol] +=1;
		coordinatesMines.push_back(std::pair<int,int>(coordinatRow, coordinatCol));
	}
	
	std::vector<std::pair<int, int> >::iterator it=coordinatesMines.begin();
	for (size_t i = 0; i < coordinatesMines.size() ; i++, it++)
	{
		coordinatRow = it->first;
		coordinatCol = it->second;
		if ( coordinatCol + 1 < matrix[0].size()) // one right
		{
			matrix[coordinatRow][coordinatCol + 1] += 1;
		}
		if ( coordinatCol - 1 >= 0) // one left
		{
			matrix[coordinatRow][coordinatCol - 1] += 1;
		}
		if ( coordinatRow + 1 < matrix.size()) //one down
		{
			matrix[coordinatRow + 1][coordinatCol] += 1;
		}
		if ( coordinatRow - 1 >= 0) // one above
		{
			matrix[coordinatRow - 1][coordinatCol] += 1;
		}
		// diagonals
		if (coordinatCol + 1 < matrix[0].size() && coordinatRow - 1 >= 0) // one right and above
		{
			matrix[coordinatRow - 1][coordinatCol + 1] += 1;
		}
		if (coordinatCol - 1 >= 0 && coordinatRow - 1 >= 0) // one left and above
		{
			matrix[coordinatRow - 1][coordinatCol - 1] += 1;
		}
		if (coordinatRow + 1 < matrix.size() && coordinatCol + 1 < matrix[0].size() ) // one right and down
		{
			matrix[coordinatRow+1][coordinatCol+1] += 1;
		}
		if (coordinatRow + 1 < matrix.size() && coordinatCol - 1 >= 0) // one left and down
		{
			matrix[coordinatRow + 1][coordinatCol - 1] += 1;
		}
	}
}


void printMatrix(std::vector<std::string>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			std::cout << matrix[i][k];
		}
		std::cout << '\n';
	}
}

int main()
{
	std::vector<std::string> matrix;
	
	readMatrix(matrix);
	
	fillMatrix(matrix);

	explodeMines(matrix);

	printMatrix(matrix);
	return 0;
}