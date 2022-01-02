#include <iostream>
// #include <vector>


// This example is not from problems
// Store the elements dynamic and print them
/*
3
2 3 5
3 8 -4 2
4 2 2 3 1
*/

int main()
{
    /*
    int numberOfArr{ 0 };
    int currentArrSize{ 0 };
    std::cin >> numberOfArr;

    std::vector<std::vector<int> > arr2D(numberOfArr);

    for (int i = 0; i < numberOfArr; i++)
    {
        std::cin >> currentArrSize;
        arr2D[i].resize(currentArrSize);
        for (int j = 0; j < currentArrSize; j++)
        {
            std::cin >> arr2D[i][j];
        }
    }


    for (size_t i = 0; i < arr2D.size(); i++)
    {
        for (size_t j = 0; j < arr2D[i].size(); j++)
        {
            std::cout << arr2D[i][j]<<" ";
        }
        std::cout << '\n';
    }
    */

    int numberOfArr{ 0 };
    std::cin >> numberOfArr;

    int** arr2D = new int* [numberOfArr];
    int* arrSizes = new int[numberOfArr];
    for (int i = 0; i < numberOfArr; i++)
    {
        std::cin >> arrSizes[i];
        arr2D[i] = new int[arrSizes[i]];

        for (int j = 0; j < arrSizes[i]; j++)
        {
            std::cin >> arr2D[i][j];
        }
    }


    for (int i = 0; i < numberOfArr; i++)
    {
        for (int j = 0; j < arrSizes[i]; j++)
        {
            std::cout << arr2D[i][j] << " ";
        }
        std::cout << '\n';
    }

    delete[] arrSizes;
    arrSizes = nullptr;

    for (int i = 0; i < numberOfArr; i++)
    {
        delete[] arr2D[i];
        arr2D[i] = nullptr;
    }

    delete[] arr2D;
    arr2D = nullptr;

    return 0;
}
