/*
 * Producer.c
 *
 *  Created on: Nov 29, 2017
 *      Author: nicolas
 */
#include <stdlib.h>
#include <stdio.h>
#include "Producer.h"
#define PRODUCER_TURN '0'
#define END_FILE '2'

/*
 * This function constantly tries to open and read from "turn.txt". When
 * the character contained in this file == '0'(producer's turn), it reads
 * the next character from "mydata.txt" and writes it in "data.txt" for the
 * consumer to read. When producer gets to the end of the file in "mydata.txt",
 * it will write '2' inside "turn.txt" for the consumer to see and terminate.
 */
void producer()
{
	char turn, charToProduce;
	FILE *turnFile, *dataFromFile, *dataToFile;
	int endOfFile = 0;

	//Not necessary to keep opening/closing mydata.txt since it is only
	//used by the producer
	dataFromFile = fopen("mydata.txt", "rt");
	charToProduce = fgetc(dataFromFile);

	while (!feof(dataFromFile))
	{
		while ((turnFile = fopen("TURN.txt", "rt")) == NULL);

		turn = fgetc(turnFile);

		if (turn == PRODUCER_TURN)
		{
			dataToFile = fopen("DATA.txt", "wt");
			fputc(charToProduce, dataToFile);

			fclose(dataToFile);
			charToProduce = fgetc(dataFromFile);
			overwriteTurn(turnFile, '1'); //Pass turn to consumer
		}
		fclose(turnFile);
	}

	//Put '2' (END_FILE) inside "turn.txt" so that consumer knows producer has reached
	//end of file
	while (!endOfFile)
	{
		while ((turnFile = fopen("TURN.txt", "rt")) == NULL);

		if (fgetc(turnFile) == PRODUCER_TURN)
		{
			endOfFile = 1;
			overwriteTurn(turnFile, END_FILE);
		}

		fclose(turnFile);
	}
	fclose(dataFromFile);
}

//This function reopens "turn.txt" and overwrites its content with "data"
void overwriteTurn(FILE *turnFile, char data)
{
	fclose(turnFile);
	while ((turnFile = fopen("TURN.txt", "wt")) == NULL);
	fputc(data, turnFile);
}
