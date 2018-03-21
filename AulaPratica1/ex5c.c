#include <stdio.h>
#include <stdlib.h> 

int main(void){
	printf("Hello %s !\n", getenv("USER"));
	return 0;
}