#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <sys/resource.h>

#define TOP_EXTREME_INDEX 1
#define TERMINATION_VALUE 2

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("usage: p8a n1 n2\n\tn1 Interval superior extreme\t n2 termination number");
		return 1;
	}

	int top_extreme = atoi(argv[TOP_EXTREME_INDEX]);
	int termination_value = atoi(argv[TERMINATION_VALUE]);

	if(termination_value > top_extreme){
		printf("Termination number is out of range!\n\n");
		return 2;
	}

	srand(time(0));
	int random;

	while(random != termination_value){
		random = rand()%top_extreme;
		printf("%d\n", random);
	}

	printf("\n");
	return 0;
}