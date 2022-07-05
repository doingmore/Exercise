#include <iostream>
#include <string>
#include <sstream>




int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream in(input);
    int output_int{ 0 };
    std::string output_str;
    
    
    std::string process;
	while (in >> process)
	{
		if (std::isalpha(process[0]))
		{
			output_str += process;
			output_str += ' ';
		}
		else
		{
			int number{ std::stoi(process) };

			output_int += number;

		}
	}

    std::cout << output_int << '\n' << output_str << '\n';

    return 0;
}
