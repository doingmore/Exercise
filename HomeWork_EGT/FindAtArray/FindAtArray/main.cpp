#include <iostream>





int main()
{   //                     |      |    
    int data[]{ -2,5,8,6,4,-9,5,3,7,-3 };
    int targetSum{ 7 };
    // I put number equal to searching sum, but we need for two number, not only one .... we don't have a zero
    
    
    bool flag = false;
    int numberA{ 0 };
    int numberB{ 0 };
    for (int i = 0; i < 10; i++)  // start from index 1 
    {
        numberA = data[i];
        for (int k = i+1; k < 10; k++)
        {
            if ((numberA + data[k]) == targetSum)
            {
                numberB = data[k];
                flag = true;
                break;
            }
        }
        if (flag)
        {
            // stop we don't need more iteration
            break;
        }
    }

    return 0;
}
