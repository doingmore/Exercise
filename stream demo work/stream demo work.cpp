#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    
    input.open("input.txt"); // NOTE: The file input.txt is created in directory on this example
    int a, b;
    input >> a >> b;

    ofstream output;
    output.open("output.txt", fstream::app);

    output << a + b <<'\n';
    // The result is saved in file output. first result and second are from error, when I tested the example
    return 0;
}
