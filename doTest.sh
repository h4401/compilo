#!/bin/bash
echo "On test le compilateur avec $1"
echo "--------------------AVEC GCC--------------------"
echo -n "La version de GCC utilisé est: ";
gcc -v 2>&1 | grep "gcc version"

# On compile avec GCC le fichier donné en paramètre
echo -n "Compilation... "
gcc $1 -o gcc_exe &> /dev/null


gcc_comp_code=$?
gcc_comp=0

gcc_prog_output="nothing"
gcc_prog_code=-1

# On test si le fichier a été correctement compilé
if [ $gcc_comp_code -eq 0 ]
then
	gcc_comp=1
	echo "OK"
	echo -n "Exécution... "
	# On execute le fichier compilé
	gcc_prog_output=$(./gcc_exe) # On récupére sa sortie standard
	gcc_prog_code=$?	     # Et son return code
	echo "OK"
	
	rm gcc_exe		     # On supprime le fichier compilé
	
	echo ""
	echo "L'exécution a retourné comme sortie standard ["
	echo $gcc_prog_output
	echo "]"
	echo "RETURN CODE: $gcc_prog_code"
else
	echo "NOK"
	echo "GCC n'a pas été en mesure de compiler."
fi
echo ""
echo "--------------------AVEC PLD--------------------"
echo -n "Compilation... "
./exe $1 &> /dev/null
as -o pld_exe.o asm.s &> /dev/null
gcc pld_exe.o -o pld_exe &> /dev/null
pld_comp_code=$?
rm pld_exe.o &> /dev/null
pld_comp=0

pld_prog_output="nothing1"
pld_prog_code=-2

# On test si le fichier a été correctement compilé
if [ $pld_comp_code -eq 0 ]
then
	pld_comp=1
	echo "OK"
	echo -n "Exécution... "
	# On execute le fichier compilé
	pld_prog_output=$(./pld_exe) # On récupére sa sortie standard
	pld_prog_code=$?	     # Et son return code
	echo "OK"
	rm gcc_exe		     # On supprime le fichier compilé
	
	echo ""
	echo "L'exécution a retourné comme sortie standard ["
	echo $pld_prog_output
	echo "]"
	echo "RETURN CODE: $pld_prog_code"
else
	echo "NOK"
	echo "Notre compilateur n'a pas été en mesure de compiler."
fi
echo ""
echo "--------------------RESULTAT--------------------"
if [ $pld_comp -ne $gcc_comp ]
then
	echo "Le test a échoué."
	exit 1
fi
if [ $pld_comp -eq true ]
then
	if [ $gcc_prog_code -ne $pld_prog_code ]
	then
		echo "Le test a échoué."
		exit 2
	fi
	if [ $gcc_prog_output != $pld_prog_output ]
	then
		echo "Le test a échoué."
		exit 3
	fi
fi
echo "Le test est un succès."
exit 0
