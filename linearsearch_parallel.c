#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct timespec start, end;

int main()
{
    int data = 0;
    int key = 0;
    int n = 1000000;  //size of data
    char string[15];
    int list[n];
    FILE *file;
    file = fopen("file.txt","r");   //reads input from file
    while(!feof(file) && data  < n)
    {
      fgets(string,sizeof(string),file); //gets input from file
  		list[data] = atoi(string);			   //convert to integer
  		data++;
    }
    fclose(file);

    int id, i, nThreads, istart, iend;
    id = omp_get_thread_num();
    nThreads = omp_get_num_threads();
    istart = id * (n / nThreads); // each thread does one section
    if(id == nThreads-1)
    {
      iend = n;
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); //start timer
    #pragma omp parallel for num_threads(4) // 4 threads for parallelising
    for (i = istart; i < iend; i++)
    {
      if(list[i]==key)  //searches for key
      {
        printf("Key found. Position = %d by thread %d \n", i+1, id);  //returns position
      }
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end); //end timer
    double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
    printf("Time is: %f\n", x/1000000 );
    return 0;
}
