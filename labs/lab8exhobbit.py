#!/usr/bin/python

import os
import sys
import re

fpin = open("the-hobbit.in",'r')
string = fpin.read()

result = re.search(r"\bhobbit\b",string)
print "First instance of hobbit: ",
print result.start()

result = re.findall(r"hobbit\b",string)
print "# of occurances: ",
print len(result)
