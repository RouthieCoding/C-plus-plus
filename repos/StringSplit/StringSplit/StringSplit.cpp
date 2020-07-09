//Ryan Routhier
// StringSplit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//7/30/2019
/*This program takes in a expression from the user the and runs it through a function. That function breaks down the expression into each of it's elements and also
retuns that to the user line by line in reverse order
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// vector function to break the string down into different parts
vector<string> split(const string& s)
{
	int i = 0, n = 0;
	vector<string> tokens;
	string token, holder;
	char  stringHolder[50];

	// copies string s into stringHolder
	strcpy(stringHolder, s.c_str());

;
//loop that runs until it finds a null terminator
	while (stringHolder[i] != '\0')
	{
		//x is a easy variable to change out
		char x = stringHolder[i];

		// to find if the string is a number
		if (x >= '0' && x <= '9')
		{
			//if it is a number build a string
			holder += stringHolder[i];
			if (x == '\0')
			{
				// add string to the vector
				tokens.push_back(holder);
			}
		}

		//hold a ( in token to be added to vector
		else if (x == '(')
		{
			holder = "(";
		}

		//hold a ) in token to be added to vector
		else if (x == ')')
		{
			holder = ")";
		}

		//hold a + in token to be added to vector
		else if (x == '+')
		{
			holder = "+";
		}
		
		//hold a - in token to be added to vector
		else if (x == '-')
		{
			holder = "-";
		}
		//hold a ( in token to be added to vector
		else if (x == '/')
		{
			holder = "/";
		}
		//hold a * in token to be added to vector
		else if (x == '*')
		{
			holder = "*";
		}
		//if a space is found then what is in the string holder is added to the vector
		else if (x == ' ')
		{

			tokens.push_back(holder);
			holder = "";
		}

		//if a null terminator is found then what is in the string holder is added to the vector
		if (stringHolder[i] == '\0')
		{
			tokens.push_back(holder);
		}
		//increments the while loop to search through a string
		i++;
	}
	//returns vector to main
	return tokens;
}
int main()
{
	string expression;
	vector<string> holder;

	//allows user to enter an expression
	cout << "Enter an expression: ";
	getline(cin, expression);
	
	//outputs that selection
	cout << expression;
	//calls function to split expression up
	holder = split(expression);
	
	//outputs to user the broken up expression in reverse
	cout << "Here is your expression in reverse: \n";
	reverse(holder.begin(), holder.end());

	for (int i = 0; i <= holder.size() - 1; i++)
	{
		cout << holder[i] + "\n";
	}

}