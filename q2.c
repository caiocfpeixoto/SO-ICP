#define EMPTY  0
#define DOGS_PRESENT  1
#define CATS_PRESENT  2
#define S = 1
#define D = 5
#define C = 5
dogWantsToEnter = FALSE;
catWantsToEnter = FALSE; 
dogLeaves = FALSE;
catWantsToEnter = FALSE;
int state[S]
typedef int semaphore;
semaphore mutex = 1;

void rest(){
  printf("Descansando!");
  printf("/n");
}

void dog(void){
  if((state[S] == EMPTY) || (state[S] == DOGS_PRESENT)){
    dogWantsToEnter = TRUE;
    down(&mutex);
    while( contador != D){
      contador++;
      state[S] = DOGS_PRESENT;
      rest();
    }
    dogWantsToEnter = FALSE;
    up(&mutex);
    while( contador !=0){
      dogLeaves = TRUE;
      contador--;
    }
    dogLeaves = FALSE;
    state[S] = EMPTY;
    
  }
}

void cat(void){
   if((state[S] == EMPTY) || (state[S] == CATS_PRESENT)){
    catWantsToEnter = TRUE;
    down(&mutex);
    while( contador != D){
      contador++;
      state[S] = CATS_PRESENT;
      rest();
    }
    catWantsToEnter = FALSE;
    up(&mutex);
    while( contador !=0){
      catLeaves = TRUE;
      contador--;
    }
    catLeaves = FALSE;
    state[S] = EMPTY;
  }
}