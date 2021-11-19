#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
You are given a sequence of strings, each on a new line. Every odd line on the console is representing a resource (e.g. Gold, Silver, Copper, and so on),
and every even – quantity. Your task is to collect the resources and print them each on a new line.
Print the resources and their quantities in format:
{resource} –> {quantity}
The quantities inputs will be in the range [1 … 2 000]
*/

int main()
{
    string input;
	int quantity{ 0 };
	map<string, int> resources;

	while (1)
	{
		cin >> input;
		if (input == "stop")
		{
			break;
		}
		cin >> quantity;
		
		if (resources.count(input)) //searching input key in map
		{
			resources[input] = resources[input]+quantity;
		}
		else if (input == "gold")
		{
			resources.insert(pair<string, int>("gold", quantity));
		}
		else if (input == "silver")
		{
			resources.insert(pair<string, int>("silver", quantity));
		}
		else
		{
			resources.insert(pair<string, int>("copper", quantity));
		}
	}

	map<string, int>::iterator it;
	for (it = resources.begin(); it != resources.end(); it++)
	{
		cout <<it->first<<" => "<<it->second<< '\n';
	}

    return 0;
}