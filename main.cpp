#include "header.h"

/************************************************************************
 * Project 1 * CPSC 474 (M/W 8:30AM) * Professor Doina Bein * 10/9/2020 *
 ************************************************************************
 * Mason Godfrey (mgodfrey@csu.fullerton.edu)
 * Bijaya Shrestha (sthavjay@csu.fullerton.edu)
 ************************************************************************
 * main.cpp
 ************************************************************************
 *
 * OutputHeader() - void
 * Outputs a short header with the authors and a brief explanation of
 * the program.
 *
 * main() - returns integer
 * Given a Matrix of events, output it's corresponding LC-Values.
 * Given 3 Matrices of LC-Values, output the corresponding Event Matrix.
 *
 ************************************************************************/

void OutputHeader()
{
	cout 	<< "************************************************************************" << endl
			<< "* Project 1 * CPSC 474 (M/W 8:30AM) * Professor Doina Bein * 10/9/2020 *" << endl
			<< "************************************************************************" << endl
			<< "* Mason Godfrey (mgodfrey@csu.fullerton.edu)" << endl
			<< "* Bijaya Shrestha (sthavjay@csu.fullerton.edu)" << endl
			<< "************************************************************************" << endl
			<< "* Given a Matrix of events, output it's corresponding LC-Values." << endl
			<< "* Given 3 Matrices of LC-Values, output the corresponding Event Matrix." << endl
			<< "************************************************************************" << endl << endl;
}

int main()
{
	const bool OUTPUT_HEADER = true;
	if(OUTPUT_HEADER)
		OutputHeader();
	//Checking with provided examples
	OutputArray(ex1Events, "Matrix of Events (1)");
	cout << "Algorithm Calculate (1)" << endl;
	AlgorithmCalculate(ex1Events);

	OutputArray(ex1Clock, "Matrix of LC-Values (1)");
	cout << "Algorithm Verify (1)" << endl;
	AlgorithmVerify(ex1Clock);

	OutputArray(ex2Clock, "Matrix of LC-Values (2)");
	cout << "Algorithm Verify (2)" << endl;
	AlgorithmVerify(ex2Clock);

	OutputArray(ex3Clock, "Matrix of LC-Values: (3)");
	cout << "Algorithm Verify (3)" << endl;
	AlgorithmVerify(ex3Clock);

	//Checking with new examples (N = 5)
/*
	OutputArray(ex1Events, "Matrix of Events (1)");
	cout << "Algorithm Calculate (1)" << endl;
	AlgorithmCalculate(ex1Events);

	OutputArray(ex1Clock, "Matrix of LC-Values: (3)");
	cout << "Algorithm Verify (3)" << endl;
	AlgorithmVerify(ex1Clock);
*/
	return 0;
}
