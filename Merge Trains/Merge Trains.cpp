#include<vector>
#include<sstream>
#include <iostream>
#include<string>
#include<list>
#include<queue>
#include<map>

using namespace std;

/*
At a certain train station, trains arrive on two tracks – Track A and Track B – and are merged onto a single track. 
Each railcar has a number, and in each train the railcars are ordered by number – the front railcar has the lowest number,
the back railcar has the highest number. Given the railcar numbers on Track A and Track B, given from the back car to the front car,
output the order in which railcars from Track A and Track B should be merged into the single track, then output the new train 
configuration, starting from the last railcar, and finishing at the first railcar. Railcars are moved starting from the front
to the back (i.e. you can only move the front car of a train). Each time you move a railcar from the parallel tracks A and B to the merge track,
it pushes forward any railcars that are already there. The first line of the console will contain the numbers of the railcars on Track A, from 
the last railcar to the first railcar. The second line of the console will contain the numbers of the railcars on Track B, from the last railcar
to the first railcar.If a railcar from Track A should be moved to the single track, print A. Otherwise, print B. On a separate line print the final
configuration of the train (numbers separated by spaces, representing the railcar numbers from the last railcar to the first). The “input” railcars will
always be correctly ordered (i.e. will be a line of descending positive integer numbers). The input will be such that the result will 
never have any railcars with the same numbers.
*/

void read(vector<pair<int, char>>& myvec, char c) {
    string line;
    getline(cin, line);
    stringstream str(line);
    int n;
    while (str >> n)
    {
        myvec.emplace_back(n, c);
    }

}

int main()
{
    vector<pair<int, char>> myvec;
    read(myvec, 'A');
    read(myvec, 'B');

    sort(myvec.rbegin(), myvec.rend(), greater<pair<int, char>>());

    for (auto n : myvec)
    {
        cout << n.second;
    }
    cout << endl;
    for (vector<pair<int, char>>::reverse_iterator it = myvec.rbegin(); it != myvec.rend(); it++)
    {
        cout << it->first << " ";
    }
}
