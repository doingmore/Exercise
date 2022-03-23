#include <iostream>
#include <vector>


void createMatrix(std::vector<std::string>& matrix)
{
	matrix.resize(10);
	for (int i = 0; i < 10; i++)
	{
		matrix[i].resize(10);
	}
}

void fillingMatrix(std::vector<std::string>& matrix)
{
	char symbol;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			std::cin >> symbol;
			matrix[i][k] = symbol;
		}
	}
}

std::vector<std::pair<int,int> > getCoordinateStartRust(const std::vector<std::string>& matrix)
{
	std::vector<std::pair<int, int> > answer;
	int row;
	int col;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t k = 0; k < matrix[i].size(); k++)
		{
			if (matrix[i][k] == '!')
			{
				row = i;
				col = k;
				answer.push_back(std::pair<int, int>(row, col));
			}
		}
	}
	return answer;
}

void expandRust(std::vector<std::string>& matrix)
{
	std::vector<std::pair<int, int>> coordinates{ getCoordinateStartRust(matrix) };
	int spread{ 0 };
	std::cin >> spread;
	int row{0};
	int col{0};
	std::vector<std::pair<int, int> >::iterator it;
	for (it = coordinates.begin(); it != coordinates.end(); it++)
	{
	
		row = it->first;
		col = it->second;

		// positive direction on row and col
		int rS{ 0 }; // row start
		for (int r=row; r < 10; r++)
		{
			int cS{ 0 + rS }; // column start
			for (int c = col; c < 10; c++)
			{
				if (matrix[r][c] != '#')
				{
					matrix[r][c] = '!';
				}
				if (cS>=spread)
				{
					break;
				}
				cS++;
			}
			if (rS >= spread)
			{
				break;
			}
			rS++;
		}
		rS= 0; // negative direction on row,positive on coloumn
		for (int r=row; r >= 0; r--)
		{
			int cS{ 0 + rS }; 
			for (int c = col; c < 10; c++)
			{
				if (matrix[r][c] != '#' && matrix[r][c] != '!')
				{
					matrix[r][c] = '!';
				}
				if (cS >= spread)
				{
					break;
				}
				cS++;
			}
			if (rS >= spread)
			{
				break;
			}
			rS++;
		}
		rS = 0; // negative direction on row,negative on coloumn
		for (int r = row; r >= 0; r--)
		{
			int cS{ 0 + rS };
			for (int c = col; c >= 0; c--)
			{
				if (matrix[r][c] != '#' && matrix[r][c] != '!')
				{
					matrix[r][c] = '!';
				}
				if (cS >= spread)
				{
					break;
				}
				cS++;
			}
			if (rS >= spread)
			{
				break;
			}
			rS++;
		}
		rS = 0; // positive direction on row,negative on coloumn
		for (int r = row; r < 10; r++)
		{
			int cS{ 0 + rS };
			for (int c = col; c >= 0; c--)
			{
				if (matrix[r][c] != '#' && matrix[r][c] != '!')
				{
					matrix[r][c] = '!';
				}
				if (cS >= spread)
				{
					break;
				}
				cS++;
			}
			if (rS >= spread)
			{
				break;
			}
			rS++;
		}
	}
}

void printMatrix(const std::vector<std::string>& matrix)
{
	for (size_t row = 0; row < matrix.size(); row++)
	{
		for (size_t col = 0; col < matrix[row].size(); col++)
		{
			std::cout << matrix[row][col];
		}
		std::cout << '\n';
	}
}

int main_4()
{
	std::vector<std::string> matrix;
	createMatrix(matrix);
	fillingMatrix(matrix);
	expandRust(matrix);
	printMatrix(matrix);
	return 0;
}