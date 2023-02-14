#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 14 *******************************************"
echo "****************************************************************************************"

# Comprobamos si el dato ingresado es un número
while true; do
    echo -n "Dame un número: "
    read -r num
    if [[ "$num" =~ ^[0-9]+$ ]]; then
        # Si el dato ingresado es un número, salimos del bucle
        break
    else
        # Si el dato ingresado no es un número, se imprime un mensaje de error y se vuelve a preguntar
        echo "Lo siento, el dato ingresado no es un número. Por favor, ingrese un número válido."
    fi
done

sum=0
for ((i = num; i >= 0; i--)); do # Se crea un bucle for que va desde el numero ingresado hasta 0
    sum=$((sum + i))             # Se va sumando el numero ingresado con los numeros menores a el
done
echo "Las suma de $num y los números menores a $num es $sum."

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
