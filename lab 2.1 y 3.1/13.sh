#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 13 *******************************************"
echo "****************************************************************************************"

echo "Introduzca el nombre de un directorio: "
read -r directorio
echo "Enlaces simbólicos en el directorio $directorio "
for fichero in $(find "$directorio" ); do # Se buscan los ficheros en el directorio introducido
    echo "$fichero"
done

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla