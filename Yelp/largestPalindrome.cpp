/*
string -> f -> largest palindrome within that string

f("abbacheese") -> "abba"
f("adbacheese") -> "ese"
f("abcdefghij") -> "a" OR "b" OR "c" OR ... OR "j"
f("a") -> "a"
f("aabb") -> "aa" OR "bb"
*/

//f("abba") -> "abba"
#include <iostream>
#include <string>

using namespace std;

string palindrome(const char *input, const int size, int i, int j)
{
	string output = "";
	int l = i;
	int r = j;
	while (l <= j)
	{
		if (input[r] == input[l])
			output = output + input[r];
		else
			return "";
		r--;
		l++;
	}
	return output;
}

int main()
{
	char input[] = "abbacheese";
	int size = strlen(input);
	string output = "";
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			string tmp = palindrome(input, size, i, j);
			if (tmp.length() > output.length())
				output = tmp;
		}
	}
	cout << "The longest palindrome is " << output << endl;

	system("pause");
	return 0;
}
