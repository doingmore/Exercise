#include <iostream>
#include <vector>
using namespace std;

/* on a warning level 4 detected warning "signed/ unsigned"
in function printMultiplied because of this we 
must use "unsigned" for type "i". In function print use type 
"size_t" which is also compatible */

void print(vector<int>numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << '\n';
}

void printMultiplied(vector<int>numbers, int multiplier)
{
    for (unsigned i = 0; i < numbers.size(); i++)
    {
        numbers[i]*= multiplier;
    }
    print(numbers);
}

int main()
{
    vector<int> numbers{ 1,2,3 };
    printMultiplied(numbers, 10); // 10, 20, 30
    print(numbers); //1, 2, 3
    return 0;
}