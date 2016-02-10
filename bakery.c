#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define PROCESS_COUNT 3

pthread_t t0;
pthread_t t1;
pthread_t t2;

int choosing[PROCESS_COUNT] = {0}; // shared variable
int number[PROCESS_COUNT] = {0};   // shared variable
const int t0_turn = 0;
const int t1_turn = 1;
const int t2_turn = 2;

void *p1(void *arg);


int main(void){
  pthread_create(&t0, NULL, p1, (void*)&t0_turn);
  pthread_create(&t1, NULL, p1, (void*)&t1_turn);
  pthread_create(&t2, NULL, p1, (void*)&t2_turn);
  pthread_join(t0, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}

int max(int a[]){
  int rval = 0;
  int i;
  for(i = 0; i < PROCESS_COUNT; i++){
    if(a[i] > rval){
      rval = a[i];
    }
  }
  return rval;
}

/**
 *
 * n-process synchronization
 * algorithm:
 * Lamport's bakery algorithm
 */
void *p1(void *arg){
  int i = *((int*) arg); // pid
  int j; // iterator
  while(1){
    // entry section
    printf("P%d waiting.\n", i);
    choosing[i] = 1;
    number[i] = max(number) + 1;
    choosing[i] = 0;
    for(j = 0; j < PROCESS_COUNT; j++){
      while(choosing[j]){ /* noop */ }
      while(
        number[j] != 0 && 
        ((number[j] < (number[i]) ||
         (number[j] == number[i] && j < i)))
      ){ /* noop */}
    }
    // critical section
    printf("P%d in critical section.\n", i);
    // exit section
    number[i] = 0;
    // remainder section
  }
}
