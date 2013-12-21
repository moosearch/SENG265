#!/bin/bash

./s265fmt3 testfiles/in01.txt > out.txt
diff -b out.txt testfiles/out01.txt

./s265fmt3 testfiles/in02.txt > out.txt
diff -b out.txt testfiles/out02.txt

./s265fmt3 testfiles/in03.txt > out.txt
diff -b out.txt testfiles/out03.txt

./s265fmt3 testfiles/in04.txt > out.txt
diff -b out.txt testfiles/out04.txt

./s265fmt3 testfiles/in05.txt > out.txt
diff -b out.txt testfiles/out05.txt

./s265fmt3 testfiles/in06.txt > out.txt
diff -b out.txt testfiles/out06.txt

./s265fmt3 testfiles/in07.txt > out.txt
diff -b out.txt testfiles/out07.txt

./s265fmt3 testfiles/in08.txt > out.txt
diff -b out.txt testfiles/out08.txt

./s265fmt3 testfiles/in09.txt > out.txt
diff -b out.txt testfiles/out09.txt

./s265fmt3 testfiles/in10.txt > out.txt
diff -b out.txt testfiles/out10.txt
