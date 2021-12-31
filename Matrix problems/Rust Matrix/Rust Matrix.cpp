#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
You are given a 10x10 matrix representing a metal square, which has begun to rust. There are 3 types of symbols in the matrix
– a . (dot) means a healthy part of the metal, a # indicates a rust-resistant part, and a ! indicates a part that has begun to rust.
There may be 0, 1 or more parts that has begun to rust. The rust spreads from a rusty cell to healthy cells by "infecting" adjacent
cells directly above, to the right, below and to the left of itself (no diagonals), at the same time. The rust cannot infect cells
that are indicated as rust-resistant. Let’s define the time it takes for all cells adjacent to a rusty cell to get infected as 1 unit.
After reading the matrix, read a single integer – the elapsed time in units (as defined above) – and print a matrix representing 
how the metal square will look after the rust has been acting on it for that amount of time
*/

void readRust(vector<string>& outInput)
{
    int rows{ 0 };
    int cols{ 0 };
    cin >> rows >> cols;

    outInput.resize(rows);
    for (size_t i = 0; i < rows; i++)
    {
        outInput[i].resize(cols);
    }

    for (size_t row = 0; row < rows; row++)
    {
        cin >> outInput[row];
    }
}

void printMatrix(const vector<string>& matrix)
{
    for (size_t row = 0; row < matrix.size(); row++)
    {
        cout << matrix[row] << '\n';
    }
}

void expandSingleRust(vector<string>& rustField,
    const int ROW,
    const int COL)
{
    if (COL < 0 || ROW < 0 || COL >= (int)rustField[0].size()
        || ROW >= (int)rustField.size())
    {
        return;
    }
    rustField[ROW][COL] = '!';
}

void expandRust(vector<string>& rustedMetal, vector<int>& rustX,
    vector<int>& rustY)
{
    for (size_t i = 0; i < rustX.size(); i++)
    {
        int ROW = rustX[i], COL = rustY[i];
        expandSingleRust(rustedMetal, ROW - 1, COL);
        expandSingleRust(rustedMetal, ROW, COL - 1);
        expandSingleRust(rustedMetal, ROW, COL + 1);
        expandSingleRust(rustedMetal, ROW + 1, COL);
    }
}


int main()
{
    //1) read input
    vector<string> rustedMetal;
    readRust(rustedMetal);

    int ticks;
    cin >> ticks; // how many times tickes we need to calculate

    //3) expand mines
    while (ticks--)
    {
        vector<int> rustX;
        vector<int> rustY;
        findRust(rustedMetal, rustX, rustY); // analyze and locate rust's coordinates
        expandRust(rustedMetal, rustX, rustY);// extend new rust on the rustedmetal
    }
    
    //4) print answer
    printMatrix(rustedMetal);

    return 0;
}
