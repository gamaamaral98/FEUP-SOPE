#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]){
	if((argc != 2) && (argc != 3)){
		printf("Usage: %s <source> OR %s <source> <destination>\n", argv[0], argv[0]);
		return 1;
	}

	int fd1, fd2, r, w;
	unsigned char buffer[BUFFER_SIZE];

	if(argc == 2){
		fd1 = open(argv[1], O_RDONLY);
		if(fd1 == -1){
			perror(argv[1]);
			return 2;
		}

		while(( r = read(fd1, buffer, BUFFER_SIZE)) > 0){
			write(STDOUT_FILENO, buffer, r);
		}
	}
	else if(argc == 3){
		fd1 = open(argv[1], O_RDONLY);
		if(fd1 == -1){
			perror(argv[1]);
			return 2;
		}

		fd2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 0644);
		if(fd2 == -1){
			perror(argv[2]);
			close(fd1);
			return 3;
		}

		while(( r = read(fd1, buffer, BUFFER_SIZE)) > 0){
			write(fd2, buffer, r);
		}
	}

	close(fd1);
		
	return 0;
}