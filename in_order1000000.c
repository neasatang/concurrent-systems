#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r,i = 0;
	FILE *f = fopen("file.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	for(i = 0; i < 1000000; i++)
	{
		fprintf(f, "%d\n", i);
	}
	return 0;
}
