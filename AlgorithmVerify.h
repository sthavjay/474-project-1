/*
 * AlgorithmVerify.h
 *
 *  Created on: Sep 23, 2020
 *      Author: bijay
 */

#ifndef ALGORITHMVERIFY_H_
#define ALGORITHMVERIFY_H_

#include "header.h"

int AlgorithmVerify(int logicClock[][col])
{
	string eventSequence[row][col];	//This will store our event sequence

	int sequence = 0;
	int max = 0;

	//Make sure the matrix is possible

	/******
	 * PROBLEM 2
	 ******/

	//Verify that the problem is possible
	int sequenceChanged = true;	//Check whether we're still incrementing sequence
	while(sequenceChanged == true)
	{
		sequenceChanged = false;
		for(int j = 0; j < col; j++)
			for(int i = 0; i < row; i++)
			{
				//If this number will increment our sequence, do so
				if(logicClock[i][j] == sequence + 1)
				{
					sequence++;
					sequenceChanged = true;
				}
				//Set the largest number we've found equal to the max
				if(logicClock[i][j] > max)
					max = logicClock[i][j];
			}
	}

	//If the problem has a larger max than possible for our sequence
	if(sequence != max)
	{
		cout << "The output is \"INCORRECT\".";
		return -1;
	}


	//Initialize eventSequence to NULL
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			eventSequence[i][j] = "NULL";


	//If arr[1] > arr[0] + 1, we're a receiver
	int previous;
	for(int i = 0; i < row; i++)
	{
		previous = -1;
		for(int j = 0; j < col; j++)
		{
			if(previous != -1)	//If we're not in the first column
			{
				if(logicClock[i][j] > (previous + 1))
					eventSequence[i][j] = "r";
			}
			else	//If we're the first index in the column
			{
				if(logicClock[i][j] != 1)	//If we're a receiver in column 1
					eventSequence[i][j] = "r";
			}
			previous = logicClock[i][j];	//Set a value for the previous number in the row
		}
	}


	//Check which number is 1 less than receiver, that's the sender. Receivers always increase in value.
	int senderLogicClock = 0;
	int receiverNumber = 0;
	int receiverI = -1;
	int receiverJ = -1;
	int foundSender = false;

	while(senderLogicClock != -1)
	{
		senderLogicClock = -1;
		receiverNumber++;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				//If we're currently the smallest receiver that we haven't yet found the sender for
				if(eventSequence[i][j] == "r" && (senderLogicClock == -1 || senderLogicClock > (logicClock[i][j] - 1)))
				{
					senderLogicClock = logicClock[i][j] - 1;
					receiverI = i;
					receiverJ = j;
				}
		//Look for the sender
		if(receiverI != -1 && receiverJ != -1)
			for(int i = 0; i < row && !foundSender; i++)
				for(int j = 0; j < col && !foundSender; j++)
					//If this is the sender
					if(logicClock[i][j] == senderLogicClock)
					{
						//Give the sender a number
						eventSequence[i][j] = "s0";
						eventSequence[i][j].at(1) += receiverNumber;

						//Give the receiver a number
						eventSequence[receiverI][receiverJ] = "r0";
						eventSequence[receiverI][receiverJ].at(1) += receiverNumber;

						//We've found the sender, there can only be one
						foundSender = true;
					}

		//Reset sender
		foundSender = false;
	}

	//if arr[n] is null, arr[n] = 0
	//Give values to everything that doesn't equal 0
	string letter = "a";	//Used to find out what letter we're on
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			//If we're not supposed to be Null and we're not a sender or receiver
			if(logicClock[i][j] != 0 && eventSequence[i][j] == "NULL")
			{
				eventSequence[i][j] = letter;	//Set our current letter
				letter.at(0)++;					//Move on to the next letter
			}

	//Output the logicClock
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			cout << setw(5) << eventSequence[i][j];

		cout << endl;
	}
	return 0;
}

#endif /* ALGORITHMVERIFY_H_ */
