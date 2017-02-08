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
