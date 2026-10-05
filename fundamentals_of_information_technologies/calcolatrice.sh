#!/bin/bash
read -p "Primo valore " a
read -p "Operazione " o
read -p "Secondo valore " b

op=$( echo $a+$b | bc -l )
echo "Somma" $op

op=$( echo $a-$b | bc -l )
echo "Sottrazione" $op

op=$( echo $a*$b | bc -l )
echo "Moltiplicazione" $op

op=$( echo $a^$b | bc -l)
echo "Potenza" $op

if [ $b -eq 0 ]; then
	echo "Non posso effettuare la divisione"
else
	op=$( echo $a/$b | bc -l )
	echo "Divisione" $op
fi
