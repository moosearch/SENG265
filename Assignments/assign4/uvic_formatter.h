#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

int pgwdth_mrgn(int variable, char * pch);
/*
This is a subset of the fmt_commands method 
used to handle mrgn or pgwdth commands.
Variable = mrgn or wdth
pch = value to be added or assigned to mrgn/pgwdth
*/

int fmt_commands(char * string, int * mrgn, int * pgwdth, int * fmt, int *first_time);
/*
This handles any format commands that come 
at the beginning of the line. It will handle
any invalid parameters or mispelt format
command errors.
string = string passed in
first_time = detects notion of first time for 
	turning on fmt if mrgn or pgwdth were set
*/

char * margins(char *ptr, int mrgn);
/*
This method appends a margin of a specified
size to a string passed in with it
ptr = string
mrgn = mrgn size
*/

char ** increase_size(char ** ptr1,int size);
/*
This method will increase the size of an array of 
pointers dynamically.
ptr1 = array of pointers to expand
size = desired size (usually twice the original size)
*/

char ** format_lines(char ** list, int *num_lines);
/*
This formats any array of char pointers that is passed in
and calls on all the other methods in this class.
list = array of char pointers
*num_lines = length of list
*/

char ** create_array(FILE *infile, int *count);
/*
This method creates an array of pointers, given a file or
from stdin.
*infile = input stream (file or stdin)
*count = size of array of pointers after it has been made
*/
