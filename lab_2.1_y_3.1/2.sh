#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 02 *******************************************"
echo "****************************************************************************************"

echo -n "Dame un numero: "
read -r num1
echo -n "Dame otro numero: "
read -r num2
# Comprobamos si los numeros son iguales
if [ $num1 -eq $num2 ]; then
    echo "Los numeros son iguales"
else
    echo "Los numeros son diferentes"
fi

# Comprombamos si num1 es mayor que num2
if [ $num1 -gt $num2 ]; then
    echo "$num1 es mayor que $num2"
else
    echo "$num1 es menor que $num2"
fi

# Comprabamos si num1 es mayor o igual que num2
if [ $num1 -ge $num2 ]; then
    echo "$num1 es mayor o igual que $num2"
else
    echo "$num1 es menor o igual que $num2"
fi

# Comprabamos si num1 es menor que num2
if [ $num1 -lt $num2 ]; then
    echo "$num1 es menor que $num2"
else
    echo "$num1 es mayor que $num2"
fi

# Comprabamos si num1 es menor o igual que num2
if [ $num1 -le $num2 ]; then
    echo "$num1 es menor o igual que $num2"
else
    echo "$num1 es mayor o igual que $num2"
fi

# Comprabamos si num1 es diferente que num2
if [ $num1 -ne $num2 ]; then
    echo "$num1 es diferente que $num2"
else
    echo "$num1 es igual que $num2"
fi

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla