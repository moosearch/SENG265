/*
 * UVic SENG 265, Fall 2011, A#4
 *
 * This will contain a solution to s265fmt3. In order to complete the
 * task of formatting a file, it must open the file and pass the result
 * to a routine in uvic_formatter.c.  That routine will then return a
 * list of strings to be output to the console/terminal, but that output
 * must be generated in this module (even if the lines are generated
 * via code in uvic_formatter.c).
 */

#include <stdio.h>
#include <stdlib.h>
#include "uvic_formatter.h"

int main(int argc, char *argv[]) {
#ifdef DEBUG
    int num_lines;
    int i;
    char **result;
    char **list;
    FILE *infile;
    
	if (argc < 2) {
	/*get input from stdin*/
	list = create_array(stdin,&num_lines);
	}else{
		/*Open file*/
		infile = fopen(argv[1], "r");
		if (infile == NULL) {
			fprintf(stderr, "%s cannot open file named %s\n", argv[0], argv[1]);
			exit(1);
		}
		list = create_array(infile, &num_lines);		
	}

    result = format_lines(list, &num_lines);
    for (i = 0; i < num_lines; i++, result++) {
        printf("%s\n", *result);
    }
#endif
	exit(0);
}
