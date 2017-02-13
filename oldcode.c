// this is trying to get the room array
// create a room array. It will be an int array
int roomArray[7];

for(int i =0; i < 7; i++){
  int boo = 1;
  while(boo == 1){
    // pick a random number
    int r;
    srand(time(NULL));
    r = rand()%10;

    if(i ==0){
      printf("going to put %d into array\n", r);
      roomArray[i] = r;
      boo = 0; // value has been put into array. Set boo to false
    }

    // if not in array, put in array
    if(i > 0){
      for(int j = 0; j < i ; j++){
        if(roomArray[j] == r){
          continue;
        }
      }

      //  looks like not found
      printf("going to put %d into array\n", r);
      roomArray[i] = r;
      boo = 0; // value has been put into array. Set boo to false

    }

  }
}


// print out the room array

for(int m = 0; m < 7; m++){
  printf("The value is %d\n", roomArray[m]);
}

///  Old code --------------------

void selectRooms(){

  printf("The first room name is %s\n", roomNames[0]);

  // create a file
  FILE *fp = NULL;
  //  a is for append, w is for write
  fp = fopen("./foo/textFile.txt" ,"w");
  fprintf(fp, "writing in this file");

  // close
  fclose(fp);
}


// how to STRING CONCATENTATE --------------

char cat[20] = "cat";
char dog[] = "doggy";
strcat(cat, dog);
printf("%s\n", cat);

//   Using arrays.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Prototypes
void fiz();

int *array = NULL;
char *strArray[8];
char *room[8][8];




int main(){
  printf("ugh finally using arrays\n");
  // array[0]  is the room name,  [1] is the room type
  // [2] and beyond is room connections
  array = malloc(8 * sizeof(int));

  room[0][0] = "first room";



  strArray[0] = "foo";
  strArray[7] = "foo10";
  printf("%s\n", strArray[7]);

  array[0] = 1;
  array[1] = 2;
  printf("%d\n", array[0]);
  fiz();
  printf("location 1 is now %d\n", array[1]);
  printf("A null location is %d\n", array[4]);


  return 0;
}

void fiz(){
  printf("This si fiz\n");
  printf("%d\n", array[0]);
  array[1] = 3;
  printf("%s is str array\n", strArray[0]);
  printf("Now leavzing fiz\n\n");
  printf("%s\n",room[0][0]);
}



void startGame(){
  // first we need to find the room which is the start room
  // iterate over each room 0-6 inclusive, and see which one has 0
  for(int roomPos = 0; roomPos < 7; roomPos++){
    // remember that room type lives in column [1]
    if(rooms[roomPos][1] == 0){
      printf("the start room is found, the room pos is %d\n", roomPos);
    }
  }
}

// ----------  This old code was to see if player entered BETA if it would be equal to roomNames[2]
int cmp = strcmp(roomNames[2], destination);
if(cmp == 0){
  printf("the strings match\n");
} else {
  printf("nope, string does not match china\n");
}

//printf("Before, The length of destination is %lu\n", strlen(destination));
//printf("The length of destination is %lu\n", strlen(destination));


// trying to get random endRoom value
int myboolean = 1;
int pidIncrementer = 3;

while(myboolean == 1){
  int midPid = pidNum/2;
  endRoom = midPid%7;
  printf("the end room is %d\n", midPid);
  if(endRoom == startRoom){
    if(midPid > 0){
      midPid = pidNum * pidIncrementer;
      pidIncrementer++; // in case we need to use pidIncrementer again,
    }
    continue;
  } else{

    break; // we got a good value for end rom
  }
}
