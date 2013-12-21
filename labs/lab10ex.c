#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINESIZE 500



/*Type for defining each person*/
typedef struct info{
	char *information;
	struct info_t *next;
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
	info_t *head=NULL; /*head of the database*/
	info_t *cur; /*Holds line to be added to linked list*/
	info_t *temp; /*Used for traversing linked list*/
	char current_str[MAXLINESIZE];
	
	/*Open file for reading*/
	if(argc==2){
		fpin = fopen(argv[1], "r");
	}else{
		printf("Too many or little parameters. Exiting.\n");
		exit(1);
	}
	printf("dffdgfhfghgfh");
	/*Make linked list; each node corresponds to a line*/
	while(fgets(current_str,MAXLINESIZE,fpin)){
		/*allocate memory for a node*/
		cur = allocate(1*sizeof(info_t));
		cur->information = current_str;
		if(head==NULL){
			head=cur;	
		}else{
			temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = cur;
		}
	}/*end while*/
	
	temp = head;
	
	/*Print the stuff*/
	while(temp!=NULL){
		printf("%s",temp->information);
		temp=temp->next;
	}
	return 0;
}






