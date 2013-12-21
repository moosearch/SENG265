#!/bin/bash
./s265fmt3 testfiles/in11.txt > out.txt
diff -b out.txt testfiles/out11.txt

./s265fmt3 testfiles/in12.txt > out.txt
diff -b out.txt testfiles/out12.txt

./s265fmt3 testfiles/in13.txt > out.txt
diff -b out.txt testfiles/out13.txt

./s265fmt3 testfiles/in14.txt > out.txt
diff -b out.txt testfiles/out14.txt

./s265fmt3 testfiles/in15.txt > out.txt
diff -b out.txt testfiles/out15.txt

./s265fmt3 testfiles/in16.txt > out.txt
diff -b out.txt testfiles/out16.txt

./s265fmt3 testfiles/in17.txt > out.txt
diff -b out.txt testfiles/out17.txt

./s265fmt3 testfiles/in18.txt > out.txt
diff -b out.txt testfiles/out18.txt

./s265fmt3 testfiles/in19.txt > out.txt
diff -b out.txt testfiles/out19.txt

./s265fmt3 testfiles/in20.txt > out.txt
diff -b out.txt testfiles/out20.txt
