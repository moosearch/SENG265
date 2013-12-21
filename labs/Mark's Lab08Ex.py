#!/usr/bin/python
import re
""" create an array within a class to store everyone into a database, can access whatever information 
    you want through the index"""
class Person:
    def __init__(self, x):
        self.Id = x[0]
        self.name = x[1]
        self.email = x[2]

persons =[]
in_file = open("Data.txt", "r")

for line in in_file:
    mo = re.search(r'([0-9]+) ([A-Za-z ]+) ([\.\w]+@\w+\.\w+)',line)
    if mo:
        persons.append(Person(mo.group(1,2,3)))
        print mo.group(1),mo.group(2), mo.group(3)
print persons[2].name, persons[0].name 
