#include <iostream>
#include <algorithm>
#include <vector>


void sortGrather (std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        int* it = &v[i];
        for (size_t k = i+1; k < v.size(); k++)
        {
            if (*it<v[k])
            {
                it = &v[k];
            }
        }
        int temp = v[i];
        v[i] = *it;
        *it = temp;
    }
}


int main()
{
    int size{0};
    std::cin >> size;
    std::vector<int> intArray;

    for (int i = 0; i < size; i++)
    {
        int n;
        std::cin >> n;
        intArray.push_back(n);
    }

    sortGrather(intArray);

    ///std::sort(intArray.begin(), intArray.end(), [](const int& left, const int& right) {return left > right; });

    for (const int& n : intArray )
    {
        std::cout << n << " ";
    }

    return 0;
}
