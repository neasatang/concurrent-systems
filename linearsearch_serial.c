#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct timespec start, end;

int linear_search(int list[], int key){
	int i;
	for(i = 0; i<1000000; i++){
		if(list[i]==key)
		{
			return i;	//returns position of key
		}
	}
	return -1;		//returns -1 if not found
}

int main(){
	int answer = 0;
	int n = 1000000;
	int key = 7;
	char string[15];
  int list[n]; //size of data
  int i = 0;
  FILE *file;
  file = fopen("file.txt","r");   //reads input from file
  while(!feof(file) && i<n)
  {
    fgets(string,sizeof(string),file); //gets input from file
		list[i] = atoi(string);			  		 //convert to integer
		i++;
  }
	fclose(file);

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	answer = linear_search(list, key);
	if(answer == -1)
	{
		printf("%d is not found\n", key);
	}
	else
	{
		printf("%d is at index %d\n",key, answer);
	}

	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
printf("Time is: %f\n", x/1000000 );

	return 0;
}
