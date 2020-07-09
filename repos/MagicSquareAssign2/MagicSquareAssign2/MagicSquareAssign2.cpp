// MagicSquareAssign2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
void readSquare(int, int[10][10]);
void printSquare(int, int[10][10]);

int main()
{
	int n, square[10][10];

	ifstream inputFile("Prog2Input");
	while (inputFile >> n)
	{
		readSquare(n, square);
		printSquare(n, square);
	}
		cout << "test";
	
}
void readSquare(int n, int square[10][10])
{
	int size = n;

	//cout << n;
	//n >> size;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			n >> square[x][y];
	
		}
	}
	//for (int x = 0; x < n; x++)
	//{
	//	for (int y = 0; y < n; y++)
	//	{
	//		;
	//	}
	//}
	//cout << endl;
}
void printSquare(int n, int square[10][10])
{
	//cout << n;
	for (int x = 0; x < n; x++)
	{
		cout << endl;
		for (int y = 0; y < n; y++)
		{
			cout << square[x][y] << " ";
		}
	}
	cout << endl;

}