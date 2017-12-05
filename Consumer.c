/*
 * Consumer.c
 *
 *  Created on: Nov 29, 2017
 *      Author: Polina
 */

#include <stdio.h>
#include "Consumer.h"
#define CONSUMER_TURN '1'
#define END_FIle '2'

//this function opens TURN.txt and reads it's first character
//if the character == "1" then consumer opens DATA.txt
//reads the character from DATA.txt and prints it to the screen
//it then changes the character in TURN.txt to "0"

void consumer(){
  
  char turn,charData;
  FILE *turnFile,*dataFile;
  
  while((turnFile=fopen("TURN.txt","r+"))==NULL);
  
  turn=fgetc(turnFile);
  
  if(turn == END_FILE){
    printf("\n all the data is printed");
    exit(0);
  }
  
  while(turn == CONSUMER_TURN){
      dataFile=fopen("DATA.txt","r");
      charData=fgetc(dataFile);
      printf("%c",charData);
    
      fclose(dataFile);
    
      fputc('0', turnFile);
      overwriteTurn(turnFile, '1');
  }
  
  fclose(turnFile);

}


void overwriteTurn(FILE *turnFile, char data){
  fclose(turnFile);
  while((turnFile = fopen("TURN.txt", "wt")) == NULL);
  fputc(data, turnFile);
}
