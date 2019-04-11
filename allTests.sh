#!/bin/bash

for dir in tests/*/*.c
do
	echo "$dir"
	./doTest.sh $dir &> /dev/null

done
for dir in tests/*/*/*.c
do
	echo "$dir"
	./doTest.sh $dir &> /dev/null

done
