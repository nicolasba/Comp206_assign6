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

/*
 * This function constantly tries to open and read from "turn.txt". When
 * the character contained in this file == '0'(producer's turn), it reads
 * the next character from mydata.txt and writes it on data.txt for the
 * consumer to read. When producer gets to the end of the file in "mydata.txt",
 * it will put '2' inside "turn.txt" for the consumer to see and terminate.
 */
void producer()
{
	char turn, charToProduce;
	FILE *turnFile, *dataFromFile, *dataToFile;

	dataFromFile = fopen("mydata.txt", "rt");
	charToProduce = fgetc(dataFromFile);

	while (!feof(dataFromFile))
	{
		while ((turnFile = fopen("turn.txt", "r+")) == NULL);

		turn = fgetc(turnFile);

		if (turn == PRODUCER_TURN)
		{
			dataToFile = fopen("data.txt", "wt");

			printf("%c", charToProduce);
			fputc(charToProduce, dataToFile);

			fclose(dataToFile);
		}
		charToProduce = fgetc(dataFromFile);

		//Send turn to consumer
		fputc('1', turnFile);
		fclose(turnFile);
	}

	//Put '2' inside "turn.txt" so that consumer knows producer has reached
	//end of file
	while ((turnFile = fopen("turn.txt", "r+")) == NULL);

	if (fgetc(turnFile) == PRODUCER_TURN)
		fputc('2', turnFile);

	fclose(turnFile);
	fclose(dataFromFile);
}
