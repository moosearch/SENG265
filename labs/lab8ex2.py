#!/usr/bin/python

import os
import sys
import re

fpin = open("lab8data.txt",'r')
string = fpin.read()

"""ID FirstNAME LastNAME EMAIL PHONE"""

#pattern = "(\d+) ([A-Za-z]+) ([A-Za-z]+)"
#pattern = "(\d+) ([A-Za-z]+)+? ([A-Za-z]+) ([A-Za-z]+) [A-Za-z]\.+[A-za-z]@[A-Za-z]+\.[A-Za-z]+ \d{1}-\d{3}-\d{3}-\d{4}"


#pattern = r"(\d+) ([A-Za-z ]+) [A-Za-z\.]*?[A-za-z]@[A-Za-z]+\.[A-Za-z] \d{1}-\d{3}-\d{3}-\d{4}"

#pattern = "[A-Za-z\.]*?[A-za-z]@[A-Za-z]+\.[A-Za-z]+"

pattern = r"(\d+) ([A-Za-z ]+) ([A-Za-z\.]+@[A-Za-z]+\.[A-Za-z]+) (\d{1}-\d{3}-\d{3}-\d{4})"

"""
Mark's edition

pattern = r""

"""
co = re.compile(pattern)

mo = co.findall(string)

print mo
