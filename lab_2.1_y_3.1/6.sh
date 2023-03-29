#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 06 *******************************************"
echo "****************************************************************************************"

#$# número de parámetros pasados
#$0 devuelve el nombre del shell script que se está ejecutando y su ubicación en el 
#sistema de archivos
#$* devuelve en una cadena de caracteres todos los parámetros pasados al script
#$@ devuelve un array con los parámetros pasados al script

#!/bin/bash
# $0 es el nombre del script
echo "Nombre del script: $0"
# $1 es el primer argumento pasado al script
echo "Primer argumento pasado al script: $1"
# $2 es el segundo argumento pasado al script
echo "Segundo argumento pasado al script: $2"
# $# es el número de argumentos pasados al script
echo "Número de argumentos pasados al script: $#"
# $* son todos los argumentos pasados al script como una cadena de caracteres
echo "Todos los argumentos pasados al script como una cadena de caracteres: $*"
# $@ son todos los argumentos pasados al script como un array
echo "Todos los argumentos pasados al script como un array:" "$@"

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla