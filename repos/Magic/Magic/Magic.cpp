//Ryan Routhier
//05/22/2019
// MagicSquare.cpp week 2 assignment
//CIS 1202
/*This program takes a input text file (inputText.txt) and uses that data to make magic squares. A magic square is a square that all rows, columns and diagonal lines equal the same total.
All true and imposter magic squares will be marked accordingly. 
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//prototypes
int sumRow(int, int, int[][11]);
int sumCol(int, int, int[][11]);
int sumDiagonal1(int, int[][11]);
int sumDiagonal2(int, int[][11]);



int main()
{
	int a[11][11], n =0, square = 0, size =0, total;
	bool magic = true, loopBreak = true;
	ifstream inputFile("inputText");

	//Main While loop
	//inputFile reads in the size of the matrix
	while (inputFile >> size)
	{
		//always sets magic and loopBreak to true at start
		magic = true;
		loopBreak = true;
		//Output matrix size to use
		cout << "Matrix Size = " << size;
		cout << endl;

		//loop to complete a matrix to be checked
		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				//inputFile reads in data to the matrix
				inputFile >> a[x][y];
				//output matrix to user
				cout << right << setw(4) << a[x][y];

			}
			cout << endl;
		}

		//to calculate total to check numbers to
		total = ((1 + (size * size)) / 2) * size;
		
		//to break the loop when magic is found false
		while ((magic != false) &&  (loopBreak != false))
		{

			//loop for checking rows
			for (int i = 0; i < size; i++)
			{
				//calls function sumRow and checks against total
				if (sumRow(i, size, a) != total)
				{
					magic = false;
				}
			}
			{
				//loop for checking columns
				for (int i = 0; i < size; i++)
				{
					//calls function sumCol and checks against total
					if (sumCol(i, size, a) != total)
					{
						magic = false;
					}
				}
			}
			//checks first diagonal against total
			if (sumDiagonal1(size, a) != total)
			{
				magic = false;
			}
			//checks other diagonal against total
			if (sumDiagonal2(size, a) != total)
			{
				magic = false;
			}
			loopBreak = false;
		}
			//to output to user if it's a magic square
			if (magic != false)
			{
				cout << "MAGIC SQUARE\n" << endl;
			}
			else if (magic == false)
			{
				cout << "** NOT A MAGIC SQUARE **\n" << endl;
			}

		
	}

}

//to check the sum of the rows
int sumRow(int row, int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[row][i];
	}
		return total;
// to check the sum of the columns
}int sumCol(int col, int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][col];
	}

		return total;
	
}
// To check the sum of the first Diagonal line
int sumDiagonal1(int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][i];
	}
	return total;
}
// To check the sum of the other Diagonal line
int sumDiagonal2(int n, int s[][11])
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += s[i][n - i - 1];
	}
		return total;
	
}