//------------------------------------------------------------
// Copyright:   Syed Shah 2014
//
// Task:	Given a string, write a routine that converts 
//		the string to a long, without using the built 
//		in functions that would do this. Describe what
//		(if any) limitations the code has
//
// IDE:		Visual Studio Express 2013
//
// Limitations: Compiler may throw a warning/error for values
//		outside the range of -2147483647 to 2147483647
//
//
// Assumptions	If the first index of the string contains a 
//		'-' operator, the program will assume that a 
//		string contains a negative number
//
//		All non-integers except a possible negative 
//		operator at the first index of the string will 
//		be ignored
//------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Convert a string to long and return the output
long stringToLong(const string & s)
{
	// Length of the input string
	int len = s.length();
	// Output to be returned
	long output = 0;
	// ASCII code value
	int ascii_begin = 48;
	int ascii_end = 57;

	for (long i = 0; i < len; i++)
	{
		// Ignore all non-integers
		if (s[i] >= ascii_begin && s[i] <= ascii_end)
		{
			output = output * 10 + (s[i] - '0');
		}
	}
	// Check for negative number
	if (s[0] == '-')
		output = output * -1;
	return output;
}

// Tests function for converting a string to long
void test(const string & s, long actualNumber)
{
	// Calling the function to do the conversion
	long output = stringToLong(s);

	// Compare the converted output with the actual number
	if (actualNumber == output)
		cout << "The operation was sucessful" << endl;
	else
		cout << "The operation failed" << endl;
}

int main(void)
{
	// Test Cases: Checking normal string
	test("123", 123);
	test("123456789", 123456789);

	// Test Cases: Checking string with spaces
	test("  1 23", 123);
	test("123  ", 123);

	// Test Cases: Checking string separated by comma
	test("1,2,3", 123);

	// Test Cases: Checking empty string
	test("", 0);
	test("", 1);
	
	// Test Cases: Checking string with different symbols
	test("123123,.++2~11", 123123211);
	
	// Test Cases: Checking limitations of long
	test("-2147483647", -2147483647);
	test("--123", -123);

	// Other Test Cases
	test("Hello World", 1234);
	test("+123", 123);

	system("pause");
	return 0;
}
