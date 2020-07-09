// StringSplitter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void tokenize(const string& str, const string& delim, vector<string>& tokens)
{
	int tokenStart = 0;

	int delimPos = str.find_first_of(delim);

	while (delimPos != string::npos)
	{
		string tok = str.substr(tokenStart, delimPos - tokenStart);

		tokens.push_back(tok);

		delimPos++;

		tokenStart = delimPos;

		delimPos = str.find_first_of(delim, delimPos);

		if (delimPos == string::npos)
		{
			string tok = str.substr(tokenStart, delimPos - tokenStart);

			tokens.push_back(tok);
		}
	}
}
int main()
{
	string code;
	vector<string> tokens;
	tokenize(code, " .,:;!?", tokens);
}

