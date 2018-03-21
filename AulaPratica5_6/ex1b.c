#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

typedef struct Numeros 
{
	int a;
	int b;

} Numero;

int main(void){
	pid_t pid;
	int fd[2];

	pipe(fd);
	pid = fork();

	Numero numero;

	if(pid > 0) //pai
	{
		printf("Parent:\n");
		printf("x ? \n");
		scanf("%d", &numero.a);
		printf("y ? \n");
		scanf("%d", &numero.b);
		close(fd[READ]);
		write(fd[WRITE], &numero, 2*sizeof(int));
		close(fd[WRITE]);
	}
	else //filho
	{
		close(fd[WRITE]);
		read(fd[READ],&numero, 2*sizeof(int));
		printf("Son: \n");
		printf("x + y = %d\n", numero.a + numero.b);
		close(fd[READ]);
	}
	return 0;
}