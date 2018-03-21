#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]){

	int fd1, fd2, r, w;
	char* buffer[BUFFER_SIZE];

	if(argc != 3){
		printf("Usage: %s <source> <destination>\n", argv[0]);
		return 1;
	}

	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1){
		perror(argv[1]);
		return 2;
	}

	fd2 = open(argv[2], O_EXCL | O_CREAT | O_WRONLY, 0644);
	if(fd2 == -1){
		perror(argv[2]);
		return 3;
	}

	while((r = read(fd1, buffer, BUFFER_SIZE)) > 0)
		if((w = write(fd2, buffer, r)) <= 0 || w != r){
			perror(argv[2]);
			close(fd1);
			close(fd2);
			return 4;
		}
		close(fd1);
		close(fd2);
		return 0;
}