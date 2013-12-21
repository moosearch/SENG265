/*
 * UVic SENG 265, Spring 2013, A#4
 *
 * This will contain the bulk of the work for the fourth assignment. It
 * provide similar functionality to the class written in Python for
 * assignment #3, but without the need to format a list of strings.
 */

#include "uvic_formatter.h"

/*
 * Some constants
 */
#define FMT_OFF 0
#define FMT_ON 1
#define TRUE 1
#define FALSE 0

/* int pgwdth_mrgn
 * PARAMETERS: 1st = mrgn or pgwdth, 2nd = token w/ parameter
 * RETURN: variable value for either mrgn or pgwdth
 * DESCRIPTION: Handles values for mrgn or pgwdth.
 */
 
int pgwdth_mrgn(int variable, char * pch){
	int value;
	if(strncmp(pch,"0",5)!=0){
		value = atoi(pch); /*convert token into an int*/
		if (value==0) { /*If pch is a non-numeric char, it will be 0*/
			fprintf(stderr,"Invalid parameter in mrgn or pgwdth. Exiting.\n");
			exit(1);
		}
		
		if (strchr(pch,'+') || strchr(pch,'-')) {
			variable += value; /*Add value to current mrgn*/
		}else{
			variable = value; /*Assign new value to mrgn*/
		}
		
	}else{
		variable = 0;
	}
	return variable;
}


/* METHOD: int fmt_commands
 * PARAMETERS: A string of text, mrgn, page width, fmt, and first_time respectively
 * RETURN: 1 for format command being handled, 0 for no format command
 * DESCRIPTION: Will check for instances of format commands at the beginning of the 
 * line; does some basic error handling for misspelled format commands and invalid
 * parameters. It also will check to ensure that the mrgn is always less than or
 * equal to the page width by 20.
 */
int fmt_commands(char * string, int * mrgn, int * pgwdth, int * fmt, int *first_time){
	char * pch;
	if (string[0]=='?') {
		pch = strtok(string," ");
		
		/*Is first token == "?mrgn" ?*/
		if (strncmp(pch,"?mrgn",6)==0) {
			
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for mrgn. Exiting.\n");
				exit(1);
			}
			*mrgn = pgwdth_mrgn(*mrgn,pch);	
		/*Is first token == "?pgwdth" ?*/	
		}else if (strncmp(pch,"?pgwdth",8)==0) {
		
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for pgwdth. Exiting.\n");
				exit(1);
			}			
			*pgwdth = pgwdth_mrgn(*pgwdth,pch);	
		/*Is first token == "?fmt" ?*/				
		}else if(strncmp(pch,"?fmt",5)==0){
		
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for fmt. Exiting.\n");
				exit(1);
			}			
			if (strncmp(pch,"off",5)==0) { /*Check if is it off*/
				*fmt = FMT_OFF; 
			}else if (strncmp(pch,"on",5)==0) { /*Check if is it on*/
				*fmt = FMT_ON;
			}else{
				fprintf(stderr,"Invalid parameter in fmt. Exiting.\n");
				exit(1);
			}
		
		/*There was a question mark at beginning of string, but no valid format command*/
		}else{
			
			fprintf(stderr,"Invalid formatting command, check for question marks at the beginning of a line. Exiting.\n");
			exit(1);
		}
	/*If no question mark at beginning of string, assumed to be text*/	
	}else{
		return 0; 
	}
	
	/*Default behaviour*/
	if(*first_time==0 && (*mrgn != 0 || *pgwdth !=0)) {
		*fmt = FMT_ON;
		*first_time=1;
	}
	
	/*Check if pgwdth or mrgn have invalid integer values*/
	if(*mrgn < 0) {
		*mrgn = 0;
	}
	if(*pgwdth < 20) {
		*pgwdth = 20;
	}
	if (*mrgn > *pgwdth - 20) {
		*mrgn = *pgwdth - 20;
	}
	
	return 1; /*Implies that a format command was processed*/
}/*end fmt_commands*/


/* METHOD: void margins
 * PARAMETERS: String, size of mrgn
 * RETURN: Nothing
 * DESCRIPTION: Adds spaces to the beginning of the string.
 */
char * margins(char *ptr, int mrgn){
	int i;
	char *temp = malloc (sizeof(char)*(mrgn+1));
	if(temp==NULL){
		fprintf(stderr,"Error in dynamically allocating memory");
		exit(1);
	}
	for(i=0;i<mrgn;i++){
		*(temp+i) = ' ';
	}
	*(temp+mrgn) = '\0';
	*(ptr) = '\0';
	strncat (ptr,temp,mrgn+1);
	free(temp);
	return ptr;
}


/* METHOD: char ** increase_size
 * PARAMETERS: array of pointers, new size
 * RETURN: the new pointer
 * DESCRIPTION: Doubles the size of the dynamically allocated array.
 */
char ** increase_size(char ** ptr1,int size) {
	char ** temp;
	temp = ptr1;
	temp = (char **) realloc(ptr1, size*sizeof(char *));
	if(temp==NULL){
	
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);
	}
	return temp;

}

/* METHOD: char ** format_lines
 * PARAMETERS: your array of string pointers and the # of elements in the array.
 * RETURN: A new array of string pointers that is formatted
 * DESCRIPTION: This will format your text. Will call on other methods to deal
 * with format command handling, margins, and page widths.
 */

