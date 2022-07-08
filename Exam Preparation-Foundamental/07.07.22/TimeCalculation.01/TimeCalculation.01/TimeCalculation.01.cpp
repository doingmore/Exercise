#include <iostream>



int main()
{
	int hours;
	int minutes;
	int seconds;

	std::cin >> hours;
	std::cin >> minutes;
	std::cin >> seconds;

	int totalTimeinHours{ (seconds/60/60) + (minutes/60) + hours };
	int totalTimeinMinutes{ (seconds/60) + minutes + (hours * 60) };
	int totalTimeinSeconds{seconds+ ( minutes*60 ) + ( hours * 60 * 60 ) };


	std::cout << totalTimeinHours << '\n';
	std::cout << totalTimeinMinutes << '\n';
	std::cout << totalTimeinSeconds << '\n';

	return 0;
}
