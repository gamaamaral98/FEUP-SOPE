#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
	printf("In SIGINT handler . . .\n");
}

int main(){

	struct sigaction action;

	//preparar a estrutura sigaction
	action.sa_handler = sigint_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	//Instalar o handler
	if(sigaction(SIGINT,&action,NULL) < 0){
		fprintf(stderr, "Unable to install SIGINT handler\n");
		exit(1);
	}

	printf("Sleeping for 30 seconds ... \n");
	sleep(30);
	printf("Waking up . . .\n");
	exit(0);
	
}