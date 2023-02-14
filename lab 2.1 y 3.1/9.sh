#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 09 *******************************************"
echo "****************************************************************************************"

# For loop

# Función para validar si el dato ingresado es solo letras
function validar() {
    if [[ $1 =~ ^[a-zA-Z]+$ ]]; then
        return 0 # Devuelve 0 si el dato es válido
    else
        return 1 # Devuelve 1 si el dato no es válido
    fi
}

# Mensajes para el usuario
echo -n "Ingrese su nombre: "
read -r nombre

# Se valida el nombre ingresado
while ! validar "$nombre"; do
    echo -n "El nombre solo puede estar formado por letras, ingrese su nombre de nuevo: "
    read -r nombre
done

echo -n "Ingrese su primer apellido: "
read -r apellido1

# Se valida el primer apellido ingresado
while ! validar "$apellido1"; do
    echo -n "El apellido solo puede estar formado por letras, ingrese su primer apellido de nuevo: "
    read -r apellido1
done

echo -n "Ingrese su segundo apellido: "
read -r apellido2

# Se valida el segundo apellido ingresado
while ! validar "$apellido2"; do
    echo -n "El apellido solo puede estar formado por letras, ingrese su segundo apellido de nuevo: "
    read -r apellido2
done

# Creamos una lista con el nombre y los apellidos
lista="$nombre $apellido1 $apellido2"

echo -n "Su nombre es:"
# Muestra el nombre y los apellidos del usuario
for x in $lista; do
    echo -n " $x"
    sleep 0.5 # Espera 0.5 segundos
done

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla