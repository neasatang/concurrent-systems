clean_linear: rm -f linearsearch_parallel
			 				rm -f linearsearch_seriel

clean_merge: rm -f mergesort_parallel
						 rm -f mergesort_seriel

clean_all: clean_linear
					 clean_merge

start_program:
	gcc -o random1000000 random1000000.c
	./random1000000

start_test:
	gcc -o random100 random100.c
	./random100

compile_linearsearch_serial:
	gcc -o linearsearch_serial linearsearch_serial.c

compile_linearsearch_parallel:
	gcc-7 -o linearsearch_parallel linearsearch_parallel.c

linearsearch_serial:
	gcc -o linearsearch_serial linearsearch_serial.c
	./linearsearch_serial

linearsearch_parallel: gcc -o linearsearch_parallel linearsearch_parallel.c
											 ./linearsearch_parallel

compile_mergesort_serial: gcc -o mergesort_serial mergesort_serial.c

compile_mergesort_parallel: gcc -fopenmp -o mergesort_parallel mergesort_parallel.c

mergesort_serial : gcc -o mergesort_serial mergesort_serial.c
									 ./mergesort_serial

mergesort_parallel: gcc -fopenmp -o mergesort_parallel mergesort_parallel.c
										./mergesort_parallel
