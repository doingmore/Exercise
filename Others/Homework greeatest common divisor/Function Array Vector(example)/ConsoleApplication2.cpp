#include <iostream>
#include <vector>
using namespace std;

vector<double> getSquareRoots(int from, int to)
{
    vector<double>roots;
    for (size_t i = from; i < to; i++)
    {
        roots.push_back(sqrt((double)i));
    }
    return roots;
}

void printVector(vector<double>arr)
{
    for (double number : arr)
    {
        cout << number << " ";
    }
}

int main()
{
  
    printVector( getSquareRoots(4, 25));
    
    return 0;
}


