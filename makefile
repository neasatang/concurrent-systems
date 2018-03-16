start_program:
	gcc -o random1000000 random1000000.c
	./random1000000

start_test:
	gcc -o random100 random100.c
	./random100

compile_linearsearch_serial:
	gcc -o linearsearch_serial linearsearch_serial.c

compile_linearsearch_parallel:
	gcc -fopenmp -o linearsearch_parallel linearsearch_parallel.c

compile_mergesort_serial:
	gcc -o mergesort_serial mergesort_serial.c

compile_mergesort_parallel:
	gcc -fopenmp -o mergesort_parallel mergesort_parallel.c
