/*
 * Consumer.c
 *
 *  Created on: Nov 29, 2017
 *      Author: nicolas
 */

//this function reads characters from DATA and display them on screen when TURN = "1" then gives TURN to Producer 
consumer(){
  char *q;
  //infinite loop that waits for TURN to be 1
  while(1){
    //get the value of environmental variable TURN
    do {q = getenv("TURN");}
    //while value of TURN is 1 get the value of DATA
    while (strcmp(q,"1")!= 0);
    char *s;
    //get the value of environmental variable DATA
    s=getenv("DATA");
    //display character stored in DATA
    printf("%s",s);
    //give TURN to Producer (set TURN to 0)
    setenv("TURN","0",1);
  }
}
