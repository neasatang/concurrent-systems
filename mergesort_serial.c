#include <stdio.h>
#include <string.h>
#include <time.h>

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

void mergesort(int list[], int l, int r){
  if(l <r)
  {
    int m = l + (r-l)/2; //avoid overflow for big l and r
    mergesort(list, l , m);
    mergesort(list, m+1, r);
    merge(list, l, m, r);
  }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
  char string[12];
  int list[1000000];
  int i = 0;
  FILE *file;
  file = fopen("file.txt","r");   //reads input from file
  while(!feof(file) && i<1000000)
  {
      fgets(string,sizeof(string),file); //gets input from file
      list[i] = atoi(string);            //convert to integer
      //printf("%d\n",list[i]);
      i++;
  }
  fclose(file);
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  int l = 0;
  int r = 1000000-1;
  mergesort(list,l,r);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
printf("Time is: %f\n", x/1000000 );

  FILE *f;
  f = fopen("mergesort.txt","w");
  for (i = 0; i < 1000000; i++)
  {
      fprintf(f,"%d\n",list[i]);
  }
  fclose(f);


  return 0;
}
