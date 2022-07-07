#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

class Sale
{
private:
    std::string m_town;
    std::map<std::string , std::pair<double , int> > m_map;

public:

    Sale(const std::string& town, std::map<std::string, std::pair<double, int> > map) : m_town{ town }, m_map{map}
    {}

    void addProduct(const std::string& s, const std::pair<double, int>& p)
    {
        m_map.emplace(s, p);
    }

    std::string getTown()const { return m_town; }
    double getProfitForAllTown() const
    {
        double answer{ 0 };
        for (const auto& it : m_map)
        {
            std::pair<double, int> pair(it.second);
            answer = answer + (pair.first * pair.second);
        }
        return answer;
    }

};


bool find(const std::vector<Sale>& v,const std::string& town)
{
    for (const Sale& s : v )
    {
        if (s.getTown() == town)
        {
            return true;
        }
    }
    return false;
}


void report(std::vector<Sale>& vec)
{
    struct sortByName
    {
        bool operator() (const Sale& left, const Sale& right)
        {
            return left.getTown() < right.getTown();
        }
    };
                                    
    std::sort(vec.begin(), vec.end(), sortByName() );  //[](const Sale& left, const Sale& right) {return left.getTown() < right.getTown(); }
    for (const Sale& o : vec)
    {
        std::cout << o.getTown() << " -> " << o.getProfitForAllTown() << '\n';
    }
}

int main()
{
    int number_iteration{ 0 };
    std::cin >> number_iteration;
    std::cin.ignore();
    std::vector<Sale> vec;
    for (int i = 0; i < number_iteration; i++)
    {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream in(input);
        
        std::string town;
        std::string product;
        double price;
        int count;
        in >> town;
        in >> product;
        in >> price;
        in >> count;

        if (!find(vec,town))
        {
            std::map<std::string, std::pair<double, int> > map;
            std::pair<double, int> paiR (price, count);

            map.emplace(product, paiR);

            vec.emplace_back(Sale{town,map});
        }
        else
        {
            for (Sale& s : vec)
            {
                if (s.getTown() == town)
                {
                    std::pair<double, int> paiR(price, count);
                    s.addProduct(product,paiR);
                    

                }
            }
        }
    }

    report(vec);

    return 0;
}
