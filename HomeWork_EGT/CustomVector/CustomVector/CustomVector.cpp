#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "vector.h"
#include "Person.h"

#define TestType Person

void doReport(Vector<TestType>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << '\n';
}
void doReport( std::vector<int>& vec )
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << '\n';
}




int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // ========================= standart std::vector ======================================
    
    //   test automatic increase capacity
    /* 
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    for (int i = 0; i < 50; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    */ 
    //   test increase capacity after resize functions   ( same action! )
    /*
    std::vector<int> vec;
    vec.resize(4);
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    for (int i = 0; i < 50; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    */

    //   test pop_back                                    ( reduce only elements not capacity )
    /*
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    doReport(vec);

    vec.pop_back();

    doReport(vec);
    */

    // ========================= custom vector ======================================

    // Test operator=  
    /*
    Vector<TestType> vec1;
    for (int i = 0; i < 4; i++)
    {
        vec1.push_back(Person{"Mr.Robot",i+5});
    }
    std::cout << "before assignment vec 1: "<<'\n';
    doReport(vec1);
    Vector<TestType> vec2;
    vec2 = vec1;
    std::cout << "after assignment vec 2: "<<'\n';
    doReport(vec1);
    */

    // Test copy CTR   
    /*
    Vector<TestType> vec1;
    for (int i = 0; i < 4; i++)
    {
        vec1.push_back(5 + i);
    }
    std::cout << "before copyCTR vec 1: "<<'\n';
    doReport(vec1);
    Vector<TestType> vec2=vec1;
    std::cout << "after copyCTR vec 2: " << '\n';
    doReport(vec1);
    */

    // Test automatic increase capacity LINEAR
    /*
    Vector<TestType> vec;
    for (int i = 0; i < 6; i++)
    {
        vec.push_back(1 + i);
        doReport(vec);
    }
    for (int i = 6; i < 26; i++)
    {
        vec.push_back(1 + i);
        doReport(vec);
    }
    for (int i = 26; i < 80; i++)
    {
        vec.push_back(5 + i);
        doReport(vec);
    }
    */
    
    // Test automatic increase capacity after function resize and mix
    /*
    Vector<TestType> vec;
    vec.resize(3);                    // start with resize
    for (int i = 0; i < 6; i++)
    {
        vec.push_back(1 + i);
        doReport(vec);
    }
    vec.erase();

    for (int i = 0; i < 6; i++)
    {
        vec.push_back(1 + i);         // start with push_back
        doReport(vec);
    }

    vec.resize(2);                    // all elements after second will be deallocated
    doReport(vec);

    for (int i = 6; i < 26; i++)
    {
        vec.push_back(1 + i);
        doReport(vec);
    }
    */

    // Test pop_back  
    /*
    Vector<TestType> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    doReport(vec);

    vec.pop_back();

    doReport(vec);
    */
    
    // Test reserve
    /*
    Vector<TestType> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    doReport(vec);
    size_t a{ 4 };
    vec.reserve(a);  

    doReport(vec);
    */
    





    system("PAUSE");
    return 0;
}