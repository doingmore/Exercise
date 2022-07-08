#include <iostream>
#include <vector>
#include <string>

void resizeMatrix(std::vector<std::vector<int> >& matrix , const int& size)
{
    matrix.resize(size);
    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i].resize(size);
    }
}

void fillingMatrix(std::vector<std::vector<int> >& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {

        for (size_t k = 0; k < matrix[i].size(); k++)
        {
            std::cout << "Enter element at matrix["<<i<<"]["<<k<<"] : ";
            std::cin >> matrix[i][k];
        }

    }
}

int getSumAboveDiagonal(const std::vector<std::vector<int> >& matrix)
{
    int answer{ 0 };
    for (size_t i = 0; i < matrix.size(); i++)
    {

        for (size_t k = 0; k < matrix[i].size(); k++)
        {
            if (i<k)
            {
                answer = answer + matrix[i][k];
            }
        }

    }
    return answer;
}


int main()
{
    int sizeOfMatrix;
    std::cout << "Enter size of matrix: ";
    std::cin >> sizeOfMatrix;
    std::vector<std::vector<int> > matrix;
    resizeMatrix(matrix, sizeOfMatrix);
    fillingMatrix(matrix);
    std::cout << getSumAboveDiagonal(matrix) << '\n';
    return 0;
}

