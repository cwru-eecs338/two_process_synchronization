# Two Process Synchronization
Four example brute-force algorithms attempting to synchronize two process that share memory.

The algorithms seek to satisfy the [critical section](https://en.wikipedia.org/wiki/Critical_section) problem requirements.
Implemented as pthreads in C.

 - `alg1`: Strict turn taking.  Does not satisfy progress requirement.
 - `alg2`: Wait-then-set flag waving.  Does not satisfy mutual exclusion or bounded waiting.
 - `alg3`: Set-then-wait flag waving.  Ends in deadlock, and therefore no progress or bounded waiting.
 - `alg4`: Peterson's algorithm.  Satisfies critical section requirements.
 
Also, for reference:
 - `alg1_counter`: demonstrates the inefficiency of busy waiting.
 - `bakery`: Lamport's bakery algorithm for n-process synchronization.
