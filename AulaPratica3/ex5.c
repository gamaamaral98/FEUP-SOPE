#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int status;

	pid = fork();

	if(pid > 0){
		printf("friends!");
		wait(&status);
	}else{
		pid = fork();
		if(pid > 0){
			printf(" my ");
			wait(&status);
		}else{
			printf("Hello");
		}
	}

	return 0;
}