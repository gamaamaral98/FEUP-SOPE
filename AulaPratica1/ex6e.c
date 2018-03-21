#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256
#define MAX 32600

int main(){
	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if ( ( src = fopen( "infile.txt", "r" ) ) == NULL){
		//perror("ERRO");
		printf("Error number: %d\n", errno);
		exit(1);
	}
	if ( ( dst = fopen( "outfile.txt" , "w" ) ) == NULL ){
		//perror("ERRO");
		printf("Error number: %d\n", errno);
		exit(2);
	}
	while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL ){
		fputs( buf, dst );
	}
	fclose( src );
	fclose ( dst );
	//perror("ERRO");
	exit(0); //zero é para sucesso.
}

/*
Alínea f)

Sim o resultado é o esperado.
*/