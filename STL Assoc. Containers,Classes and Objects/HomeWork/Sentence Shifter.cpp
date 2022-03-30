#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class shift
{
private:
	std::vector<std::string> m_data;
public:
	shift(const std::string& str)
	{
		std::stringstream stream{ str };
		std::string word;
		while (stream >> word)
		{
			m_data.push_back(word);
			word.erase();
		}
	}

	void movingForward(const int& numberTimes)
	{
		std::string temporary;
		for (int i = 0; i < numberTimes; i++)
		{
			temporary = m_data[m_data.size()-1];
			for (size_t i = m_data.size()-1; i >= 1; i--)
			{
				m_data[i] = m_data[i - 1];
				if (i==1)
				{
					m_data[i-1]=temporary;
				}
			}
		}
	}

	void print() const
	{
		for (size_t i = 0; i < m_data.size(); i++)
		{
			std::cout << m_data[i] << '\n';
		}
	}
};

int main_10()
{
	std::string input;
	std::getline(std::cin, input);
	shift array{ input };

	int position{ 0 };
	std::cin >> position;

	array.movingForward(position);

	array.print();

	return 0;
}