#ifndef SERIALIZE_H
#define SERIALIZE_H
#include <string>
#include <sstream>
#include <vector>

#define begin 0

/*
188 icyha (B.Q.,H.P.,F.S.)
58 uadel (S.A.,C.H.,L.T.)
end
*/

int getNumberOfCompanies(const std::string& s)
{
	int answer{ 0 };
	for(int i=begin ; i < s.size(); i++)
	{
		if (s[i] == '\n') // number of newLines is equal to number of companies
		{
			answer++;
		}
	}
	return answer;
}

int getNumberCapitalLetter(const std::string& s)
{
	int answer{ 0 };
	for (size_t k = 0; k < s.size(); k++) // get only capital letters
	{
		if (64 < s[k] && s[k] < 91)
		{
			answer++;
		}
	}
	return answer;
}

int getLengthForArray(const std::string& s,const int& numberOfCompanies)
{
	int answer{ 0 };
	answer++; // first place for number of companies
	std::istringstream in(s);
	int id;
	std::string name;
	std::string pair;
	for (size_t i = 0; i < numberOfCompanies; i++)
	{
		in >> id;
		answer++;

		in >> name;
		answer = answer + name.size();

		answer++; // place for 0 terminate name
		answer++; // place for number of employees

		in >> pair;
		answer = answer + getNumberCapitalLetter(pair);
	}
	return answer;
}




byte* serializeToMemory(const std::string& input, size_t& length_bytesWritten)
{
	byte* answer = NULL;
	int numberCompanies{ getNumberOfCompanies(input) };
	int sizeOfDinamicArray{ getLengthForArray(input,numberCompanies) };
	length_bytesWritten = sizeOfDinamicArray;

	answer = new byte[sizeOfDinamicArray]{};
	int index{ begin };
	answer[index] = numberCompanies; // first place is for number of companies
	index++;

	std::istringstream in(input);
	int id;
	std::string name;
	std::string pair;
	for (size_t i = 0; i < numberCompanies; i++)
	{
		in >> id;
		answer[index] = id;
		index++;

		in >> name;
		for (size_t k = 0; k < name.size(); k++)
		{
			answer[index] = name[k];
			index++;
		}

		answer[index] = (int) 0; // terminate name
		index++;

		in >> pair;
		answer[index] = ( getNumberCapitalLetter(pair) / 2 ); // number of employees
		index++;

		for (size_t u = 0; u < pair.size(); u++)
		{
			if (64 < pair[u] && pair[u] < 91)
			{
				answer[index] = pair[u];
				if (index < sizeOfDinamicArray)
				{
					index++;
				}
			}
		}
	}

	return answer;
}


#endif // !SERIALIZE_H
