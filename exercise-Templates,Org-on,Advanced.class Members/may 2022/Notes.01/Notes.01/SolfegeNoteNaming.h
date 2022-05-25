#ifndef SOLFEGE_NOTE_NAMING_H
#define SOLFEGE_NOTE_NAMING_H

#include "NoteName.h"

struct SolfegeNoteNaming
{                                                           //C  D  E  F  G   A  B      ?
	NoteName operator() (const std::string& noteText) const //Do Re Mi Fa Sol La Si   unknown
	{
		if (noteText == "Do")
		{
			return 'C';
		}
		else if (noteText == "Re")
		{
			return 'D';
		}
		else if (noteText == "Mi")
		{
			return 'E';
		}
		else if (noteText == "Fa")
		{
			return 'F';
		}
		else if (noteText == "Sol")
		{
			return 'G';
		}
		else if (noteText == "La")
		{
			return 'A';
		}
		else if (noteText == "Si")
		{
			return 'B';
		}
		else if (noteText == "unknown")
		{
			return '?';
		}
		else
		{
			throw _EXCEPTION_;
		}
		return ' ';
	}

};

#endif // !SOLFEGE_NOTE_NAMING_H
