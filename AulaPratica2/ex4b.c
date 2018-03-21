#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_NAMES 5
#define MAX_NUM_LEN 15

typedef struct Student{
	char name[MAX_NAME_LEN];
	int grade;
} Student;

int main(int argc, char* argv[]){
	if( argc != 2 ){
		printf("Usage: %s <file_name> \n", argv[0]);
		return 1;
	}

	int file = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT);
	if(file == -1){
		printf("Error opening the file.\n");
		return 2;
	}

	//Declarar um array que contém estruturas Student e um Student arbitrário.
	Student students[MAX_NUM_NAMES];
	Student s;

	printf("Enter %d students names and their respective grades at SOPE:\n", MAX_NUM_NAMES);

	int i; 

	for(i = 0; i < MAX_NUM_NAMES; i++){
		printf("Name:");
		fgets(s.name, MAX_NAME_LEN, stdin);

		printf("Grade: ");
		scanf("%d", &s.grade);
		getchar();
		
		students[i] = s;
	}

	for( i = 0; i < MAX_NUM_NAMES; i++){
		write(file, &students[i], sizeof(Student));
	}

	close(file);

	return 0;

}