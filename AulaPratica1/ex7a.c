#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void exit_handler_1(){
	printf("This is exit handler 1\n");
}

void exit_handler_2(){
	printf("This is exit handler 2\n");
	//exit(2); troca a ordem de print na main.
}

int main(){
	atexit(exit_handler_1);
	atexit(exit_handler_2);
	//abort(); "Aborted (core dump)"
	printf("Main done!\n");

	return 0;
}