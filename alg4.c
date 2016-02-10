#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t t0;
pthread_t t1;

int flag[2] = {0,0}; // shared variable
int turn = 0;        // shared variable
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
 * algorithm 4: Peterson's algorithm
 * with shared int turn and flag[2]
 */
void *p1(void *arg){
  int mine = *((int*) arg); // 0 or 1
  int not_mine = (mine + 1) % 2;
  while(1){
    // entry section
    flag[mine] = 1;
    turn = not_mine;
    printf("P%d waiting.\n", mine);
    while(flag[not_mine] && turn==not_mine){
       // do nothing
    }
    // critical section
    printf("P%d in critical section.\n", mine);
    // exit section
    flag[mine] = 0;
    // remainder section
  }
}
