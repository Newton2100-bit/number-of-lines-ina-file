#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static int count = 0, rd;
static FILE *fileptr;
static char character;

void openfile(char *);
void count_lines();

int main(int argc, char **argv){
	// pthread_t nchars, nwords;
	/* These wiil count the number of lines in a file and 
	   printf out the number */

	if(argc < 2){
		fprintf(stderr, "Kindly provide the file name.\n");
		exit(0);
	}
	openfile(argv[1]);
	count_lines();


	printf("[ %s ]\n\tlines : %d\n" , argv[1], count);
	fclose(fileptr);
	return 0;
}

void openfile(char *filename){
	fprintf(stderr, "opening file %s\n", filename);
	if((fileptr = fopen(filename, "r")) == NULL){
		fprintf(stderr, "could not ooen the file %s\n", filename);
		exit(0);
	}
	printf("file succesfully opened\n");
}


void count_lines(){
	do{
		rd = fscanf(fileptr, "%*[^\n]%c", &character);
		if(rd == 0 && !feof(fileptr))
			character = getc(fileptr);
		// printf("read %c\t", character);
		if(rd == -1)
			break;
		else
			count++;
	}while(1);
}
