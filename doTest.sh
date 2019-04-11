#!/bin/bash
output=${1%.*}
error=$output".cout.log"
output=$output".s"

rm asm.s

./exe $1 &> $error
if [ -f ./asm.s ]
then
	echo $output
	mv asm.s $output
	rm $error
fi
