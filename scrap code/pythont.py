import sys
import os
import re

def main():
	(aaa,bbb,ccc) = (0,0,0)
	print aaa
	aaa = 4565
	print aaa
	print bbb
	print ccc
	
	ddd=sys.stdin.readlines()

	while(ddd!=[]):
		a_ddd = ddd[0]
		ccc = ccc+1
		bbb = bbb + len(a_ddd)
		print len(a_ddd)
		a_ddd = a_ddd.strip()		
		words = a_ddd.split()
		aaa = len(words) + aaa
		ddd = ddd[1:]
		print aaa, bbb, ccc
	print len("gay")

def fitemeirl():
    prices =[ "3.141500002", "12.125", "51.500"]
    for p in prices:
        print "Before --> ", p
        p = re.sub(r"(\.\d\d[1-9]?)\d*", r"\1", p)
        print "After --> ", p
        print ""

if __name__ == '__main__':
	fitemeirl()
