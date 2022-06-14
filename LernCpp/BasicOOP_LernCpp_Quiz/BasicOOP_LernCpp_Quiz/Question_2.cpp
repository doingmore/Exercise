#include <iostream>
#include <cmath>

// Write a destructor for this class:


// skeleton
class HelloWorld
{
private:
	char* m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char* init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		// write here your implementation 
		delete m_data;
		m_data = NULL;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}

};

int main()
{
	HelloWorld hello{};
	hello.print();

	return 0;
}
// skeleton 