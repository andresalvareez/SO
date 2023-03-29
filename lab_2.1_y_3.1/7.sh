#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 07 *******************************************"
echo "****************************************************************************************"

# For loop

# Se inicializa la variable
sum=0
# Por cada número del 1 al 4, se suma a la variable sum.
for num in 1 2 3 4; do
    sum=$((sum + num))
done
# La suma de los números del 1 al 4 es 10.
echo "Las suma de $num y los números menores a $num es $sum."

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
