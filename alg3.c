#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t t0;
pthread_t t1;

int flag[2] = {0,0}; // shared variable
const int t0_turn = 0;
const int t1_turn = 1;

void *p1(void *arg);


int main(void){
  pthread_create(&t0, NULL, p1, (void*)&t0_turn);
  pthread_create(&t1, NULL, p1, (void*)&t1_turn);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  return 0;
}

/**
 *
 * Two-process synchronization
 * algorithm 3: more flag waving
 * with shared int flag[2]
 */
void *p1(void *arg){
  int my_flag = *((int*) arg);
  int other_flag = (my_flag + 1) % 2;
  while(1){
    // entry section
    flag[my_flag] = 1;
    printf("P%d waiting.\n", my_flag);
    while(flag[other_flag]){
       // do nothing
    }
    // critical section
    printf("P%d in critical section.\n", my_flag);
    // exit section
    flag[my_flag] = 0;
    // remainder section
  }
}
