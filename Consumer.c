/*
 * Consumer.c
 *
 *  Created on: Nov 29, 2017
 *      Author: Polina
 */

#include <stdio.h>
#include "Consumer.h"

//this function opens TURN.txt and reads it's first character
//if the character == "1" then consumer opens DATA.txt
//reads the character from DATA.txt and prints it to the screen
//it then changes the character in TURN.txt to "0"
void consumer(){
  
  char cturn,cdata;
  FILE *openTURN,*openDATA;
  
  while((openTURN=fopen("TURN.txt","r+"))==NULL);
  
  cturn=fgetc(openTURN);
  
  if(cturn=='1'){
    openDATA=fopen("DATA.txt","r");
    cdata=fgetc(openDATA);
    printf("%c",cdata);
  }
  
  else{
    printf("value in TURN.txt is not 1");
  }
  fclose(openDATA);
  
  fputc('0', openTURN);
  fclose(openTURN);

}
