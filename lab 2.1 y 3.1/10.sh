#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 10 *******************************************"
echo "****************************************************************************************"

# For loop

for x in "papel\ A4" "lapiz\ STADTLER" "boli\ BIC"; do # Se pueden usar espacios pero hay que separarlos con \
    echo "El valor de la variable x es: $x"
done

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla