#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define FILENAME "asd.txt"

int randomNumber(int i){
	rand()%i;
}

void eraseFileContent(char* fileName){
	FILE * file = fopen(fileName, "w");
	fclose(file);
}

void writeFile(char* fileName, int num){
	FILE * file = fopen(fileName, "a");
	fprintf(file, "%i", num);
    fprintf(file, "\n");
	fclose(file);
}

int main(int argc, char*argv[]){
	char* fileName=argv[1];
	char* p;
	eraseFileContent(fileName);
	int num=strtol(argv[2], &p, 10);
	time_t t = time(NULL);
	srand((int)t);
	for(int i=0;i<num;i++){
		int rnd = rand()%10;
		printf("%i\n",rnd);
		writeFile(fileName, rnd);
	}
	return 0;
}
