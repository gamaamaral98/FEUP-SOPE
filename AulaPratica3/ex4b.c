#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int status, childpid;

	pid = fork();

	switch(pid){
		case 0:
			printf(" world !");
			break;
		default:
			printf("Hello");
	}
	return 0;
}