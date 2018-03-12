#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linear_search(int list[], int search_var){
	for(int i = 0; i<100; i++){
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
	int search_var = 1232312;
	char string[6];
    int list[100];
    int i = 0;
    FILE *file;
    file = fopen("file.txt","r");   //reads input from file
    while(!feof(file) && i<100)
    {
        fgets(string,sizeof(string),file); //gets input from file
		list[i] = atoi(string);			   //convert to integer
		i++;
    }
	fclose(file);
	answer = linear_search(list, search_var);
	if(answer == -1)
	{
		printf("%d is not found\n", search_var);
	}
	else
	{
		printf("%d is at index %d\n",search_var, answer);
	}
	return 0;
}
