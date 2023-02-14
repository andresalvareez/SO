#!/bin/bash

echo "****************************************************************************************"
echo "********************************* GENERATEFILE *****************************************"
echo "****************************************************************************************"

# El nombre del fichero debe tener entre 6 y 20 caracteres.
# El tamaño del fichero debe estar entre 1Mb y 20Mb.
# El tipo de contenido solo puede ser "vacío" y "texto".
#############################COMPROBACIONES#############################
comprobar_nombre() {
    if [[ "$nombre" =~ ^[a-zA-Z0-9]{6,20}$ ]]; then # If para comprobar que el nombre del fichero es correcto
        return 0                                    
    elif [ -f "$nombre" ]; then                     # If para comprobar si el fichero ya existe
        echo "El fichero ya existe, ingrese otro nombre."
        return 1
    else
        echo "Lo siento, el dato ingresado no es valido. Por favor, ingrese un dato válido."
        return 1
    fi
}
comprobar_tamano() {
    if [[ "$tamano" =~ ^[0-9]+$ ]] && [ "$tamano" -ge 1 ] && [ "$tamano" -le 20 ]; then # If para comprobar que el dato es correcto
        return 0
    else
        echo "Lo siento, el dato ingresado no es valido. Por favor, ingrese un número válido."
        return 1
    fi
}
comprobar_contenido() {
    if [[ "$1" =~ ^(V|v|T|t)$ ]]; then # If para comprobar que el tipo de contenido es correcto
        return 0                      
    else
        echo "Lo siento, el dato ingresado no es valido. Por favor, ingrese un dato válido."
        return 1
    fi
}
#############################BUCLES#############################
while true; do
    echo -n "Introduzca el nombre del fichero(6-20 caracteres): "
    read -r nombre
    comprobar_nombre "$nombre"
    if [ $? -eq 0 ]; then # Si la función comprovar_nombre() retorna 0, significa que el contenido es válido
        break             # Salir del bucle while
    fi
done
while true; do
    echo -n "Introduzca el tamaño del fichero(1-20 Mb): "
    read -r tamano
    comprobar_tamano "$tamano"
    if [ $? -eq 0 ]; then # Si la función comprovar_tamano() retorna 0, significa que el contenido es válido
        break             # Salir del bucle while
    fi
done
while true; do
    echo -n "Introduzca el tipo de contenido V(vacio) o T(texto): "
    read -r contenido
    comprobar_contenido "$contenido"
    if [ $? -eq 0 ]; then # Si la función comprovar_contenido() retorna 0, significa que el contenido es válido
        break             # Salir del bucle while
    fi
done
#############################IMPRIMIR#############################
if [[ "$contenido" =~ ^(V|v)$ ]]; then                     # If para comprobar que tipo de contenido se quiere
    touch "$nombre"                                        # Se crea el fichero con el nombre indicado
    dd if=/dev/zero of="$nombre" bs=1M count="$tamano"     # Se crea el fichero con el tamaño indicado
elif [[ "$contenido" =~ ^(T|t)$ ]]; then                   # If para comprobar que tipo de contenido se quiere
    touch "$nombre.txt"                                    # Se crea el fichero con el nombre indicado
    dd if=/dev/zero of="$nombre.txt" bs=1M count="$tamano" # Se crea el fichero con el tamaño indicado
fi