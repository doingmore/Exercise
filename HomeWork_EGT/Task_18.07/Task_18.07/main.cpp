#include <iostream>
#include <string>
#include <vector>

/*
1. translate number 
От клавиатурата се въвежда полужително двуцифрено число. Да се напише програма която извежда числото с думи
например при въвеждане на 54 да се изпринти "петдесен и четири"

2. getFactorial
Напиши рекурсивно програма която да прави факториел
демек 5! ти е равно на 5 * 4 * 3 * 2 * 1

3. powerOfTwo
да се напише програма която да проверява
дали дадено число е степен на двойката

4. numberOfDigits.
да се напише програма която да намира броя на цифрите на дадено число
примерно ако се виведе 51324 искам да ми изкара 5.

5. sumOfAllDigits = three
Да се напише програма която да проверява дали сумата на цифрите
на дадено положително число е равна на 3.
example 120
1 + 2 + 0 = 3  ==> true
*/

std::string translateNumber(const int& number)
{
	std::string answer;
	std::string tenth[]
	{
		" ",
		"teen",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};
	std::string units[]
	{
		" ",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",       //   18 --  without 't' 
		"nine"
	};

	int firstDigit{ number / 10 };
	int secondDigit{ number % 10 };
	if (firstDigit == 1)
	{
		if (secondDigit == 0)
		{
			answer = "ten";
		}
		else if (secondDigit == 1)
		{
			answer = "eleven";
		}
		else if (secondDigit == 2)
		{
			answer = "twelve";
		}
		else if (secondDigit == 3)
		{
			answer = "thirteen";
		}
		else
		{
			answer+=units[secondDigit];   // attention we work only with first word is a units
			if (secondDigit == 8)
			{
				answer.pop_back();       // 18 eighteen not eightteen  remove "t" 
			}
			answer+=tenth[firstDigit];    // second word always will be a "teen"
		}
	}
	else
	{
		answer += tenth[firstDigit];
		if (secondDigit != 0 )
		{
			answer += units[secondDigit];
		}
	}
	return answer;
}

int getFactorial(const std::string& input)  
{
	// for this example without protections for negative number

	int answer{ 0 };
	std::string number;
	for (size_t i = 1; i < input.size(); i++)  // remove first element "!"
	{
		number+= input[i];
	}
	int intNumber{ std::stoi(number) };        
	answer = intNumber;
	intNumber--;

	for (int i = intNumber; i > 1; i-- )
	{
		answer *= i;
	}

	return answer;
}

bool powerOfTwo(const int& number) // return true if the number is power of two
{
	double result = static_cast<double>(number);

	while (1) 
	{
		if (result == 2)  // right on 2
		{
			return true;
		}
		if (result < 2)
		{
			break;
		}

		result /= 2;
	}

	return false;
}

int getNumberOfDigits(const int& number)
{
	std::string str_numbers = std::to_string(number);
	return static_cast<int>(str_numbers.size());
}

bool sumOfAllDigits(const int& number) // return true if  the sum is equal to 3
{
	std::string str_numbers = std::to_string(number);
	int sum{ 0 };
	for (size_t i = 0; i < str_numbers.size(); i++)
	{
		int in{ str_numbers[i] - 48 };
		sum += in;
	}
	if (sum == 3)
	{
		return true;
	}
	return false;
}

int main()
{
	// Problem 1.
	/*
	int number{ 0 };
	std::cin >> number;
	std::cout << number <<' '<< translateNumber(number) << '\n';
	*/
	
	// Problem 2.
	/*
	std::string input;
	std::cin >> input;    
	std::cout<< input << " " << getFactorial(input)<<'\n';
	*/

	// Problem 3.      // ask about infinity loop in production
	/*
	int input;
	std::cin >> input;
	if (powerOfTwo(input))
	{
		std::cout << input << '\n';
		std::cout << "The input number is a power of 2." << '\n';
	}
	else
	{
		std::cout << "False => The input number is not a power of 2." << '\n';
	}

	// automatic print all numbers until 1024
	for (int i = 1; i < 1025; i++)
	{
		if (powerOfTwo(i))
		{
			std::cout <<i<< " power of 2." << '\n';
		}
	}
	*/

	// Problem 4.
	/*
	int input;
	std::cin >> input;
	std::cout << getNumberOfDigits(input) << '\n';
	*/

	// Problem 5.      // ask about signed/unsigned  using
	/*
	int input;
	std::cin >> input;
	if (sumOfAllDigits(input))
	{
		std::cout << "The input number have a sum of digits = 3." << '\n';
	}
	else
	{
		std::cout << "False => The input number no have a sum of digits = 3." << '\n';
	}
	*/

 	return 0;
}
