//Ryan Routhier
//05/22/2019
// MagicSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//prototypes
void readSquare(int, int);
void printSquare(int, int);
int sumRow(int, int , int[]);
int sumCol(int, int , int[]);
int sumDiagonal1(int, int[][11]);
int sumDiagonal2(int, int[][11]);



int main()
{
	int a[10][10], n, square = 0, size;

	ifstream inputFile("inputText");

	inputFile >> size;
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			inputFile >> a[x][y];
		}
	}
	int total = ((1 + (size * size)) / 2) * size;
	for (int i = 0; i < size; i++)
		if (sumRow(i, size, a)) {
			cout << "not magic";
		}
	for (int i = 0; i < size; i++)

		if (sumCol(i, size, a))
			cout << "not magic";

	if (sumDiagonal1(size, a[][11]) != total);

}


void readSquare(int n, int square)
{
	int a[][10];
	cout << n << endl;
	if (n == 3)
	{
		a[][10];
		return;
	}
}
void printSquare(int n, int square)
{
	for (int i = 0; i < n; i++)
	{
		cout << n;
		for (int x = 0; x < n; x++)
		{
			cout << n << endl;
		}
	}
}
int sumRow(int row, int n, int s[])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[row][i];

		return total;
	}
}int sumCol(int col, int n, int s[])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][col];
		return total;
	}
}
int sumDiagonal1(int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][i];
		return total;
	}
}int sumDiagonal2(int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][n - i - 1];
		return total;
	}
}
//while (inputFile >> n)
//{
//	readSquare(n, square);
	//printSquare(n, square);
	//if (checkMagic(n, square))
	//	cout << "MAGIC SQUARE\n\n";
	//else
	//	cout << "** NOT A MAGIC SQUARE **\n\n";