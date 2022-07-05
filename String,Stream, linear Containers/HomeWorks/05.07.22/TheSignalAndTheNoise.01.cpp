#include <iostream>
#include <string>
#include <sstream>

int removeNoise(const std::string& str)
{
    int answer{0};
    if (str.size() == 0)
    {
        answer = 0;
        return answer;
    }
    std::string answer_str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
        {
            answer_str += str[i];
        }
    }
    answer = std::stoi(answer_str);
    return answer;
}


int main()
{
    std::string input;
    std::getline(std::cin,input);

    std::istringstream in(input);
    std::string partition;
    int output{0};
    while (in>>partition)
    {
        int process{ removeNoise(partition) };
        if (output < process)
        {
            output = process;
        }
    }

    std::cout<<output<<'\n';

    return 0;
}