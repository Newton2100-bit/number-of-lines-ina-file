#include <stdio.h>
#include <stdlib.h>
int count = 0;

void usage(){
	printf("Provide a file name kindly\n");
	exit(1);
}

int main(int argc, char **argv){
	printf("we have EOF as %d\n", EOF);
	FILE *stream;
	if(argc < 2)
		usage();

	if ((stream = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Error occured could not open\n");
		exit(1);
	}

	int rv;
	char character;
	do{
		// printf("[ character ] : ");
		rv = fscanf(stream, "%*[^\n]%c", &character);
		if(rv == 0 && !feof(stream))
			character = getc(stream);
		 if( rv == -1)
			 break;
		 else 
			 count++;
		
	}while(1);
	printf("found %d lines\n", count);
	fclose(stream);

	return 0;
}
