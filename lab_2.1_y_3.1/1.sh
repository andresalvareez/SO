#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 01 *******************************************"
echo "****************************************************************************************"

#Comparadores
aux=0 # Variable auxiliar para el while(el comprovar si los numeros son numero o no)

while [ $aux -eq 0 ]; do
    aux=1
    # Pide dos numeros y los guarda en las variables num1 y num2
    echo -n "Ingrese un numero: "
    read -r num1
    # Comprueba si num1 es un numero
    if ! [[ $num1 =~ ^[0-9]+$ ]]; then
        echo "El numero ingresado no es valido" # Si no es un numero muestra un mensaje y sale del script
        aux=0
    fi
    echo -n "Ingrese otro numero: "
    read -r num2
    # Comprueba si num2 es un numero
    if ! [[ $num2 =~ ^[0-9]+$ ]]; then
        echo "El numero ingresado no es valido" # Si no es un numero muestra un mensaje y sale del script
        aux=0
    fi
    if [ $aux -eq 1 ]; then
        # Si son iguales muestra un mensaje
        if [[ $num1 = "$num2" ]]; then
            echo "Los numeros son iguales"
            aux=1
        # Si son diferentes muestra otro mensaje
        else
            echo "Los numeros son diferentes"
            aux=1
        fi
    fi
done

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla
