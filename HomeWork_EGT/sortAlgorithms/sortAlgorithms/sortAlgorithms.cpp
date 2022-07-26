#include <iostream>

#include "algorithms.h"





int main()
{
    //int data[]{ 9,5,1,4,3 };
    int data[]{ 14,24,37,42,50 };
    constexpr int size =static_cast<int>(std::size(data));

    //insertionAlg(data, size);
    //selectionAlg(data,size);
    bubbleSort(data,size);
    print(data , size);


    return 0;
}
