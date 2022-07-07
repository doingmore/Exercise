#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class MyList
{
private:
    std::vector<std::string> m_line;
public:
    MyList(const std::vector<std::string>& line) : m_line{ line }
    {}

    void forwardPreArranging(const int& n)
    {
        for (int i = 0; i < n; i++)
        {
            std::string lastElement = m_line[m_line.size() - 1];

            for (size_t i = m_line.size()-1; i > 0; i--)
            {
                m_line[i] = m_line[i - 1];
            }

            m_line[0] = lastElement;

        }
    }

    void print()
    {
        for (const std::string& s : this->m_line)
        {
            std::cout << s << '\n';
        }
    }

};

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream in(input);
    input.clear();

    std::vector<std::string> line;
    while (in>>input)
    {
        line.push_back(input);
        input.clear();
    }

    MyList object{line};
    int numberforwardPosition{ 0 };
    std::cin >> numberforwardPosition;

    object.forwardPreArranging(numberforwardPosition);
    object.print();
    

    return 0;
}
