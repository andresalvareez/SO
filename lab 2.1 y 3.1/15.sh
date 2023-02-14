#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 15 *******************************************"
echo "****************************************************************************************"

echo "Introduzca un número: "
read -r x
sum=0
i=1
# i menor o igual que x
while [ $i -le $x ]; do
    # Hacemos la suma
    sum=$((sum + i))
    # Aumentamos i
    i=$((i + 1))
done
echo "La suma de los primeros $x números es: $sum"

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
