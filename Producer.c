/*
 * Producer.c
 *
 *  Created on: Nov 29, 2017
 *      Author: nicolas
 */
#include <stdlib.h>
#include <stdio.h>
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
	int endOfFile = 0;

	while (!endOfFile)
	{
		while ((turnFile = fopen("turn.txt", "r+")) == NULL);

		turn = fgetc(turnFile);

		if (turn == PRODUCER_TURN)
		{
			dataFromFile = fopen("mydata.txt", "rt");
			dataToFile = fopen("data.txt", "wt");

			if (!feof(dataFromFile))
			{
				charToProduce = fgetc(dataFromFile);
				fputc(charToProduce, dataToFile);
			}
			else
			{
				endOfFile = 1;
				//Write '2' in "turn.txt" for the consumer to see and terminate
				fputc('2', turnFile);
			}

			fclose(dataFromFile);
			fclose(dataToFile);

			//Close turn file so that consumer can read from it
			fclose(turnFile);
		}
	}

}
