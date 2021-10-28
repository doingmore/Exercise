#include <iostream>

using namespace std;

/*
Write a program that reads a matrix of integers from the console, then a number, and prints all the positions at which that number appears in the matrix.
The matrix definition on the console will contain a line with two positive integer numbers R and C – the number of rows and columns in the matrix – followed by
R lines, each containing C numbers (separated by spaces), representing each row of the matrix.
You should print each position on a single line – first print the row, then the column at which the number appears.
If the number does not appear in the matrix, print not found
*/

int main()
{
    int row{ 0 }, column{ 0 };
    int matrix[100][100];
    int wantedNumber{ 0 }, countSeccessfulMatch{0};
    cout << "How many rows are in a matrix: ";
    cin >> row;
    cout << "How many columns are in a matrix: ";
    cin >> column;

    matrix[row][column];

    cout << "Input the numbers in matrix: "<<'\n';
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the wanted number:" <<'\n';
    cin >> wantedNumber;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == wantedNumber)
            {
                cout <<"row: "<<i+1<<" "<<"column: "<<j+1<< '\n';
                countSeccessfulMatch++;
            }
        }
    }

    if (countSeccessfulMatch == 0)
    {
         cout << "In this matrix not found wanted number" << '\n';
    }

    return 0;
}
