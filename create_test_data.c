#include <stdio.h>
#include <fcntl.h>   //open 
#include <unistd.h>  //write

#define MAXLINE_NUM 100000
#define MAXL 1000000
#define MAXBUFFER 100000

int main(){

	int fd = open("t.in", O_CREAT | O_WRONLY);

	char buffer[MAXBUFFER];
	char change_line[1] = {'\n'};
	int i, j;
	for(i = 0; i < MAXBUFFER; i++){
		buffer[i] = '0';
	}

	int r_size;
	for(i = 0; i < MAXLINE_NUM; i++){
		for(j = 0; j < MAXL / MAXBUFFER; j++){
			r_size = write(fd, buffer, (MAXL+1));	
		}
		r_size = write(fd, change_line, 1);
	}

	return 0;
}