/*
 * Main.c
 *
 *  Created on: Nov 29, 2017
 *      Author: nicolas
 */
#include <stdio.h>
#include <stdlib.b>
#include <unistd.h>

int main(void)
{
  //intitialize TURN shell variable to 0 
  //producer has TURN = 0; consumer has TURN = 1
  setenv("TURN","0",1);
  
  //launch the clones
  int pid = fork();
  if (pid == -1)exit(1);
  if (pid == 0) {producer();}
  if (pid != 0) {consumer();}


}
