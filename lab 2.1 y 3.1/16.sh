#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 16 *******************************************"
echo "****************************************************************************************"

# Lee un número para empezar el bucle de cuenta atrás
echo "Introduzca un número: "
read -r x
echo

# Empieza el bucle
until [ "$x" -le 0 ]; do
    echo "$x"
    ((x = x - 1)) # El (( )) es para hacer operaciones aritméticas
    sleep 1
done

# Termina el bucle
echo
echo FIN

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla