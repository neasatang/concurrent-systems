#include <stdio.h>

void merge(int list[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
  {
      L[i] = list[l + i];
  }
  for (j = 0; j < n2; j++)
  {
      R[j] = list[m + 1+ j];
  }
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
      if (L[i] <= R[j])
      {
          list[k] = L[i];
          i++;
      }
      else
      {
          list[k] = R[j];
          j++;
      }
      k++;
  }

  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1)
  {
      list[k] = L[i];
      i++;
      k++;
  }

  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2)
  {
      list[k] = R[j];
      j++;
      k++;
  }
}

void mergesort(int list[], int l, int r){
  if(r > l)
  {
    int m = (l+r)/2;
    mergesort(list, l , m);
    mergesort(list, m+1, r);
    merge(list, l, m, r);
  }
}

int main(){
  char string[6];
  int list[100];
  int i = 0;
  FILE *file;
  file = fopen("file.txt","r");   //reads input from file
  while(!feof(file) && i<100)
  {
      fgets(string,sizeof(string),file); //gets input from file
      list[i] = atoi(string);            //convert to integer
      i++;
  }
  fclose(file);
  int l = 0;
  int r = 99;
  mergesort(list,l,r);
  for(i = 0; i < 100; i++){
    printf("%d\n",list[i]);
  }
  return 0;
}
