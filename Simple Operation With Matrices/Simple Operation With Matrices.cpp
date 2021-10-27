#include <iostream>

using namespace std;

int main()
{
    int operation, rowFirst, columnFirst, rowSecond, columnSecond;
    int matrix1[100][100], matrix2[100][100], addition[100][100], subtraction[100][100], multiplication[100][100]; //max size
    bool flag=false; //For compare

    // Display the menu of operations
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
    if (operation < 1 || operation > 5)
    {
        cout << "Error! Please enter a number avalible in menu above" << '\n';
        cin >> operation;
    }

    // Ask the user about the size of each matrix
    cout << "How many rows are in the first matrix ? ";
    cin >> rowFirst;
    cout << "How many columns are in the first matrix ? ";
    cin >> columnFirst;
    cout << "How many rows are in the second matrix ? ";
    cin >> rowSecond;
    cout << "How many columns are in the second matrix ? ";
    cin >> columnSecond;
    cout << '\n';

    matrix1[rowFirst][columnFirst];
    matrix2[rowSecond][columnSecond];

    // Check the conditions which must be satsified to perform the operation
    switch (operation)
    {
    case 1:
    {
        if (rowFirst != rowSecond || columnFirst != columnSecond)
        {
            cout << "Error ! Number of rows/columns in matrix 1 must be equal to " << '\n' <<
                "Number of rows/columns in matrix 2 to preform ADDITION" << '\n';
         system("pause");
         return -1;
        }

        break;
    }
    case 2:
    {
        if (rowFirst != rowSecond || columnFirst != columnSecond)
        { 
            cout << "Error ! Number of rows/columns in matrix 1 must be equal to " << '\n' <<
            "Number of rows/columns in matrix 2 to preform SUBTRACTION" << '\n';
        system("pause");
        return -1;
        }

        break;
    }
    case 3:
    {
        if (columnFirst != rowSecond)
        { 
            cout << "Error ! Number of Columns in first matrix must be equal " << '\n' <<
            "to number of rows in second matrix to prefom Multiplication" << '\n';
        system("pause");
        return -1;
        }

        break;
    }
    case 4:
        if (rowFirst != rowSecond || columnFirst != columnSecond)
        {
            cout << "Error ! Number of rows/columns in matrix 1 must be equal to " << '\n' <<
                "Number of rows/columns in matrix 2 to preform COMPARE" << '\n';
            system("pause");
            return -1;
        }

        break;
    }

    
    // Ask user to enter first marix. Enter the numbers on one row with space betwin them.
    cout << "First Matrix :" << '\n';

    for (int i = 0; i < rowFirst; i++)
    {
        cout << "Please enter row" << i + 1 << " : ";
        {
            for (int j = 0; j < columnFirst; j++)
            { 
             cin >> matrix1[i][j];
            }
        }
    }
    cout << '\n';

    // Ask user to enter Second marix. Enter the numbers on one row with space betwin them.
    cout << "Second Matrix :" << '\n';

    for (int i = 0; i < rowSecond; i++)
    {
        cout << "Please enter row" << i + 1 << " : ";
        {
            for (int j = 0; j < columnSecond; j++)
            { 
             cin >> matrix2[i][j];
            }
        }
    }
    cout << '\n';
    
    switch (operation)
    {
    case 1:
        // Prefprm ADITION
        for (int i = 0; i < rowFirst; i++)
        {
            for (int j = 0; j < columnFirst; j++)
            {
                addition[i][j] = matrix1[i][j] + matrix2[i][j];
                cout << addition[i][j] << '\n';
            }
        }
        break;

    case 2:
        // preform SUBTRACTION
        for (int i = 0; i < rowFirst; i++)
        {
            for (int j = 0; j < columnFirst; j++)
            {
                subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
                cout << subtraction[i][j] << '\n';
            }
        }
        break;

    case 3:
        // preform MULTIPLICATION
        for (int i = 0; i < rowFirst; i++)
        {
            for (int j = 0; j < columnSecond; j++)
            {
                for (int k = 0; k < columnSecond; k++)
                {
                    multiplication[i][j] = matrix1[i][j] * matrix2[i][j];
                }
                cout << multiplication[i][j] << " "; 
            }
            '\n';
        }

        break;

    case 4:
        // preform COMPARE
        for (int i = 0; i < rowFirst; i++)
        {
            for (int j = 0; j < columnFirst; j++)
            {
                if (matrix1[i][j] != matrix2[i][j])
                {
                    cout << "The matrices are not equal."<< '\n';
                    flag = true;
                } 
                break;
            }
            if (flag)
            {
                break;
            }
        }
        break;
    }
    return 0;
}
