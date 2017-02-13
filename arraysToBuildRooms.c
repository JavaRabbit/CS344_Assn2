#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


// method Prototypes
void createDirectory();
void selectRooms();
void pickStartEnd();

char *roomNames[11] = {
  "placeHolderRoom","ALPHA", "BETA", "CHI", "FOUR",
  "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"
};

// 2D array that will store room TYPE and CONNECTIONS
// array has 11 rows, since there are 10 possible room Names, and I won't use row 0
// array has 12 columns, since 10 possible rooms, and 1 column for room type, and won't be using col 0
int rooms[11][12];

// variable to hold directory name
char dirName[20];

// array of 10 spaces
int roomArray[10];

int main(){

  // method to create a directory
  createDirectory();
  selectRooms();
  pickStartEnd();


}

void createDirectory(){
  // create a directory kwongb.rooms.<processID>
  // change this to processID here
  int pidNum = getpid();
  sprintf(dirName,"kwongb.rooms.%d", pidNum);
  printf("FInally, the room generated is %s\n\n", dirName);
  mkdir(dirName, 0755);
}

// the purpose of this method is to select the 7 random rooms that will be used
void selectRooms(){
  /*
    Goal is to select 7 rooms out of 10
    Another way to look at this is that we're selecting out 3 rooms to NOT be used
  */

  /* using the roomArray[10]
  use srand to randomly pick out 3 rooms. Each time we put it (or swap it at the end of the array)
  Example: Pick #1, from 0-9 pick a number. That number will be swapped with element at position [9]
  Pick #2: Pick a number from 0-8, That number will be swapped with element at pos [8]
  Pick #3, pick a number from 0-7, That number will be swapped with element at pos[7]
  Thus, at the end, our random 7 values will be in the array at positions [0] - [6] inclusive
  */

  // First create a roomArray and set the values from 1-10 inclusive, because it corresponds to valid
  // rooms in roomNames[]
  for(int i = 0; i < 10; i++){
    // plus 1, because the 0th element is Room 1, [1] is Room 2, etc.
    roomArray[i] = i+1;
  }

  // now that each room is set, 3 times, we will pick out numbers and put at end
  for(int p = 0; p < 3; p++){
    // pick a random value from 0 to 9-p inclusive
    int mod = 9-p;
    int r;
    // remember we reseed each time so we get different random values
    srand(time(NULL));
    r = rand()%mod;

    // each time swap value at r with 9-p
    int temp = roomArray[mod];
    roomArray[mod] = roomArray[r];
    roomArray[r] = temp;

  }

  for(int i = 0; i < 10; i++){
    printf("The value of room is %d\n", roomArray[i]);
  }
}

void pickStartEnd(){
  /*
  Goal of method is to pick 2 rooms from roomArray[]  to select as our start and end rooms
  The two rooms must be from roomArray[0] - roomArray[6] inclusive, because that's the 7 rooms
  we randomly chose to use
  */

  int startRoom;
  int endRoom;
  int multiplier;

  // as an alternative to the wretched rand(), I'll use the pid and mod to get a random value
  // for start that's between 0-6 inclusive
  int pidNum = getpid();
  startRoom = pidNum%7;
  printf("the startRoom is %d\n", startRoom);


  // for the end room, get a random variable and multiply it by pidNum
  // Trouble with rand giving same values each time means funky ways of coming up with a random number

  // start room and end room cannot be the same. Use a while loop to ensure that
  // start and end rooms are different.
  //
  // this while loop will end if start and end values differ

  // need to FIX FIX !!!!!!!!!!!!!!!!!!!!!!!
  if(startRoom == 0 || startRoom== 1 || startRoom == 2 || startRoom ==3 ){
    endRoom = 6;
  } else{
    endRoom = 1;
  }


  printf("the end room is %d\n", endRoom);

  // let startRoom be a number between 0-6 inclusive
}
