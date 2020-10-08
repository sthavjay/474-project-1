#include "header.h"

int main()
{
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

	cout << "Algorithm Calculate (1)" << endl;
	AlgorithmCalculate(ex1Events);
	cout << "Algorithm Verify (1)" << endl;
	AlgorithmVerify(ex1Clock);
	cout << "Algorithm Verify (2)" << endl;
	AlgorithmVerify(ex2Clock);
	cout << "Algorithm Verify (3)" << endl;
	AlgorithmVerify(ex3Clock);
	return 0;
}
