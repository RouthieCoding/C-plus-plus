// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
void loadArrays(string[], double[], int&);
void showArrays(string[], double[], int);
void lookUpTaxes(string[], double[], int);
void sortTaxes(string[], double[], int);
void biggestTaxes(string[], double[], int);


int main()
{
	int length;
	double amtDue[7];
	string address[7];

	loadArrays(address, amtDue, length);
	return 0;
}

void loadArrays(string[], double[], int&)
{
	int i;
	double amtDue[7];
	string address[7];
	ifstream inputFile("prog3");

	while (inputFile >> address[i] >> amtDue[i])
	{
		i++;
		cout << address[i] << amtDue[i];
	}
}
void showArrays(string[], double[], int)
{

}
void lookUpTaxes(string[], double[], int)
{

}
void sortTaxes(string[], double[], int)
{

}
void biggestTaxes(string[], double[], int)
{

}
