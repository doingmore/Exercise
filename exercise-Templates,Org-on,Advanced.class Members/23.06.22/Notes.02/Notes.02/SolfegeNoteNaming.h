#ifndef SOLFEGE_NOTE_NAMING_H
#define SOLFEGE_NOTE_NAMING_H


struct SolfegeNoteNaming
{
	char operator() (const std::string& noteText) const
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

		return '?';
	}

};


#endif // !SOLFEGE_NOTE_NAMING_H
