#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct timespec start, end;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2]; //temp arrays for left and right

    for (i = 0; i < n1; i++) // copy elems
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // index of 1st array
    j = 0; // index of 2nd array
    k = l; // index of merged array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int list[], int l, int r){
  if(l <r)
  {
    int m = l + (r-l)/2; //avoid overflow for big l and r
    merge_sort(list, l , m);
    merge_sort(list, m+1, r);
    merge(list, l, m, r);
  }
}

int main(){
  /* initialise variables */
  char string[12];
  int n = 1000000; //size of data
  int list[n];
  int i = 0;

  /* read input from file */
  FILE *file;
  file = fopen("file.txt","r");
  while(!feof(file) && i<n)
  {
      fgets(string,sizeof(string),file); //gets input from file
      list[i] = atoi(string);            //convert to integer
      //printf("%d\n",list[i]);
      i++;
  }
  fclose(file);

  clock_gettime(CLOCK_MONOTONIC_RAW, &start); //start timer
  int l = 0;
  int r = n-1;
  merge_sort(list,l,r);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
  printf("Time is: %f\n", x/1000000 );


  /* stores sorted array into a file*/
  FILE *f;
  f = fopen("mergesort.txt","w");
  for (i = 0; i < n; i++)
  {
      fprintf(f,"%d\n",list[i]);
  }
  fclose(f);


  return 0;
}
