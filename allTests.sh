#!/bin/bash
echo "Execution des tests du compilateur..."
c=0
r=0
for dir in Tests/*/*.c
do
	c=$((c+1))
	echo -n $dir
	echo -n "... "
	./doTest.sh $dir &> /dev/null
	code=$?
	if [ $code -eq 0 ]
	then
		r=$((r+1))
		echo "OK"
	else
		echo -n "NOK "
		if [ $code -eq 1 ]
		then
			echo "(L'un des compilateurs n'a pas pu compiler.)"
		fi
		
		if [ $code -eq 2 ]
		then
			echo "(Le RETURN CODE retourné n'est pas correct.)"
		fi
		
		if [ $code -eq 3 ]
		then
			echo "(La sortie standard retournée n'est pas correct.)"
		fi
	fi
done
echo ""
echo "--------------------RESULTAT--------------------"
echo "$r/$c des tests ont réussi."
