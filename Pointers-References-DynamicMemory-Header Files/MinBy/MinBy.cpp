#include <iostream>
#include <sstream>

#include "MinBy.h"
#include "ClassCharacteristic.h"


std::string checkWordCharacteristic(std::stringstream *stream)
{
	std::string localAnswer;
	std::string checkWord;
	std::string maxlength="a";   // Given the task, I understand that this is the criterion of the highest priority
	std::string earliestLex="z"; // last letter 
	std::string minLength="Pneumonoultramicroscopicsilicovolcanoconiosis+1";  //longest word in English lenguage + 1
	while ( (*stream) >> checkWord )
	{
		if (checkWord.size() >= maxlength.size())
		{
			if (checkWord < earliestLex)
			{
			maxlength = checkWord;
			earliestLex=checkWord;
			}
		}
		if (checkWord.size() < minLength.size()) // for minimum length word
		{
			minLength = checkWord;
		}
	}

	ClassCharacteristic member= ClassCharacteristic(maxlength, earliestLex, minLength);
	ClassCharacteristic *ptr = &member; // Pointer to this member

	localAnswer= ptr->getLong() ;
	
	return (localAnswer);
}



