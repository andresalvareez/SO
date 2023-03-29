#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 12 *******************************************"
echo "****************************************************************************************"

# Lista todos los ficheros del directorio actual
for x in *; do
    ls -a $x # Se listan todos los ficheros del directorio actual
done
¡
sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
