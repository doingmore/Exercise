#include <iostream>
#include <string>
#include <sstream>

#include <chrono> // aded be me
using namespace std::chrono; // aded be me

#include "List.h"
                      //    sorted    //  current  //
List mergeSortedLists(      List a    ,   List b   ) {
      List merged;

    while (!a.isEmpty() || !b.isEmpty()) {
        List* listToTakeFrom;
        if (a.isEmpty()) {
            listToTakeFrom = &b;
        }
        else if (b.isEmpty()) {
            listToTakeFrom = &a;
        }
        else {
            if (a.first() < b.first()) {
                listToTakeFrom = &a;
            }
            else {
                listToTakeFrom = &b;
            }
        }

        merged.add(listToTakeFrom->first());
        listToTakeFrom->removeFirst();
    }

    return merged;
}

/* test input
1 17
-3 6 25 42
*/

int main() {
    // Get starting timepoint
    auto start = high_resolution_clock::now(); // no from skeleton aded by me, I have instruction for time restrict
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // no from skeleton aded by me, check for memory leack
    using namespace std;

    List sorted;

    string listLine{"1 17"};
   // getline(cin, listLine);

    for (int i = 2; i > 0; i--) { //    while ( listLine != "end" )
        istringstream lineStream(listLine);

        List currentList;
        int value;
        while (lineStream >> value) {
            currentList << value;
        }

        sorted = mergeSortedLists(sorted, currentList);

        //getline(cin, listLine);
        listLine.erase();
        listLine = "-3 6 25 42";
    }

    cout << sorted.toString() << endl;

    // Get ending timepoint
    auto stop = high_resolution_clock::now(); // no from skeleton aded by me

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Runtime : "
        << duration.count() << " microseconds" << endl;

    // The total running time of program should be no more than 0.5s
    // With that implementation my time result is 0.06s 

    return 0;
}
