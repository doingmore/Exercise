#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

/*
Read a list of real numbers and print them in ascending order along with their number of occurrences.
*/

void Problem1()
{
	map<double, int> map;
	string numbers;
	getline(cin, numbers);
	stringstream stream(numbers);
	double n{ 0 };

	while (stream >> n)
	{
		if (map.count(n))
		{
			map[n]++;
		}
		map.insert(pair<double, int>(n, 1));
	}

	std::map<double, int>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		cout << it->first << " " << it->second << '\n';
	}
}