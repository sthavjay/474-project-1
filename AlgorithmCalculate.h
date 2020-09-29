/*
 * AlgorithmCalculate.h
 *
 *  Created on: Sep 23, 2020
 *      Author: bijay
 */

#ifndef ALGORITHMCALCULATE_H_
#define ALGORITHMCALCULATE_H_

#include "header.h"
#include <string>
int AlgorithmCalculate(string eventSequence[][col])
{
	int k = 0; //k is the value immediately before a in the same row
	int logicClock[row][col];	//This will store our logic clock


	/******
	 * PROBLEM 1
	 ******/
	int responsePts[row];

	//Initialize logicClocks to 0, Initialize responsePts to -1
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			logicClock[i][j] = 0;
		}
		responsePts[i] = -1;
	}

	bool done = false;

	while(!done)
	{
		//Travels each row
		for(int i = 0; i < row; i++)
		{
			//Travels each column
			for(int j = 0; j < col && (j < responsePts[i] || responsePts[i] < 0); j++)
			{
				//If we're not a response point or going past a response point, update our logic clock
				if(eventSequence[i][j].size() > 0 && eventSequence[i][j].at(0) != 'r' && logicClock[i][j] == 0)
					logicClock[i][j] = k + 1;
				//If we're a response point, keep track of where we are
				else if(eventSequence[i][j].size() > 1 && eventSequence[i][j].at(0) == 'r' && logicClock[i][j] == 0)
					responsePts[i] = j;
				//If we're a send point, try to send if possible
				if(eventSequence[i][j].size() > 1 && eventSequence[i][j].at(0) == 's')
					//For all rows, check if and where there is a response point, and update the logic clock if we find a response point before resetting it
					for(int respi = 0; respi < row; respi++)
						if(responsePts[respi] >= 0)
							if(eventSequence[respi][responsePts[respi]].at(1) == eventSequence[i][j].at(1))
							{
								logicClock[respi][responsePts[respi]] = max(logicClock[i][j] + 1, k);
								responsePts[respi] = -1;
							}

				//Set k equal to the current clock # in the column (which will become the previous item)
				k = logicClock[i][j];
			}
			//Set k to 0 (we're on a new row)
			k = 0;

			//Check if we're done
			done = true;
			for(int y = 0; y < row && done == true; y++)
				for(int z = 0; z < col && done == true; z++)
					if(logicClock[y][z] == 0 && eventSequence[y][z].size() > 0)
						done = false;
		}
	}

	//Output the logicClock
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << setw(5) << logicClock[i][j];

		cout << endl;
	}
	return 0;
}

#endif /* ALGORITHMCALCULATE_H_ */
