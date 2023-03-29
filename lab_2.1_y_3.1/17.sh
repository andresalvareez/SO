#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 17 *******************************************"
echo "****************************************************************************************"

function check() {
    if [ -e "$1" ]; then # El $1 indica que el primer parámetro de la función y como no hay ruta significa que es un archivo de la carpeta actual
        return 0         # Devuelve 0 si el dato es válido
    else
        return 1         # Devuelve 1 si el dato no es válido
    fi
}
echo "Introduzca el nombre del archivo(de la carpeta actual): "
read -r x
if check "$x"; then
    echo "$x existe"
else
    echo "$x no existe"
fi
