#!/bin/bash

echo "****************************************************************************************"
echo "********************************* TABLAX ***********************************************"
echo "****************************************************************************************"

valor=$1
#############################COMPROBACIONES#############################
comprobar_valor() {
    if ! [[ "$valor" =~ ^[0-9]+$ ]]; then # If para comprobar que el dato es correcto
        echo "Lo siento, el dato ingresado no es un número. Por favor, ingrese un número válido."
        return 0
    else
        if [ "$valor" -eq 0 ]; then
            echo "El valor es 0"
            echo "Por lo que todos los valores de la tabla de multiplicar seran 0"
            exit 1 # Salir del script
        fi
        return 1
    fi
}
#############################IMPRIMIR#############################
comprobar_valor "$valor"
if [ $? -eq 0 ]; then # Si la función comprovar_tamano() retorna 0, significa que el contenido es válido
    exit 1            # Si no es un número, se sale del script
else
    for ((i = 1; i <= 12; i++)); do         # Se crea el bucle for para las tablas de multiplicar
        echo "$valor x $i = $((valor * i))" # Se imprime la tabla de multiplicar
    done
fi