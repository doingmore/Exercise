#include <iostream>
#include <vector>
#include <list>

void printProduct(std::vector<std::pair<std::string, double> >& vecList, double& price ) // with this sum price
{
    std::vector<std::pair<std::string, double> >::iterator it;
    for (it = vecList.begin(); it != vecList.end(); it++)
    {
        if (it->second == price)
        {
            std::cout << it->first << " " << it->second << '\n';
            break;
        }
    }
}

int main_Exam_Problem1()
{
    int numberProducts{ 0 };
    std::cin >> numberProducts;
    std::vector<std::pair<std::string,double> > vecList;
    std::list<double> orderedList;
    std::string name;
    double price;
    double sum;
    double totalSum{ 0 };
    int count;
    for (size_t i = 0; i < numberProducts; i++)
    {
        std::cin >> name >> price >> count;
        sum = count * price;
        vecList.emplace_back(std::pair<std::string,double>(name,sum));
        orderedList.push_back(sum);
        totalSum += sum;
    }
    orderedList.sort();
    std::cout << "The total sum is: " << totalSum << " lv." << '\n';

    std::list<double>::iterator it= orderedList.end();
    for (size_t i = orderedList.size(); i > 0; i--)
    {
        it--;
        printProduct(vecList , *it );
    }

    return 0;
}
