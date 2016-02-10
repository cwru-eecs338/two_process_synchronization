all: alg1 alg1_counter alg2 alg3 alg4 bakery

alg1: alg1.c
	gcc -pthread -Wall alg1.c -o alg1

alg1_counter: alg1_counter.c
	gcc -pthread -Wall alg1_counter.c -o alg1_counter

alg2: alg2.c
	gcc -pthread -Wall alg2.c -o alg2

alg3: alg3.c
	gcc -pthread -Wall alg3.c -o alg3

alg4: alg4.c
	gcc -pthread -Wall alg4.c -o alg4

bakery: bakery.c
	gcc -pthread -Wall bakery.c -o bakery

clean:
	rm alg1 alg1_counter alg2 alg3 alg4 bakery
