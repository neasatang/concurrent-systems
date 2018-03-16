#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int r,i = 0;
	FILE *f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	for(i = 0; i < 1000000; i++)
	{
		r=rand()%1000000;
		fprintf(f, "%d\n", r);

	}
	return 0;
}
