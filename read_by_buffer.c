#include <stdio.h>
#include <assert.h>
#include <fcntl.h>   //open 
#include <unistd.h>  //read

#define MAXBUFFER 100000	

int count_line_in_array(char* buffer, int size){
	int i, count = 0;
	for(i = 0; i < size; i++){
		if(buffer[i] == '\n')count++;
	}
	return count;
}

int main(int argc, char** argv){
	int fd1 = open(argv[1], O_RDONLY);
	assert(fd1 >= 0);

	char buffer[MAXBUFFER];
	int f1_l = 0, r_size = 0;

	do{
		r_size = read(fd1, buffer, MAXBUFFER);
		//printf("r_size = %d\n", r_size);
		if(r_size > 0){
			f1_l += count_line_in_array(buffer, r_size);
		}
	}while(r_size > 0);

	printf("Line of F1 is %d\n", f1_l);

	return 0;
}