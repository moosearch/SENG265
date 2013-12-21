/* 
 * UVic SENG 265, Spring 2013, A#4
 *
 * Code for driver.c -- Calls the "format_lines()" routine within the
 * uvic_formatter.c module.  ("format_lines()" may, of course, be called
 * from within other programs that also link in uvic_formatter.o.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uvic_formatter.h"

/*Given a multiline string literal, convert it into an array
of character pointers.*/
char ** alloc_mem(char * lines[],int num_lines){
	char ** ptr;
	int i;
	ptr = malloc(sizeof(char *)*(num_lines));
	if (ptr == NULL) {
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);	
	}	
	for (i=0;i<num_lines;i++) {
		
		ptr[i] = malloc(sizeof(char)*(strlen(*(lines+i))+1));
		strncpy(ptr[i],lines[i],strlen(*(lines+i))+1);
	}
	return ptr;
}

int main(int argc, char *argv[]) {
	char **result;
	int  num_lines = 10;
	char *lines[] = {
		"?pgewdth 30",
		"While there    are enough characters   here to",
		"fill",
		"   at least one line, there is",
		"plenty",
		"of",
		"            white space that needs to be",
		"eliminated",
		"from the original",
		"         text file."	
	};
	char **line;
	char **list;
	
	/*Convert multi-string into lines pointed by pointers in an array*/	
	list = alloc_mem(lines,num_lines); 

	/*Get result*/
	result = format_lines(list, &num_lines);
	
	/*We do not need to free list, as it is already done*/
	
	if (result == NULL) {
		printf("%s: it appears 'format_lines' is not yet complete\n",
			argv[0]);
		exit(1);
	}

	for (line = result; *line != NULL; line++) {
		printf ("%s\n", *line);
	}

	exit(0);
}











