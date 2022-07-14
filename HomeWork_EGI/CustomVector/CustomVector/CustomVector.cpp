#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "vector.h"
#include "Person.h"


#define TestType Person


Vector<TestType> otherScope()
{
    Vector<TestType> answer;

    
    Person first{"Mr.Robot",3};      // test for user defined type
    Person second{ "NONAME",8 };     // test for user defined type
    Person third{ "EXAMPLE",30 };    // test for user defined type

    answer.push_back(first);
    answer.push_back(second);
    answer.push_back(third);
    

    /*
    answer.push_back(5);            // test for int and char also
    answer.push_back(8);              // test for int and char also
    answer.push_back(10);           // test for int and char also
    */

    /*answer.push_back("test");       // test for std::string
    answer.push_back("EGT");          // test for std::string
    answer.push_back("GABLING");*/    // test for std::string

    for (size_t i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << " ";
    }
    std::cout << '\n';
    return answer;
}




int main()
{
    // test memory leak
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    /*
    // test copy CTR
    Vector<TestType> vec = otherScope();
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] <<" ";
    }
    std::cout << '\n';

    // test assignment operator
    Vector<TestType> copy;
    copy = vec;
    for (size_t i = 0; i < copy.size(); i++)
    {
        std::cout << copy[i] << " ";
    }
    std::cout << '\n';
    */
    Vector<TestType> vec;
    Person first{ "Mr.Robot",3 };      // test for user defined type
    Person second{ "NONAME",8 };     // test for user defined type
    Person third{ "EXAMPLE",30 };    // test for user defined type



    std::vector<TestType> s_vec;
    s_vec.push_back(first);
    s_vec.resize(2);
    for (size_t i = 0; i < s_vec.size(); i++)
    {
        std::cout << s_vec[i] << " ";
    }

    s_vec.push_back(second);
    s_vec.push_back(third);
    std::cout << s_vec.size() << " " << s_vec.capacity() << '\n';


    vec.push_back(first);
    vec.push_back(second);
    vec.push_back(third);

    std::cout << vec.size() << " " << vec.capacity();

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';

    vec.erase();
    

    return 0;
}
