#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string s = "Hello Simona";
    istringstream stream(s);

    string first, second;
    stream >> first >> second;

    string numbersString = "3 -2";
    istringstream numbersStream(numbersString);

    int num1{ 0 }, num2{ 0 };
    numbersStream >> num1 >> num2;

    ostringstream outputStream;

    outputStream << "The sum is: " << num1 + num2 << '\n';

    cout << outputStream.str();

    return 0;
}
