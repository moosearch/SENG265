#Wesley Chow V00727646
#SENG265 Assignment 2
#Due Feb 27, 2013 at 9PM
#Work with 2.6 Python

#!/usr/bin/python
import sys
import os

############################################################################################
def formats(x, format_numbers, mrgn_pointer):
    """Loop through the list that contains the words of the line
    if word doesnt exceed page width, then print it out
    otherwise reset pointer to 0, add margin, and print word.
    x is a LIST of strings, format_numbers is the LIST containing all 
    of the format specs, and mrgn_pointer is an int that is the current 
    position of the line"""
    
    #add margin if start of a new line
    if(mrgn_pointer==0):
        mrgn_pointer = add_mrgn(format_numbers[1])    
    i=0
    #loop through the elements of the list x
    while(i<len(x)):
        if((mrgn_pointer+len(x[i])+1)<=format_numbers[0]+1):
            print x[i],
        else:
            print '\n', #comma for going to next line directly
            mrgn_pointer = add_mrgn(format_numbers[1]) #add margin to output
            print x[i], #print text
        mrgn_pointer=mrgn_pointer+len(x[i])+1 #update line position
        i=i+1
    #endWHILE
    return mrgn_pointer
############################################################################################
def add_mrgn(mrgn):
    """Prints spaces for the margin, mrgn is the mrgn size, returns mrgn size"""
    z=0
    for x in range(0,mrgn):
        print "",
        z = z+1    
    return z
############################################################################################
def format_tags(string, fmt_num,first_time):
    """This is for checking if there are formatting tags present;
    string is the string to be checked, fmt_num is the list
    of text format settings, and first_time is to check for
    first time format sets (used to turn on formatting if any 
    parameters are set). 
    Return 1 if there is a formatting tag, 0 otherwise"""
    #Check for presence of ? at 0th index of string
    if(string[0] == "?"):
        #if ?pgwdth, store in list
        if('?pgwdth' in string):
            string = string.split()
            fmt_num[0] = int(string[1])
            if(first_time[0] == 0):
                fmt_num[2] = "on"
                first_time[0]=1;
        #if ?mrgn, store in list             
        elif('?mrgn' in string):
            string = string.split()
            if('+' in string[1] or '-' in string[1]):
                fmt_num[1] = int(string[1])+fmt_num[1]
            else:
                fmt_num[1] = int(string[1])                
            #check if mrgn exceeds pdwdth-20 or is below 0
            if(fmt_num[1]+20>fmt_num[0]):
                fmt_num[1] = fmt_num[0]-20
            elif(fmt_num[1]<0):
                fmt_num[1]=0
                
            if(first_time[0] == 0):
                fmt_num[2] = "on"
                first_time[0]=1;            
        #if ?fmt, store in list
        elif('?fmt' in string):
            string = string.split()
            fmt_num[2] = string[1]
        #if none of the above, return 0 for no formatting tags
        else: 
            return 0
        #return 1 to indicate formatting tag was processed
        return 1       
    #if no presence of '?', return 0
    else:
        return 0

############################################################################################
def newline(x,fpin,mrgn_pointer):
    """x is string, fpin is file pointer, mrgn_pointer is current position
    of pointer. This method will loop print a newline, the loop through
    through any lines other lines that are also new lines. Returns x."""
    print '\n' 
    mrgn_pointer[0] = 0
    x = fpin.readline()
    while(len(x)==1 and x == '\n'):
        print "\n",
        x = fpin.readline()
    return x
############################################################################################
def process_stdin():
    """No file name was input, so have to accept text from console"""
    
    print "Hello, since there was no filename input as a parameter enter your", 
    print "lines of text. To end the stream of text, type \"-1\" on a new line\n"
    fpout = open("write.txt",'w')
    x = raw_input()
    while(x != "-1"):
        fpout.write(x+"\n")
        x = raw_input()
    fpout.close()
    return None
############################################################################################
if __name__ == '__main__':
    #[0] is pgwdth, [1] is mrgn, [2] is fmt
    format_numbers = [0,0,"off"] 
    
    input_from_stdin = 0
    #open file for reading, read through argument
    if(len(sys.argv)>1):
        fpin = open(sys.argv[1],'r')
        x = fpin.readline()
    else:
        process_stdin() #get input from console, WRITE to file, then re-open for reading
        
        fpin = open("write.txt",'r')
        x=fpin.readline()
        #print "FORMATTED TEXT:\n"
        input_from_stdin = 1
    mrgn_pointer = [0];
    first_time = [0];
    
    while(x):
        #format_check will equal 1 if there are format tags processed
        format_check = format_tags(x,format_numbers, first_time)
        if(format_check==1): 
            x = fpin.readline()
            continue
        
        #deals with new lines
        if(len(x)==1 and x == '\n'):
            x = newline(x, fpin, mrgn_pointer)
            continue
            
        #if fmt is off, then just print the line
        if(format_numbers[2]=="off"):
            print x,
        #if fmt is on, then format accordingly
        else:
            x = x.split()     
            #format string, return current position of mrgn_pointer
            mrgn_pointer[0] = formats(x, format_numbers, mrgn_pointer[0])    
        #endIF
        x = fpin.readline()
    #endWHILE
    fpin.close()
    if(input_from_stdin == 1):
        os.remove("write.txt")

#end program   

        
        
