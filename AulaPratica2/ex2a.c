#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]){
	//int fd1, fd2, nr, nw;
	
	unsigned char buffer[BUFFER_SIZE];

	if(argc != 3 ){
		printf("Usage: %s <source> <destination>\n\n", argv[0]);
		return 1;
	}

	FILE* fd1 = fopen(argv[1], "r");
	if(fd1 == NULL){
		perror(argv[1]);
		return 2;
	}

	FILE* fd2 = fopen(argv[2], "w");
	if(fd2 == NULL){
		perror(argv[2]);
		return 3;
	}

	size_t num_chars;
	while((num_chars = fread(buffer, sizeof(char), BUFFER_SIZE, fd1)) > 0){
		fwrite(buffer, sizeof(char), num_chars, fd2);
	}

	fclose(fd1);
	fclose(fd2);

	printf("Copying done\n\n");
	return 0;

}