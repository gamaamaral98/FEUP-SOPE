#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	//write(STDOUT_FILENO,"1",1);
	//printf("1");
	printf("1\n");

	if(fork() > 0){
		//write(STDOUT_FILENO,"2",1);
		//write(STDOUT_FILENO,"3",1);
		printf("2");
		printf("3");
	} else {
		//write(STDOUT_FILENO,"4",1);
		//write(STDOUT_FILENO,"5",1);
		printf("4");
		printf("5");
	}
	//write(STDOUT_FILENO,"\n",1);
	return 0;
}