#ifndef OUTPUTARRAY_H_
#define OUTPUTARRAY_H_

#include "header.h"

/************************************************************************
 * Project 1 * CPSC 474 (M/W 8:30AM) * Professor Doina Bein * 10/9/2020 *
 ************************************************************************
 * Mason Godfrey (mgodfrey@csu.fullerton.edu)
 * Bijaya Shrestha (sthavjay@csu.fullerton.edu)
 ************************************************************************
 * OutputArray.h
 ************************************************************************
 *
 * OutputArray(Var array) - Returns integer
 * Outputs an array, of any variable type, to the user.
 * array - Array to be output.
 *
 * OutputArray(Var array, string message) - Returns integer
 * Outputs a message to the user, then calls OutputArray(Var array).
 * array - Array to be output.
 * message - Message to be output.
 *
 ************************************************************************/

//General
template <class Var>
int OutputArray(Var array)
{
	//For every row and column, output every item
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << setw(5) << array[i][j];

		cout << endl;
	}
	cout << endl;
	return 0;
}

//Wrapper for OutputArray; this allows a message to be output before the array is
template <class Var>
int OutputArray(Var array, string message)
{
	//Output message that was passed in
	cout << message << endl;

	//Output the array
	OutputArray(array);
	return 0;
}


#endif /* OUTPUTARRAY_H_ */
