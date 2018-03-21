#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sigusr1_handler(int sign, int num){
	printf("Entering SIGUSR1 hanlder . . .\n");
	sleep(1);
	num++;
	printf("Exiting SIGUSR1 handler . . . \n");
}

void sigusr2_handler(int sign, int num){

}