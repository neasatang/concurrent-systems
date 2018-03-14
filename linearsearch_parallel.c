#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct timespec start, end;

int main()
{
    int data = 0;
    int key=7812;
    int n = 1000000;
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
    istart = id * (n / nThreads);
    if(id == nThreads-1)
    {
      iend = n;
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    #pragma omp parallel for num_threads(4)
    for (i = istart; i < iend; i++)
    {
      if(list[i]==key)
      {
        printf("Key found. Position = %d by thread %d \n", i+1, id);

      }
    }
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
  printf("Time is: %f\n", x/1000000 );
    return 0;
}
