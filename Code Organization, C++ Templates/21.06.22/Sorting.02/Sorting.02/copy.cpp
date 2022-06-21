/*


template <typename C>
void printContainer(typename C::iterator begin , typename C::iterator end)
{
	while (begin != end)
	{
		std::cout << *begin <<" ";
		begin++;
	}
}




template<typename U>
class LessThan
{
public:
	const bool operator() (const U& left, const U& right) const
	{
		return left < right;
	}
};



template<typename U,typename LessThan>
class Reverse
{
public:
	const bool operator() (const U& left, const U& right) const
	{
		LessThan object;
		return !object(left, right);
	}
};



template<typename T>
class Parser
{
private:
	std::string m_stopLine;
public:
	Parser(std::istream& stream, std::string& stop) : m_stopLine{stop}
	{}

	bool readNext(T& object)
	{
		std::string input;
		std::getline(std::cin, input);
		if ( input != m_stopLine )
		{
			std::istringstream in( input );
			in >> object;
			return true;
		}
		return false;
	}
};




*/