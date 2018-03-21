// PROGRAMA p6a.c
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
		exit(1);
	}
	if ( ( dst = fopen( "outfile.txt" , "w" ) ) == NULL ){
		//perror("ERRO");
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

/*b) & c)
	
	O programa não executa corretamente porque na linha 12, 
	fazíamos read e não write.
	O código de terminação é 1.

*/