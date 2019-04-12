#!/bin/bash

for dir in tests/*/*.c
do
	echo "$dir:"
	./doTest.sh $dir
	echo ""
done
for dir in tests/*/*/*.c
do
	echo "$dir:"
	./doTest.sh $dir
	echo ""
done
