#include <iostream>
#include <vector>
#include <string>

using namespace std;

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



void readInput(vector<string>& outInput)
 {
	int rows = 0;
	int cols = 0;

	std::cin >> rows >> cols;

	outInput.resize(rows);
	for (int i = 0; i < rows; ++i)
	{
		outInput[i].resize(cols);
	}

	for (int row = 0; row < rows; ++row)
	{
		cin >> outInput[row];
	}
}
void findMines(const vector<string>& matrix,vector<int>& minesX,vector<int>& minesY)
{
	for (int row = 0; row < matrix.size(); ++row)
	{
		for (int col = 0; col < matrix[row].size(); ++col)
		{
			//found mine
			if ('!' == matrix[row][col])
			{
				minesX.push_back(row);
				minesY.push_back(col);
			}
		}
	}
}

void expandSingleMine(vector<string>& mineField,const int ROW,const int COL)
{
	if (COL < 0 || ROW < 0 || COL >= (int)mineField[0].size() || ROW >= (int)mineField.size())
	{
		return;
	}

	mineField[ROW][COL] += 1;
}

void expandMines(vector<string>& mineField,const vector<int>& minesX,const vector<int>& minesY)
{
	for (int i = 0; i < minesX.size(); ++i)
	{
		const int ROW = minesX[i];
		const int COL = minesY[i];
		//expand mine


		expandSingleMine(mineField, ROW - 1, COL - 1);
		expandSingleMine(mineField, ROW - 1, COL);
		expandSingleMine(mineField, ROW - 1, COL + 1);

		expandSingleMine(mineField, ROW, COL - 1);
		expandSingleMine(mineField, ROW, COL);
		expandSingleMine(mineField, ROW, COL + 1);

		expandSingleMine(mineField, ROW + 1, COL - 1);
		expandSingleMine(mineField, ROW + 1, COL);
		expandSingleMine(mineField, ROW + 1, COL + 1);
	}
}

void printMatrix(const vector<string>& matrix)
{
	for (int row = 0; row < matrix.size(); ++row)
	{
		cout << matrix[row] << '\n';
	}
}

int main()
{
	//1) read input
	vector<string> mineField;
	readInput(mineField);
	//2) find mines
	vector<int> minesX;
	vector<int> minesY;
	findMines(mineField, minesX, minesY);

	vector<string> mineFieldValues(mineField.size(), string(mineField[0].size(), '0'));

	//3) expand mines
	expandMines(mineFieldValues, minesX, minesY);

	
	//4) print answer
	printMatrix(mineFieldValues);
	
	return 0;
}