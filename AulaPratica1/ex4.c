#include <stdio.h>
/*
Nesta função introduzimos o número de vezes que queremos ser saudados.
*/
int main(void){

	char nome[50];
	int n, i;

	printf("Introduza o número de vezes que quer ser saudado: \n");
	scanf("%i", &n);

	printf("Introduza o seu nome: \n");
	scanf("%s", nome);

	for(i = 0; i < n; i++){
		printf("Hello %s !\n", nome);
	}

	return 0;
}