#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status, childpid;

	pid = fork();
	switch(pid){
		case 0: // filho
			//sprintf(str,"Hello");
			//write(STDOUT_FILENO,str,strlen(str));
			printf("Hello ");
			break;
		default: //pai
			//sprintf(str,"world !");
			//write(STDOUT_FILENO,str,strlen(str));
			printf("world !");
			childpid = wait(&status);
			//break;
	}
	return 0;
}