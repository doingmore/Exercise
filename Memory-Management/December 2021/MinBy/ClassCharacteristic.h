#ifndef ClassCharacteristic_h
#define ClassCharacteristic_h
#include <iostream>
#include <string>

class ClassCharacteristic
{
private:
	std::string m_specs;
public:
	ClassCharacteristic(std::string specs)
	{
		m_specs = specs;
	}

	std::string getSpecs() { return  m_specs; };
};


#endif // !ClassCaracteristic

