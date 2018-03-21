#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void){

	int fd[2];
	pid_t pid;

	pipe(fd);

	pid = fork();

	if(pid > 0) //Processo pai;
	{
		int a[2];
		printf("Parent: (Usage: int int) \n");
		printf("x y ?");
		scanf("%d %d", &a[0], &a[1]);
		close(fd[READ]);
		write(fd[WRITE],a,2*sizeof(int));;
		close(fd[WRITE]);
	}
	else //filho
	{
		int b[2];
		close(fd[WRITE]);
		read(fd[READ], b, 2*sizeof(int));
		printf("Son:\n");
		printf("x + y = %d\n", b[0] + b[1]);
		printf("x - y = %d\n", b[0] - b[1]);
		printf("x * y = %d\n", b[0] * b[1]);
		printf("x / y = %d\n", b[0] / b[1]);
		close(fd[READ]);
	}
	return 0;
}	