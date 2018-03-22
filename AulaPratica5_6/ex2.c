#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdio.h>

#define READ 0
#define WRITE 1

int main(void){
	pid_t pid, w;
	int fd1[2], fd2[2];
	int status;

	pipe(fd1);
	pipe(fd2);
	pid = fork();

	if(pid > 0){
		int a[2];
		int op[4];
		printf("Parent: x y ?\n");
		scanf("%d and %d", &a[0], &a[1]);
		close(fd1[READ]); 
		close(fd2[WRITE]);

		write(fd1[WRITE], a, 2*sizeof(int));
		close(fd1[WRITE]);

		w = wait(&status);

		read(fd2[READ], op, 4*sizeof(int));
		
		printf("My son calculated: \n");
		printf("Soma = %d\n", op[0]);
		printf("Mult = %d\n", op[1]);
		printf("Dif = %d\n", op[2]);
		printf("Invalid Operation.");

		close(fd2[READ]);

	}else{
		int b[2];
		int c[4];
		close(fd1[WRITE]); 

		close(fd2[READ]);
		read(fd1[READ], b, 2*sizeof(int));

			c[0] = b[0] + b[1];
			c[1] = b[0] * b[1];
			c[2] = b[0] - b[1];
			c[3] = b[0] / b[1];
		
		write(fd2[WRITE], c, 4*sizeof(int));
		close(fd2[WRITE]);
		close(fd1[READ]);
	}
	return 0;
}