#!/bin/bash
output=${1%.*}
cout=$output".cout.log"
cerr=$output".cerr.log"
log=$output".output.log"
output=$output".s"


echo "GCC:"


# On compile avec GCC le fichier donné en paramètre
echo -n " Compilation... "
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
	echo -n " Exécution... "
	# On execute le fichier compilé
	gcc_prog_output=$(./gcc_exe) # On récupére sa sortie standard
	gcc_prog_code=$?	     # Et son return code
	echo "OK"
	
	rm gcc_exe		     # On supprime le fichier compilé
	
	echo " L'exécution a retourné comme sortie standard ["
	echo $gcc_prog_output
	echo " ]"
	echo " RETURN CODE: $gcc_prog_code"
else
	echo "NOK"
fi
echo "Notre compilateur:"
echo -n " Compilation... "
./exe $1 1> $cout 2> $cerr
errorSize=$(wc -c $cerr | awk '{print $1}')
cat $cerr $cout > $log
rm $cerr
rm $cout
pld_comp=0
pld_prog_output="nothing1"
pld_prog_code=-2
if [ -f ./asm.s ] && [ $errorSize -eq 0 ]
then
	mv asm.s $output
	rm $log
	as -o pld_exe.o $output #&> /dev/null
	gcc pld_exe.o -o pld_exe #&> /dev/null
	rm pld_exe.o &> /dev/null
	pld_comp_code=$?
	
	# On test si le fichier a été correctement compilé
	if [ $pld_comp_code -eq 0 ]
	then
		pld_comp=1
		echo "OK"
		echo -n " Exécution... "
		# On execute le fichier compilé
		pld_prog_output=$(./pld_exe) # On récupére sa sortie standard
		pld_prog_code=$?	     # Et son return code
		echo "OK"
		rm pld_exe		     # On supprime le fichier compilé
	
		echo " L'exécution a retourné comme sortie standard ["
		echo $pld_prog_output
		echo " ]"
		echo " RETURN CODE: $pld_prog_code"
	else
		pld_comp=0
		echo "NOK1"
	fi
	
	pld_comp=1
	
else
	pld_comp=0
	echo "NOK2"
fi




echo -n "Resultat du test... "
if [ $pld_comp -ne $gcc_comp ]
then
	echo "NOK1"
	exit 1
fi
if [ $pld_comp -eq 1 ]
then
	if [ $gcc_prog_code -ne $pld_prog_code ]
	then
		echo "NOK2"
		exit 2
	fi
	if [ $gcc_prog_output != $pld_prog_output ]
	then
		echo "NOK3"
		exit 3
	fi
fi
echo "OK"
exit 0
