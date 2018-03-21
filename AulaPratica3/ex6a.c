#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	pid_t pid;
	int i, j;
	int status;

	printf("I'm process %d. My parent is %d.\n", getpid(), getppid());
	for (i = 1; i <= 3; i++) {
		pid = fork();
		if (pid < 0) {
			printf("Fork error");
			exit(1);
		}
		else if(pid == 0){
			printf("I'm process %d. My parent is %d. I'm going to work for 1 second . . .\n",getpid(),getppid());
			sleep(1);
			printf("I'm process %d. My parent is %d. I finished my work\n", getpid(), getppid());

			//exit(0);
		}
		else{
			for( j = i; j <= 10; j++){
				sleep(1);
				printf("Father working . . .\n");
				//waitpid(pid, &status, WNOHANG);
			}
		}	
	}
	exit(0);
}