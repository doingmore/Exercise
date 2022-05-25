#include <iostream>
#include <string>
#include <vector>

#include "NoteName.h"
#include "SolfegeNoteNaming.h"

template<typename Naming>
class NoteParser {
	Naming translator; // naming is solfegenotenaming // Do Re Mi Fa Sol La Si unknown end
public:
	NoteName translate(const std::string& noteText) const {
		return translator(noteText); // overloading operator() for NoteName objects
	}
};

int main() {
	NoteParser<SolfegeNoteNaming> parser;

	std::vector<NoteName> notes;
	std::string noteText;
	while (std::cin >> noteText && noteText != "end") {
		NoteName note = parser.translate(noteText);
		notes.push_back(note);
	}

	for (NoteName note : notes) {
		std::cout << note << " ";
	}

	return 0;
}