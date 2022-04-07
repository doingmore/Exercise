#include <iostream>
#include <vector>

void createMatrix(std::vector<std::string>& matrix,const int& size)
{
	matrix.resize(size);
	for (size_t i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(size);
	}
}

void fillingMatrix(std::vector<std::string>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix.size(); k++) //rows every time are equal to columns
		{
			std::cin >> matrix[i][k];
		}
	}
}

void getSum(std::vector<std::string>& matrix,int& sum) //above on diagonal
{
	int temp{ 0 };
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix.size(); k++)
		{
			if (k > i)
			{
				temp = matrix[i][k] - 48 ;
				sum += temp;
			}
		}

	}
}

int main_3()
{
	int sizeMatrix{ 0 }; // every time row equal on column
	std::cin >> sizeMatrix;
	std::vector<std::string> matrix;
	int sum{ 0 };
	createMatrix(matrix,sizeMatrix);
	fillingMatrix(matrix);
	getSum(matrix,sum);

	std::cout << sum << '\n';

	return 0;
}