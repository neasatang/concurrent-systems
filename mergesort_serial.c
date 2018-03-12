#include <stdio.h>

void mergesort(int list[], int l, int r){
	int m = (l+r)/2;
	mergesort(list, l , m);
	mergesort(list, m+1, r);
	mergesort(list, l,m,r);
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