char ** format_lines(char ** list, int *num_lines){
	char ** list2 = NULL;
	int mrgn=0;
	int pgwdth=20;
	int fmt = FMT_OFF;
	int first_time = 0;
	
	char * pch;
	int i;
	int cur_pos = 0; /*current position of line*/
	int cur_len = 0;
	int list2_max;
	
	int partial_array = 0;
	
	list2 = (char **) malloc(sizeof(char *));
	list2_max = 1;
	if (list2 == NULL) {
	
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);	
	}	
	
	/*For each line*/

	for(i = 0;i<*num_lines;i++){
		
		/*Is array of string pointers full?*/
		if (cur_len>=list2_max) {
			list2_max *= 2;
			list2 = increase_size(list2,list2_max);
		}
		
		/*Process any format commands, list2 doesn't increase in size*/
		if( fmt_commands(list[i],&mrgn,&pgwdth,&fmt,&first_time) ){			
			if(fmt == FMT_OFF){
				cur_pos = 0;
			}
			continue;
		}
		
		/*
		Keep in mind that list2[cur_len] could be in the two states before executing
		the conditional statements:
			1. A partially filled one, presumably from formatting.
			2. An empty initialised one.
		*/
		
		/*Process newlines*/
		if (strlen(list[i]) == 0) {
			/*If this condition runs, then list2[cur_len] was in state #1
			otherwise, it is in state #2*/
			if(partial_array){
				cur_len++;
				partial_array = 0;
			}
			list2[cur_len] = (char *) malloc (sizeof(char *)); /*One spot for '\0'*/
			*list2[cur_len] = '\0';
			cur_len++;
			cur_pos = 0;
			continue;
		}
		
		if (fmt == FMT_OFF) {
			/*If this condition runs, then list2[cur_len] was in state #1
			otherwise, it is in state #2*/
			if(partial_array){
				cur_len++;
				partial_array = 0;
			}		
			list2[cur_len] = (char *) malloc ( (strlen(list[i])+1)*sizeof(char *) );
			strncpy(list2[cur_len],list[i],(strlen(list[i])+1));
			cur_len++;
		/*fmt on*/
		}else{
			
			/*Create a new block if there isn't already a partial filled list2[cur_len]*/
			if (!partial_array) {
				list2[cur_len] = (char *) malloc ( (pgwdth+1)*sizeof(char *) );
				cur_pos = 0;
				*list2[cur_len] = '\0';
			}
			
			pch = strtok(list[i]," ");
			/*Append tokens to line from list[i] string until no more.*/
			while(pch != NULL){
				
				/*Allocate more memory for array of pointers if needed*/
				if (cur_len>=list2_max) {
					list2_max *= 2;
					list2 = increase_size(list2,list2_max);
				}

				/*Add margin if start of new string (presumably after a newline*/
				if (cur_pos == 0) {
					list2[cur_len]=margins(list2[cur_len],mrgn);
					cur_pos+=mrgn;
				}
				
				/*Append to block if adding a word doesn't exceed block*/
				if (strlen(pch) + cur_pos <= pgwdth ) {
					strncat(list2[cur_len],pch,strlen(pch)+1);
					strncat(list2[cur_len]," ",2);
					cur_pos += strlen(pch) + 1;
				
				/*create new block and append token*/
				}else{
					cur_len++; /*update current size of formatted array*/
					cur_pos = 0; /*reset the line position pointer*/
					list2[cur_len] = (char *) malloc((pgwdth+1)*sizeof(char *));
					list2[cur_len]=margins(list2[cur_len],mrgn);
					cur_pos += mrgn;
					/*list2[cur_len] = '\0';*/
					strncat(list2[cur_len],pch,strlen(pch)+1);
					strncat(list2[cur_len]," ",2);
					cur_pos += strlen(pch) + 1;
				}

				pch = strtok(NULL, " ");
			}/*end while*/
			partial_array = 1;
		}/*end ifelse for fmt on/off*/	
		free(list[i]); /*free string at slot i in unformatted array*/
	}/*end for*/
	
	if(partial_array==1){
		cur_len++;
	}
	
	free(list);
	*num_lines = cur_len;
	return list2;
	
}/*end format_lines*/

/* METHOD: char ** create_array
 * PARAMETERS: Text file, current size for array, and max size for array
 * RETURN: A new array of string pointers that is unformatted
 * DESCRIPTION: This will dynamically allocate memory for an array of
 * string pointers for the whole text file.
 */
char ** create_array(FILE *infile, int *count){
	char ** ptr;
	int list_max;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	/*the array of pointers to strings*/
	ptr=(char **) malloc(sizeof(char *));
	if (ptr == NULL) {
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);	
	}

	list_max = 1;
	*count = 0;
	/*For each line, dyn allocate memory for string, then a pointer that is in
	an array of pointers will reference it*/
	while ((read = getline(&line, &len, infile)) != -1 && strncmp(line,"\\0",2)!=0) {
		line[strlen(line)-1] = '\0'; /* Replace '\n' with '\0' */
		
		/*expand pointer array if needed*/
		if(*count >= list_max){
		
			list_max *= 2;
			ptr = increase_size(ptr,list_max);
		}
		
		ptr[*count] = line;
		line=NULL;
		len=0;
		(*count)++;
	}
	return ptr;
}/*end create_array*/
