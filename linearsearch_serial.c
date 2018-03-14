#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct timespec start, end;

int linear_search(int list[], int search_var){
	for(int i = 0; i<1000000; i++){
		if(list[i]==search_var)
		{
			//printf("%d\n",list[i]);
			return i;
		}
	}
	return -1;		//returns -1 if not found
}

int main(){
	int answer = 0;
	int search_var = 123231;
	char string[15];
  int list[1000000];
  int i = 0;
  FILE *file;
  file = fopen("file.txt","r");   //reads input from file
  while(!feof(file) && i<1000000)
  {
    fgets(string,sizeof(string),file); //gets input from file
		list[i] = atoi(string);			   //convert to integer
		i++;
  }
	fclose(file);

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	answer = linear_search(list, search_var);
	if(answer == -1)
	{
		printf("%d is not found\n", search_var);
	}
	else
	{
		printf("%d is at index %d\n",search_var, answer);
	}

	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double x = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
printf("Time is: %f\n", x/1000000 );

	return 0;
}
