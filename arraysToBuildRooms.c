#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


// method Prototypes
void createDirectory();

char *roomNames[11] = {
  "blankroom","ALPHA", "BETA", "CHI", "FOUR",
  "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"
};

int main(){
  printf("Trying again to fix this build room thing\n");
  createDirectory();
}

void createDirectory(){
  // create a directory kwongb.rooms.<processID>
  // change this to processID here
  mkdir("kwongb", 0755);
}
