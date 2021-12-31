#include <iostream>
#include <vector>
using namespace std;

/*
Write a program that reads two integer matrices (2D arrays) from the console and compares them element by element. 
For better code reusability, you could do the comparison in a function, which returns true if they are equal
and false if not. Each matrix definition on the console will contain a line with a positive integer number R – the number
of rows in the matrix – followed by R lines containing the numbers in the matrix, separated by spaces
(each line will have an equal amount of numbers.The matrices will have at most 10 rows and at most 10 columns.
Print equal if the matrices match, and not equal if they don’t match.
*/

int main()
{
    int operation, row1, column1, row2, column2;
    int matrix1[100][100], matrix2[100][100], addition[100][100], subtraction[100][100], multiplication[100][100]; //max size

    // Display the menu of operations
    cout << "Menu of operations " << '\n';
    cout << "-------------------------" << '\n';
    cout << "1- MATRIX ADDITION" << '\n';
    cout << "2- MATRIX SUBTRACTION" << '\n';
    cout << "3- MATRIX MULTIPLICATION" << '\n';
    cout << "4- MATRIX COMPARE" << '\n';
    cout << "-------------------------" << '\n';

    cout << "Please enter your choice from the menu above : ";
    cin >> operation;

    // Display Error message if user enter not availble
    // number of operation and ask him to enter again
    if (operation < 1 || operation > 3)
    {
        cout << "Error! Please enter a number avalible in menu above" << '\n';
        cin >> operation;
    }

    // Ask the user about the size of each matrix
    cout << "How many rows are in the first matrix ? ";
    cin >> row1;
    cout << "How many columns are in the first matrix ? ";
    cin >> column1;
    cout << "How many rows are in the second matrix ? ";
    cin >> row2;
    cout << "How many columns are in the second matrix ? ";
    cin >> column2;
    cout << '\n';

    matrix1[row1][column1];
    matrix2[row2][column2];

    // Check the conditions which must be satsified to perform the operation
    switch (operation)
    {
    case 1:
    {
        if (row1 != row2 || column1 != column2)
        {
            cout << "Error ! Number of rows/columns in matrix 1 must be equal to " << endl <<
                "Number of rows/columns in matrix 2 to preform ADDITION" << endl << endl;
            system("pause");
            return -1;
        }

        break;
    }
    case 2:
    {
        if (row1 != row2 || column1 != column2)
            cout << "Error ! Number of rows/columns in matrix 1 must be equal to " << endl <<
            "Number of rows/columns in matrix 2 to preform SUBTRACTION" << endl << endl;
        system("pause");
        return -1;
    }
    case 3:
    {
        if (column1 != row2)
            cout << "Error ! Number of Columns in first matrix must be equal " << endl <<
            "to number of rows in second matrix to prefom Multiplication" << endl << endl;
        system("pause");
        return -1;
        break;
    }
    }
    // Ask user to enter first marix
    cout << "First Matrix :" << '\n';

    for (int i = 0; i < row1; i++)
    {
        cout << "Please enter row #" << i + 1 << " : ";
        {
            for (int j = 0; j < column1; j++)
                cin >> matrix1[i][j];
        }
    }
    cout << '\n';

    // Ask user to enter Second marix
    cout << "Second Matrix :" << '\n';

    for (int i = 0; i < row2; i++)
    {
        cout << "Please enter row #" << i + 1 << " : ";
        {
            for (int j = 0; j < column2; j++)
                cin >> matrix2[i][j];
        }
    }
    cout << '\n';
    switch (operation)
    {
    case 1:
        // Prefprm ADITION
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
            {
                addition[i][j] = matrix1[i][j] + matrix2[i][j];
                cout << addition[i][j] << '\n';
            }
        break;

    case 2:
        // preform SUBTRACTION
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column1; j++)
            {
                subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
                cout << subtraction[i][j] << '\n';
            }
        break;

    case 3:
        // preform MULTIPLICATION
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < column2; j++)
                for (int k = 0; k < column2; k++)
                {
                    multiplication[i][j] += matrix1[i][j] * matrix2[i][j];
                    cout << multiplication[i][j];
                }
        break;

    }
    system("pause");
    return 0;
}
