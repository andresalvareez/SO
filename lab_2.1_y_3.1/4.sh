#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 04 *******************************************"
echo "****************************************************************************************"

#Operadores lógicos:
#! = NOT
#-a = AND
#-o = OR
#&& = AND
#|| = OR

# este script pedirá un número al usuario y comprobará si el número está en el intervalo (0, 10)

# Definimos una variable para indicar si el usuario ha introducido un número válido
valid=false

# Mientras no se haya introducido un número válido
while [ "$valid" = false ]; do

    # Preguntamos al usuario por un número
    echo "Dame un número que esté en el intervalo (0, 10): "
    # Leemos el número y lo guardamos en la variable "num"
    read -r num
    # Comprobamos si el número introducido es un número
    if [[ "$num" =~ ^[0-9]+$ ]]; then
        # Si es un número, comprobamos si está en el intervalo (0, 10)
        if [ "$num" -gt 0 -a "$num" -lt 10 ]; then
            echo "El número está en el intervalo"
            valid=true
        # Si el número es menor que 0 o mayor que 10, entonces no está en el intervalo
        elif [ "$num" -lt 0 -o "$num" -gt 10 ]; then
            echo "El número no está en el intervalo"
            valid=true
        # Si el número no cumple ninguna de las condiciones anteriores, entonces no está en el intervalo
        else
            echo "El número no está en el intervalo"
            valid=true
        fi
    else
        # Si no es un número, informamos al usuario y repetimos la pregunta
        echo "Por favor, introduce un número válido"
    fi
done

# Comprobamos si num es diferente que 8
if [ "$num" != "8" ]; then
    echo "El número no es 8"
else
    echo "El número es 8"
fi

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
