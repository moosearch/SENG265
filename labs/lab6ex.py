import sys #for command arguments
import os

if __name__=='__main__':
    f = open("Lab 5 Notes.txt","r")
    
    s = f.readlines()
    print s
    print len(s)
    
    for x in range(0,len(s)):
        s[x].split('\n')
        print s[x],
    
        
