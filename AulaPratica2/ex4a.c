#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_NUM_NAMES 5
#define MAX_NUM_LEN 15

int main(int argc, char* argv[]){

	if(argc != 2){
		perror(argv[0]);
		printf("Usage: %s <file_name> \n", argv[0]);
		return 1;
	}

	//Open the file to write.
	int file = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT);
	if(file == -1){
		perror(argv[1]);
		printf("Failed to open the document for writting!\n");
		return 2;
	}

	//Read student names and grades

	char names[MAX_NUM_NAMES][MAX_NAME_LEN];
	char grades[MAX_NUM_NAMES][MAX_NUM_LEN];

	printf("Enter %d student names and their respective grades.\n", MAX_NUM_NAMES);

	int i;

	for(i=0; i < MAX_NUM_NAMES; i++){
		printf("\nName: ");
		fgets(names[i], MAX_NAME_LEN, stdin);
		printf("\nGrade: ");
		fgets(grades[i], MAX_NUM_LEN, stdin);
	}

	//Write them to a file

	for(i = 0; i < MAX_NUM_NAMES; i++){
		write(file, names[i], strlen(names[i])-1);
		write(file, " - ", strlen(" - "));
		write(file, grades[i], strlen(grades[i])-1);
		write(file, "\n", strlen("\n"));
	}

	close(file);
	return 0;

}

//Juntei a opção de criar um ficheiro caso ele não exista.
//Ao executar "cat <nome_do_ficheiro>" verifiquei que foi tudo escrito corretamente.