#ifndef SolfegeNoteNaming_H
#define SolfegeNoteNaming_H

#include "NoteName.h"
#include <string>

struct SolfegeNoteNaming
{
public:
	

	NoteName operator() (const std::string& note) const
	{
		NoteName answer=' ';
		if (note == "Do")
		{
			answer = 'C';
			return answer;
		}
		else if (note == "Re")
		{
			answer = 'D';
			return answer;
		}
		else if (note == "Mi")
		{
			answer = 'E';
			return answer;
		}
		else if (note == "Fa")
		{
			answer = 'F';
			return answer;
		}
		else if (note == "Sol")
		{
			answer = 'G';
			return answer;
		}
		else if (note == "La")
		{
			answer = 'A';
			return answer;
		}
		else if (note == "Si")
		{
			answer = 'B';
			return answer;
		}
		else
		{
			answer = '?';
			return answer;
		}
	}



};


#endif // !SolfegeNoteNaming_H
