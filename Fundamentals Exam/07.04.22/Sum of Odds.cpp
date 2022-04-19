#include <iostream>
#include <vector>

void createMatrix(std::vector<std::vector<int> >& matrix, const int& size)
{
	matrix.resize(size);
	for (size_t i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(size);
	}
}

void fillingMatrix(std::vector<std::vector<int> >& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++) // i= row
	{
		for (size_t k = 0; k < matrix.size(); k++)  // k = col
		{
			std::cin >> matrix[i][k];
		}
	}
}

void getSum(const std::vector<std::vector<int> >& matrix, int& sum)
{
	for (size_t i = 0; i < matrix.size(); i++) // i= row
	{
		for (size_t k = 0; k < matrix.size(); k++)  // k = col
		{
			if ( (i != k) &&  (i+k != matrix.size()-1 ) )  // check for position
			{
				if ((matrix[i][k] % 2 != 0) && matrix[i][k] > 0) //check for Odd
				{
				sum +=  matrix[i][k] ;
				}
			}
		}
	}
}

int main_Exam_Problem2()
{
	std::vector<std::vector<int> > matrix;
	int sizeOfMatrix{ 0 }; //Everytime row equal to coloumn
	int sum{ 0 }; // Of non diagonals positions
	std::cin >> sizeOfMatrix;
	createMatrix(matrix,sizeOfMatrix);
	fillingMatrix(matrix);
	getSum(matrix,sum);
	std::cout << "The sum is: " << sum << '\n';
	return 0;
}