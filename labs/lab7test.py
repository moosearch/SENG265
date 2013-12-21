#!/usr/bin/python

import os
import sys
import lab7ex.py

if __name__ == '__main__':

    fpin = open("the-hobbit.in",'r')
    string = fpin.readlines()
    tester = myString(string) #declare a class
    x = tester.count(hobbit) #call method from the myString class
    print x
