#!/bin/bash

echo "****************************************************************************************"
echo "********************************* CATEGORIA ********************************************"
echo "****************************************************************************************"

# Si el valor por parámetro está
# entre 0 y 15, retorna el valor 1, si esta entre 15 y 55 retorna 2, si está entre 56 y 100
# retorna 3, si está entre 101 y 200 retorna 4 y si corresponde a otro valor, retorna 5.

valor=$1 # Guardar el valor por parámetro en una variable
#############################COMPROBACIONES#############################
comprobar_valor() {
    if ! [[ "$valor" =~ ^[0-9]+$ ]]; then # If para comprobar que el dato es correcto
        echo "Lo siento, el dato ingresado no es un número. Por favor, ingrese un número válido."
        return 0
    else
        return 1
    fi
}
#############################IMPRIMIR#############################
comprobar_valor "$valor"
if [ $? -eq 0 ]; then # Si la función comprovar_tamano() retorna 0, significa que el contenido es válido
    exit 1 # Si no es un número, se sale del script
else
    if [ "$valor" -ge 0 ] && [ "$valor" -lt 15 ]; then # Comprobar que el valor está entre 0 y 15
        echo "1"
    elif [ "$valor" -ge 15 ] && [ "$valor" -le 55 ]; then # Comprobar que el valor está entre 15 y 55
        echo "2"
    elif [ "$valor" -ge 56 ] && [ "$valor" -le 100 ]; then # Comprobar que el valor está entre 56 y 100
        echo "3"
    elif [ "$valor" -ge 101 ] && [ "$valor" -le 200 ]; then # Comprobar que el valor está entre 101 y 200
        echo "4"
    else
        echo "5"
    fi
fi