#!/usr/bin/python

import os
import sys

class myString:
    """A class for a string"""
    tot = 0
    def __init__(self,inputz):
        self.z = inputz
        
    def find(self,substr):
#        if(substr in self.z):
 #           i=0
 #           while(i+len(substr) < len(self.z)):
 #               if(substr is self.z[ i : (i+len(substr)) ]):
 #                   return i
  #              i=i+1
        return self.z.find(substr)

    def count(self,substr):
        if(substr in self.z):
            self.__class__.tot = self.__class__.tot + 1
        return self.__class__.tot
        
if __name__ == '__main__':

    fpin = open("the-hobbit.in",'r')
    total = 0
    for line in fpin:
        y=myString(line)
        
        find_value = y.find("hobbit")
        #print "First instance: ",
        #print find_value
        
        total = y.count("hobbit")
    
    print "Total times that hobbit came up: ",
    print total

    """
    x = fpin.readline()
    total = 0
    while(x):       
        y = myString(x)
        
        find_value = y.find("hobbit")
        print "First instance: ",
        print find_value
        
        total = y.count("hobbit")
        x = fpin.readline()
    #end while    
    """

