#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void getInput(std::vector<std::string>& list)
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream in(input);
    input.clear();
    while (in>>input)
    {
        list.push_back(input);
        input.clear();
    }
}

std::string filteringPunctuation(const std::string& s)
{
    std::string answer;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (std::isalpha(s[i]))
        {
            answer += s[i];
        }
    }
    return answer;
}

bool checkForPunctuation(const std::string& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isalpha(s[i]))
        {
            return true;
        }
    }
    return false;
}

void doReplace(std::vector<std::string>& list, const std::string& find, const std::string& replace)
{
	for (std::string& str : list)
	{
		std::string comparer{ str };
		char punctuation;
		bool flag{ checkForPunctuation(comparer) };
		if (flag)
		{
			comparer = filteringPunctuation(comparer);
			if (comparer == find)
			{
				int lastChar = str.size() - 1;
				punctuation = str[lastChar];
			}
		}


		if (comparer == find && flag)
		{
			str.clear();
			str = replace;
			str += punctuation;
		}
		else if (comparer == find)
		{
			str.clear();
			str = replace;
		}
	}
}

int main()
{
    std::vector<std::string> list;
    getInput(list);
    std::string find;
    std::string replace;
    std::cin >> find;
    std::cin >> replace;

    doReplace(list,find,replace);

    for (const std::string& s : list)
    {
        std::cout << s << " ";
    }

    return 0;
}
