#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


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
  printf("creating room\n");
  printf("The first room name is %s\n", roomNames[0]);

  /* hardcode 10 room names
  // but randomly only create 7 rooms
  one is start, one is end, and others are middle

  */
}
