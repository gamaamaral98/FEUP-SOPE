#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

typedef struct Numeros
{
	char x[10];
	char y[10];

} Numero;

int main(void){

	int fd[2];
	pid_t pid;

	pipe(fd);

	pid = fork();

	Numero numeros;

	if(pid > 0) //pai
	{
		printf("Pai:\n");
		printf("x ?\n"); scanf("%s", &numeros.x);
		printf("y ?\n"); scanf("%s", &numeros.y);
		close(fd[READ]);
		write(fd[WRITE], &numeros, 20*sizeof(char));
		close(fd[WRITE]);
	}
	else{
		close(fd[WRITE]);
		read(fd[READ], &numeros, 20*sizeof(char));
		printf("Son: \n");
		int a = atoi(numeros.x);
		int b = atoi(numeros.y);
		printf("x + y = %d\n", a+b);
		close(fd[READ]);
	}
	return 0;
}