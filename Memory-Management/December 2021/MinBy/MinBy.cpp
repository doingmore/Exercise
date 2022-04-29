#include <iostream>
#include <sstream>

#include "MinBy.h"
#include "ClassCharacteristic.h"

std::string checkForFirstCriteria(std::stringstream& stream)
{ // finds the string that is earliest lexicographically
	std::string localAnswer;
	std::string checkWord;
	std::string earliestLex="z"; // last letter 
	while (stream >> checkWord)
	{
		if (checkWord < earliestLex)
		{
			earliestLex = checkWord;
		}
	}
	localAnswer=earliestLex;
	return (localAnswer);
}

std::string checkForSecondCriteria(std::stringstream& stream)
{ // finds the shortest string

	std::string localAnswer;
	std::string checkWord;
	std::string minLength = "Pneumonoultramicroscopicsilicovolcanoconiosis+1";  //longest word in English lenguage + 1
	while (stream >> checkWord)
	{
		if (checkWord.size() < minLength.size())
		{
			minLength = checkWord;
		}
	}

	ClassCharacteristic member = ClassCharacteristic(minLength);
	ClassCharacteristic* ptr = &member; // Pointer to this member

	localAnswer = ptr->getSpecs();

	return (localAnswer);
}

std::string checkForThirdCriteria(std::stringstream& stream)
{ //finds the longest string
	std::string localAnswer;
	std::string checkWord;
	std::string maxlength = "a";   
	
	while (stream >> checkWord)
	{
		if (checkWord.size() > maxlength.size())
		{
			maxlength = checkWord;
		}
	}

	ClassCharacteristic member = ClassCharacteristic(maxlength);
	ClassCharacteristic* ptr = &member; // Pointer to this member

	localAnswer = ptr->getSpecs();

	return (localAnswer);
}