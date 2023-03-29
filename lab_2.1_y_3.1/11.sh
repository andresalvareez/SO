#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 11 *******************************************"
echo "****************************************************************************************"

# Lista todos los ficheros del directorio /bin

for x in /bin; do
    ls -l "$x" # Se listan los ficheros del directorio /bin
done

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
