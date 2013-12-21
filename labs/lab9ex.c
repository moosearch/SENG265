#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINESIZE 500

/*Type for defining each person*/
typedef struct info
{
	char *id;
	char *name;
	char *email;
	char *phone;
}info_t;


info_t * allocate(size){
	void *ptr;
	ptr = malloc(size);
	if(ptr != NULL){
		return ptr;
	}else{
		printf("Unsuccessful dynamic allocation.");
		exit(1);
	}
}

int main(int argc, char *argv[]){
	FILE *fpin;
	info_t *database;
	info_t *ptr;
	char current_str[MAXLINESIZE];
	
	/*Open file for reading*/
	if(argc==2){
		fpin = fopen(argv[1], "r");
	}else{
		printf("Too many or little parameters. Exiting.\n");
		exit(1);
	}
	/*allocate memory for database*/
	ptr = allocate(sizeof(info_t)*50);
	database = ptr;
	
	/*allocate memory for string*/

	
	
	fgets(current_str,MAXLINESIZE,fpin);
	printf("%s\n",current_str);

	/*printf("%s %d",current_str,strlen(current_str));*/
	/*Initialise an array of structs*/
	return 0;
}
