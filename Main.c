/*
 * Main.c
 *
 *  Created on: Nov 29, 2017
 *      Author: nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Consumer.h"
#include "Producer.h"

int main(void)
{
	//Set first turn for the producer
	FILE *turnFile = fopen("TURN.txt", "wt");
	fputc('0', turnFile);
	fclose(turnFile);

	//launch the clones
	int pid = fork();

	if (pid == -1)
		exit(1);
	//Producer is child process
	else if (pid == 0)
		producer();
	//Consumer is parent process
	//else if (pid == 0)
	//	consumer();
	exit(0);
}
