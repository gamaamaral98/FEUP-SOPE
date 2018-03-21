#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int main(void){

	int fd[2];
	pid_t pid;

	pipe(fd);

	pid = fork();

	int status;

	if(pid > 0) //Processo pai;
	{
		int a[2];
		int rf[4];
		printf("Parent: (Usage: int int) \n");
		printf("x y ?");
		scanf("%d %d", &a[0], &a[1]);
		close(fd[READ]);
		write(fd[WRITE],a,2*sizeof(int));;
		close(fd[WRITE]);

		wait(pid, &status, WNOHANG);

		read(fd[READ], rf, 4*sizeof(int));
		printf("Soma: %d", rf[0]);
		printf("Sub: %d", rf[0]);
		printf("Mult: %d", rf[0]);
		printf("DIV: %d", rf[0]);
		close(fd[READ]);


	}
	else //filho
	{
		int b[2];
		int r[4];
		close(fd[WRITE]);
		read(fd[READ], b, 2*sizeof(int));
		close(fd[READ]);

		r[0] = b[0] + b[1];
		r[1] = b[0] - b[1];
		r[2] = b[0] * b[1];
		r[3] = b[0] / b[1];

		write(fd[WRITE], r, 4*sizeof(int));
		close(fd[WRITE]);
	}
	return 0;
}	