#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
using namespace std;

/************************************************************************
 * Project 1 * CPSC 474 (M/W 8:30AM) * Professor Doina Bein * 10/9/2020 *
 ************************************************************************
 * Mason Godfrey (mgodfrey@csu.fullerton.edu)
 * Bijaya Shrestha (sthavjay@csu.fullerton.edu)
 ************************************************************************
 * header.h
 ************************************************************************
 * col - The number of columns each array should have
 * row - The number of rows each array should have
 *
 * ex1Events[row][col] - An event sequence to find the LC values for
 * ex1Clock[row][col]  - First LC matrix to verify
 * ex2Clock[row][col]  - Second LC matrix to verify
 * ex3Clock[row][col]  - Third LC matrix to verify
 ************************************************************************/

//Checking with provided examples
const int col = 4; //columns
const int row = 3; //rows

//Event sequence
string ex1Events[row][col] =	 {	{"a", 	"s1",  	"r3",	"b"	},
									{"c",  	"r2",  	"s3",		},
									{"r1", 	"d", 	"s2",	"e"	}	};

//Clocks with logical sequence
int ex1Clock[row][col] = 	{	{1, 2, 8, 9},
								{1, 6, 7, 0},
								{3, 4, 5, 6}	};

int ex2Clock[row][col] = 	{	{1, 2, 8, 9},
								{1, 6, 7, 0},
								{2, 3, 4, 5}	};

int ex3Clock[row][col] = 	{	{1, 2, 8, 9},
								{1, 6, 7, 0},
								{2, 4, 5, 6}	};

//Checking with new examples (N = 5)
/*
const int col = 4; //columns
const int row = 5; //rows

string ex1Events[row][col] =	 {	{"a", 	"s1",  	"r3",	"r4"	},
									{"c",  	"r2",  	"s3",			},
									{"r1", 	"d", 	"s2",	"e"		},
									{"f", 	"g", 	"h", 	"i"		},
									{"j", 	"r2", 	"k", 	"s4"	}	};

int ex1Clock[row][col] = 	{	{1, 2, 3, 4},
								{2, 3, 4, 5},
								{3, 4, 5, 6},
								{5, 6, 7, 8},
								{6, 7, 8, 9}};
*/

#include "OutputArray.h"
#include "AlgorithmCalculate.h"
#include "AlgorithmVerify.h"

#endif /* HEADER_H_ */
