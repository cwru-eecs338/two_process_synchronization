#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t t0;
pthread_t t1;

int turn = 0; // shared variable
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
 * algorithm 1: strict turn-taking
 * with shared int "turn".
 */
void *p1(void *arg){
  int my_turn = *((int*) arg);
  while(1){
    // entry section
    printf("P%d waiting.\n", my_turn);
    while(turn != my_turn){
       // do nothing
    }
    // critical section
    printf("P%d in critical section.\n", my_turn);
    // exit section
    turn = (turn + 1) % 2;
    // remainder section
  }
}
