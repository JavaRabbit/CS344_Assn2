#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
void createDirectory();
void selectRooms();
void pickStartEnd3();
void roomLoopCaller4();
void createRooms();

void pickRoomConnections();


// create room names as string array
char *roomNames[10] = {
  "alpha", "beta", "three", "four",
  "five", "six", "seven", "eight", "nine", "ten"
};

char *fileNames[7] = {"file1", "file2", "file3","file4", "file5", "file6", "file7"};

char *roomTypes[3] = {"start", "middle", "end"};

int roomArray[10];

int startEndArray[7];

struct Room{
  char *roomName;
  char *roomType;
  struct Room *connectingRooms[6]; // 6 max connections
};

int main() {

   createDirectory();

   selectRooms();
   pickStartEnd3();
   roomLoopCaller4();
   //pickRoomConnections();
   //createRooms(1);
   return 0;
}

void createDirectory(){
  // create a directory kwongb.rooms.<processID>
  // change this to processID here
  mkdir("foo", 0755);
}

void selectRooms(){

  /* hardcode 10 room names
  // but randomly only create 7 rooms
  one is start, one is end, and others are middle

  To pick 7 rooms, pick number between 1-10
  check if exists in array, if so add to room array
  */


  // pick random number between one and 10 with different seed


  // First create a roomArray and set the values from 0-9

  for(int i = 0; i < 10; i++){
    roomArray[i] = i;
  }

  // now that each room is set, 3 times, we will pick out numbers and put at end
  for(int p = 0; p < 3; p++){
    // pick a random value from 0 to 9-p inclusive
    int mod = 9-p;
    int r;
    // remember we reseed each time so we get different random values
    srand(time(NULL));
    r = rand()%mod;
    //printf("The random  is %d\n",r );

    // each time swap value at r with 9-p
    int temp = roomArray[mod];
    roomArray[mod] = roomArray[r];
    roomArray[r] = temp;


  }

  for(int i = 0; i < 10; i++){
    printf("The value of room is %d\n", roomArray[i]);
  }

}

// this method is to help assign the start and end rooms
void pickStartEnd3(){
  // the start room and end room are between 0-6 inclusive
  // pick start 0-6
  int start;
  srand(time(NULL));
  start = rand()%6;
  printf("The start room  is %d\n",start );

  //   ------  FIX -------------- hardcode end here, bad.
  int end = start + 1;
  if(end ==7 ){
    end = 2;
  }
  printf("The end room  is %d\n", end );

  //  now set up startEndArray
  // the start room gets value 0, end room gets 2, middle gets 1

  // everything gets 1 first
  for(int i=0; i < 7; i++){
    startEndArray[i] = 1;
  }

  startEndArray[start] = 0;
  startEndArray[end] = 2;

  for(int i=0; i < 7; i++){
    printf("room %d  is a %s room\n", i, roomTypes[startEndArray[i]]);
  }
}

void roomLoopCaller4(){
  // loop over each of the 7 rooms. Call the createRooms method
  // with the right arguments

  int m;
  for(int i=0; i < 7; i++){
    m = roomArray[i];
    //printf("going to send %d to method\n", m);
    createRooms(m);
  }
}

// This method is called 7 times by roomLoopCaller4
// argument is roomNamePos
void createRooms(int roomNamePos){
  // each room is a struct
  // use 7 since 7 rooms are created
  struct Room baz;
  baz.roomName = roomNames[roomNamePos];
  printf("We live in %s\n", baz.roomName);


  // create a file
  FILE *fp = NULL;


  // name of the file will be the name of the room
  char cat[50] = "./foo/";

  strcat(cat, baz.roomName);
  printf("%s\n", cat);

  fp = fopen(cat,"w");
  fprintf(fp, "%s is a %s type room \n", baz.roomName, roomTypes[startEndArray[roomNamePos]]);

  // close
  fclose(fp);


}


//   Pick room connections -----------------------------
void pickRoomConnections(){


}
