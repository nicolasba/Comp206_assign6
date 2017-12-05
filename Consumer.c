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
  
  char c,d;
  FILE *q,*s;
  
  while((q=fopen("turn.txt","r+"))==NULL);
  
  c=fgetc(q);
  
  if(c=='1'){
    s=fopen("data.txt","r");
    d=fgetc(s);
    printf("%c",d);
  }
  
  else{
    printf("value in TURN.txt is not 1");
  }
  fclose(s);
  
  fputc('0', q);
  fclose(q);

}
