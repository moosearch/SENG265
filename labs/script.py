#!/usr/bin/python

print "hello world"
#tup = [(1,2,3),(4,2,5),(8,9)]
tup = [(1,2), (3,)]
print "original array: "
#print tup
newlist =[]
print 

for b in range(0,len(tup),1): #runs from 0 to nth index spot of original list
    print "Value of b"
    print b
    print "Length of tup[b]"
    print len(tup[b])
    for c in range (0,len(tup[b]),1): #runs from 0 to nth index of the tuple in the list
        
        y = tup[len(tup)-b-1][tup[len(len(tup)-b-1)-c]
        newlist += (y,)
print "end for"
print "\nNew array:"
print newlist
#it should print [(9,8),(5,2,4),(3,2,1)]
