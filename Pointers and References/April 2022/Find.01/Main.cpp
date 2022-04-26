#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Company.h"

#include "Find.h"

int main() {
	using namespace std;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF  ); // this line added by Svetozar, check for memory leak, exercise

	vector<Company*> companies;

	string line;
	while (getline(cin, line) && line != "end") {
		istringstream lineIn(line);

		Company* c = new Company();
		lineIn >> *c;
		companies.push_back(c);
	}

	string searchIdLine;
	getline(cin, searchIdLine);
	int searchId = stoi(searchIdLine);

	Company* companyWithSearchedId = find(companies, searchId);

	if (companyWithSearchedId != nullptr) {
		cout << *companyWithSearchedId << endl;
	}
	else {
		cout << "[not found]" << endl;
	}

	for (auto companyPtr : companies) {
		delete companyPtr;
	}

	return 0;
}