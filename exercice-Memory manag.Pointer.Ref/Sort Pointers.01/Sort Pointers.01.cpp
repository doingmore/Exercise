#include <iostream>
#include <string>
#include <sstream>

#include "Company.h"

#include "SortBy.h"
//#include "SORT_BY_STL_SORT.h"


bool lessThanById(const Company& a, const Company& b) {
	return a.getId() < b.getId();
}

bool lessThanByName(const Company& a, const Company& b) {
	return a.getName() < b.getName();
}

int main() {
	using namespace std;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // this line added by me, check for memory leak, exercise
	vector<string> lines;
	string line;
	while (getline(cin, line) && line != "end") {
		lines.push_back(line);
	}

	int numCompanies = lines.size();
	Company** companyPtrs = new Company * [numCompanies];
	for (int i = 0; i < lines.size(); i++) {
		string line = lines[i];

		istringstream lineIn(line);
		string name;
		int id;
		lineIn >> name >> id;

		companyPtrs[i] = new Company(id, name);
	}

	string sortKey;
	cin >> sortKey;

	if (sortKey == "name") {
		sortBy(companyPtrs, companyPtrs + numCompanies, lessThanByName);
	}
	else if (sortKey == "id") {
		sortBy(companyPtrs, companyPtrs + numCompanies, lessThanById);
	}

	for (int i = 0; i < numCompanies; i++) {
		cout << companyPtrs[i]->toString() << endl;
	}

	// deallocated memory - added from me, because this step is forgotten in skeleton
	for (Company** i = companyPtrs; i != companyPtrs + numCompanies; i++)
	{
		delete *i;
	}

	delete[] companyPtrs;
	//
	return 0;
}