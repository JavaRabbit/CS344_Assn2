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
  int r;
  srand(time(NULL));
  r = rand()%10;
  printf("The random number is %d\n",r );
}
