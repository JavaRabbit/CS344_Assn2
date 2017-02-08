#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>


// Prototypes
void createDirectory();

void createRooms();

// create room names as string array
char *roomNames[10] = {
  "alpha", "beta", "three", "four",
  "five", "six", "seven", "eight", "nine", "ten"
};

int main() {

   printf("Hello, World! \n");
   createDirectory();
   createRooms();
   return 0;
}

void createDirectory(){
  // create a directory kwongb.rooms.<processID>
  // change this to processID here
  mkdir("foo", 0755);
}

void createRooms(){

  printf("The first room name is %s\n", roomNames[0]);

  // create a file
  FILE *fp = NULL;
  //  a is for append, w is for write
  fp = fopen("./foo/textFile.txt" ,"w");
  fprintf(fp, "writing in this file");

  // close
  fclose(fp);

  /* hardcode 10 room names
  // but randomly only create 7 rooms
  one is start, one is end, and others are middle

  To pick 7 rooms, pick number between 1-10
  check if exists in array, if so add to room array
  */


  // pick random number between one and 10 with different seed
  /*  ------------ DELETE --------------------------------------
  int r;
  srand(time(NULL));
  r = rand()%10;
  printf("The random number is %d\n",r );  */

  // First create a roomArray and set the values from 0-9
  int roomArray[10];
  for(int i = 0; i < 10; i++){
    roomArray[i] = i;
  }

  // now that each room is set, 3 times, we will pick out numbers and put at end
  for(int p = 0; p < 3; p++){
    // pick a random value from 0 to 9-p inclusive
    int mod = 9-p;
    int r;
    srand(time(NULL));
    r = rand()%mod;
    printf("The random  is %d\n",r );

    // each time swap value at r with 9-p
    int temp = roomArray[mod];
    roomArray[mod] = roomArray[r];
    roomArray[r] = temp;


  }

  for(int i = 0; i < 10; i++){
    printf("The value of room is %d\n", roomArray[i]);
  }





}
