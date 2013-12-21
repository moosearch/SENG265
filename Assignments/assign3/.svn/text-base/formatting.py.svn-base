#!/usr/bin/python
import sys
import os
import re

class seng265_formatter:
    """Initialise variables"""
    def __init__(self,item):
        self.format_numbers = [0,0,"off"] #[0] is pgwdth, [1] is mrgn, [2] is fmt
        self.mrgn_pointer = [0]
        self.first_time = [0]
        self.fpin = ""
        self.list_exist = 0
        #if item is list, get elements into a text file, then process it
        #else, item assumed to be a file directory to a text file
        if(type(item)==list):
            self.fpin = open("listfile.txt",'w')
            self.process_list(item,self.fpin)
            self.fpin.close() 
            self.fpin = open("listfile.txt",'r')         
            self.list_exist = 1
        else:    
            self.fpin = open(item,'r')
            
    def get_lines(self):
        fpresult = open("tempresult.txt",'w')
        x = self.fpin.readline()
        while(x):
            #check for format tags; if it equals to 1, get next line and reloop
            if(self.format_tags(x, self.format_numbers, self.first_time) == 1):
                x = self.fpin.readline()
                continue
            #print newline each time you hit a newline
            if(len(x)==1 and x == '\n'):
                x = self.newline(x, self.fpin, self.mrgn_pointer,fpresult)
                continue
            #fmt is off    
            if(self.format_numbers[2]=="off"):
                fpresult.write(x)
            #fmt is on
            else:
                x = x.split()     
                #format string
                self.formats(x, self.format_numbers, self.mrgn_pointer,fpresult)    
            #endIF
            x = self.fpin.readline()
        #end while
        
        #close and reopen file, get contents of file as a list of lines of strings
        fpresult.close()
        fpresult = open("tempresult.txt",'r')
        lines = fpresult.readlines()
        #close any remaining files
        fpresult.close()
        self.fpin.close()
        if(self.list_exist!=0):
            os.remove("listfile.txt")
            self.list_exist = 0
        os.remove("tempresult.txt")
        return lines
    ############################################################################################
    def newline(self,x,fpin,mrgn_pointer,fpresult):
        """x is string, fpin is file pointer, mrgn_pointer is current position
        of pointer. This method will loop print a newline, the loop through
        through any lines other lines that are also new lines. Returns x."""
        fpresult.write('\n')
        fpresult.write('\n')
        mrgn_pointer[0] = 0
        x = fpin.readline()
        while(len(x)==1 and x == '\n'):
            #print "\n",
            fpresult.write('\n')
            x = fpin.readline()
        return x        
    ############################################################################################
    def formats(self,x,format_numbers, mrgn_pointer,fpresult):
        """Loop through the list that contains the words of the line
        if word doesnt exceed page width, then print it out
        otherwise reset pointer to 0, add margin, and print word.
        x is a LIST of words, format_numbers is the LIST containing all 
        of the format specs, and mrgn_pointer is an int that is the current 
        position of the line"""
        
        #add margin if start of a new line
        if(mrgn_pointer[0]==0):
            mrgn_pointer[0] = self.add_mrgn(format_numbers[1],fpresult)    
        i=0
        #loop through the elements of the list x
        while(i<len(x)):
            if((mrgn_pointer[0]+len(x[i])+1)<=format_numbers[0]+1):
                fpresult.write(x[i]+" ")
                #print x[i],
            else:
                fpresult.write('\n')
                #print '\n', #comma for going to next line directly
                mrgn_pointer[0] = self.add_mrgn(format_numbers[1],fpresult) #add margin to output
                fpresult.write(x[i]+" ")
                #print x[i], #print text
            mrgn_pointer[0]=mrgn_pointer[0]+len(x[i])+1 #update line position
            i=i+1
        #endWHILE
        return None
    ############################################################################################
    def add_mrgn(self,mrgn,fpresult):
        """Prints spaces for the margin, mrgn is the mrgn size, returns mrgn size"""
        z=0
        for x in range(0,mrgn):
            fpresult.write(" ")
            #print "",
            z = z+1    
        return z
    ############################################################################################
    def format_tags(self,string,fmt_num,first_time):
        """This will deal with the format lines that occur in the text. This will take into account
        any extra spaces that may appear before '?' at the beginning of the line and between the format
        name and the value"""
    
        value = "" # placeholder variable for appending match.group variables
        
        #for page width
        match = re.search(r"^[ ]*?\?[ ]*?pgwdth([ ]*?)([-\+]?)(\d+)",string,re.IGNORECASE)
        if(match): 
            if(match.group(2)=='+' or match.group(2)=='-'):
                value = value+(match.group(2))
                value = value+(match.group(3))
                fmt_num[0] = int(value) + fmt_num[0]
            else:
                fmt_num[0] = int(match.group(3))
            if(first_time[0] == 0):
                fmt_num[2] = "on"
                first_time[0]=1;  
            self.mrgn_pgwdth_exceed(fmt_num)
            return 1
        
        #for margin width
        match = re.search(r"^[ ]*?\?[ ]*mrgn([ ]+?)([-\+]?)(\d+)",string,re.IGNORECASE)
        if(match):
            if(match.group(2)=='+' or match.group(2)=='-'):
                value = value+(match.group(2))
                value = value+(match.group(3))
                fmt_num[1] = int(value) + fmt_num[1]
            else:
                fmt_num[1] = int(match.group(3))
            if(first_time[0] == 0):
                fmt_num[2] = "on"
                first_time[0]=1;
            self.mrgn_pgwdth_exceed(fmt_num)
            return 1
        
        #for format on or off
        match = re.search(r"^[ ]*?\?fmt([ ]+?)(off)",string,re.IGNORECASE)
        if(match):
            fmt_num[2] = match.group(2)
            return 1
        match = re.search(r"^[ ]*?\?fmt([ ]+?)(on)",string,re.IGNORECASE)
        if(match):
            fmt_num[2] = match.group(2)
            return 1
            
        #return 0 otherwise if it's none of the above, implies that it's text
        return 0    
    ############################################################################################    
    def mrgn_pgwdth_exceed(self,fmt_num):
        """Method will change margin to pgwdth-20 if current mrgn>pgwdth-20"""
        if(fmt_num[1]+20>fmt_num[0]):
            fmt_num[1] = fmt_num[0]-20
        elif(fmt_num[1]<0):
            fmt_num[1]=0  
        return None 
    ############################################################################################   
    def process_list(self,item,fpin):
        """Read a list into a file for writing"""
        i=0
        while(i<len(item)):
            fpin.write(item[i]+'\n')
            i=i+1
        return None
