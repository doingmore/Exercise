#include <iostream>
#include <string>
using namespace std;

int main()
{
	int judgingPeople{ 0 };
	cin >> judgingPeople;
	string namePresentation;

	double assessment{ 0 }; // from one of judging people
	double sumAssessment{ 0 }; //from all judging people
	double assessmentStudent{ 0 }; //for one presentation
	int counter{ 0 }; //number presentation


	for (int i = 0; i < 1; counter++)
	{
		getline(cin, namePresentation);
		assessment, sumAssessment = 0;

		if (namePresentation == "finish")
		{
			break;
		}
		
		for (int j = 1 ; j <= judgingPeople; j++)
		{
			cin >> assessment;
			sumAssessment = sumAssessment + assessment;
		}
		assessmentStudent = assessmentStudent + (sumAssessment / judgingPeople);
		cout << namePresentation << " - " << (sumAssessment / judgingPeople) << '\n';
	}

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "student final assessment is : " << (assessmentStudent / counter);

	return 0;
}