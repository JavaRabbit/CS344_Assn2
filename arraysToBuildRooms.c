#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// method Prototypes
void createDirectory();

char *roomNames[11] = {
  "blankroom","ALPHA", "BETA", "CHI", "FOUR",
  "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"
};

int main(){

  // method to create a directory
  createDirectory();


}

void createDirectory(){
  // create a directory kwongb.rooms.<processID>
  // change this to processID here
  char dirName[20];
  int mm = getpid();
  printf("%d is the current process\n", mm);
  sprintf(dirName,"kwongb.rooms.%d", mm);
  printf("FInally, the room generated is %s\n\n", dirName);
  mkdir(dirName, 0755);
}
