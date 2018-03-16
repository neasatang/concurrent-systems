# concurrent-systems

https://www.scss.tcd.ie/~pandith/CS3014/assignment.html

Implement 1 searching algorithm and 1 sorting algorithm in non-parallel and parallel execution formats, and compare them. 
I chose to do Linear Search and Merge Sort while using OpenMP to do it in parallel handling one million data. This assignment was done in C.

# prerequisites
For mac:
``brew install clang-omp``  
`` gcc-7 -fopenmp -o linearsearch_parallel linearsearch_parallel.c ``


On linux:
`` gcc -fopenmp -p linearsearch_parallel linearsearch_parallel.c ``
