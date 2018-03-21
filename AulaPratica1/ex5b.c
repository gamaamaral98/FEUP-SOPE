#include <stdio.h>
#include <string.h>

/*
Temos duas funçoes distintas para comparar strings:

1: int strcmp(const char *s1, const char *s2);
Compara duas strings s1 e s2, retorna um inteiro maior, igual ou menor que 0.

2: int strncmp(const char *s1, const char *s2, size_t n);
Compara apenas os primeiros "n" bits de s1 e s2.
*/


int main(int argc, char *argv[], char *env[]){
	unsigned int i, j;

	for(i=0; env[i]!=NULL; i++){
	
		if(strncmp(env[i], "USER=", 5) == 0){
	
			printf("Hello ");
	
			for(j = 5; ; j++){
	
				printf("%c", env[i][j]);
	
				if(env[i][j] == '\0')
					break;
			}
	
			printf("\n");
			break;
	
		}
	
	}
	
	return 0;
}
