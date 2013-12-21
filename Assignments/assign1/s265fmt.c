/*****************************
s265fmt.c
Wesley Chow V00727646
Spring 2013 SENG 265 Assignment 1
Due Feb 5 at 9AM 
use -ansi tag to compile

Program Description: 
Given a text file, it will format it
with specified word wrapping and margin
indenting.
******************************/

#include <stdio.h>
#include <string.h>
#define MAX 128

void formatting_tags(FILE *fpin, char line[MAX], int *width, int *mrgn_left, int *fmt)
{   
    char *token;
    char holder;
    fgets(line,128,fpin);
    token = strtok(line, " ");
    fprintf(stdout,"%s\n",token);
        
    while(strncmp(token,"?pgwidth ",15)==0 || strncmp(token,"?mrgn ",15) ==0 || strncmp(token, "?fmt ",15)==0)
    {
        if(token == "?pgwidth"){
            printf("Testing");
            token = strtok(NULL, "\n");
            *width = atoi(token);
        }else if(token =="?mrgn"){ 
            token = strtok(NULL,"\n");
            *mrgn_left = atoi(token);
        }else{
            token = strtok(NULL, "\n");
            if(strncmp(token,"on",15)==0) fmt = 1;
            else fmt = 0;
        }
    }
}

int main()
{
    FILE *fpin;
    FILE *fpout;
    int width;
    int mrgn_left;
    int fmt;
    fprintf(stdout,"-\ns265fmt.c : This is a text formattor.\nWesley Chow-V00727646\nSeng265 Assignment 1\n\n");

	fpin = fopen("in03.txt", "r");  /* open the file for reading */
	if (fpin == NULL) {
		fprintf(stderr, "Cannot open input file - Bye\n");
		return(0); /*if problem, exit program*/
    }else{
        fprintf(stdout,"Input file is opened for reading.\n");
    }

    fpout = fopen("OutTest.txt","w"); /* open the file for writing */
    if (fpout == NULL) {
        fprintf(stderr, "Cannot open output file - Bye\n");
        return(0); /*if problem, exit program*/
    }else{
        fprintf(stdout,"Output file is opened for writing.\n");
    }
    fprintf(stdout,"Now executing...\n");
    
    char line[MAX];
    formatting_tags(fpin,line,&width,&mrgn_left,&fmt);
    return 0;
}















