#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv){
	FILE *iF_1;
	iF_1 = fopen(argv[1], "r");
	assert(iF_1 != NULL);

	int f1_l = 0;
	char c;
	do{
		c = fgetc(iF_1);
		if(c == '\n') f1_l++;
	}while(c != EOF);

	printf("Line of F1 is %d\n", f1_l);

	return 0;
}