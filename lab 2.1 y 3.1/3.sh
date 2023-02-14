#!/bin/bash

echo "****************************************************************************************"
echo "********************************* EJEMPLO 03 *******************************************"
echo "****************************************************************************************"

# -d verifica si el path dado es un directorio
# -f verifica si el path dado es un archivo
# -L verifica si el path dado en un link simbólico
# -e verifica si el fichero existe
# -s verifica si el fichero tiene un tamaño mayor a 0
# -r verifica si el fichero tiene permiso de lectura
# -w verifica si el fichero tiene permiso de escritura
# -x verifica si el fichero tiene permiso de ejecución

# Este script pide al usuario un path y verifica si el path dado es un directorio, un archivo, un link simbólico, 
#si existe, si tiene un tamaño mayor a 0, si tiene permiso de lectura, si tiene permiso de escritura y si tiene permiso de ejecución
echo -n "Deme la direccion de una carpeta o de un archivo : "
# Guardamos el path en la variable "dir"
read -r dir

# Si el path es un directorio, imprimirá un mensaje
if [ -d "$dir" ]; then
    echo "El path dado es un directorio"

# Si el path es un archivo, imprimirá un mensaje
elif [ -f "$dir" ]; then
    echo "El path dado es un archivo"

# Si el path es un link simbolico, imprimirá un mensaje
elif [ -L "$dir" ]; then
    echo "El path dado es un link simbolico"

# Si el path existe, imprimirá un mensaje
elif [ -e "$dir" ]; then
    echo "El path dado existe"

# Si el path tiene un tamaño mayor a 0, imprimirá un mensaje
elif [ -s "$dir" ]; then
    echo "El path dado tiene un tamaño mayor a 0"

# Si el path tiene un permiso de lectura, imprimirá un mensaje
elif [ -r "$dir" ]; then
    echo "El path dado tiene permiso de lectura"

# Si el path tiene un permiso de escritura, imprimirá un mensaje
elif [ -w "$dir" ]; then
    echo "El path dado tiene permiso de escritura"

# Si el path tiene un permiso de ejecución, imprimirá un mensaje
elif [ -x "$dir" ]; then
    echo "El path dado tiene permiso de ejecución"

# Si el path no es un directorio ni un archivo, imprimirá un mensaje
else
    echo "El path dado no es un directorio ni un archivo"
fi

sleep 6 # Se espera 6 segundos para que el usuario pueda leer el resultado
clear   # Se limpia la pantalla