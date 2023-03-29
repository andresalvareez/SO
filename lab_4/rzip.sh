#!/bin/bash

echo "****************************************************************************************"
echo "********************************* RZIP *************************************************"
echo "****************************************************************************************"

#############################COMPROBACIONES#############################
comprobar_existe() {
    if [ -f "$archivo" ]; then
        return 0
    else
        echo "El archivo no existe, ingrese otro nombre."
        return 1
    fi
}

comprobar_compresion() {
    if [[ "$1" =~ ^(Z|z|T|t)$ ]]; then # If para comprobar que el tipo de contenido es correcto
        return 0                      
    else
        echo "Lo siento, el dato ingresado no es valido. Por favor, ingrese un dato válido."
        return 1
    fi
}
#############################BUCLES#############################
while true; do
    echo "Introduzca el nombre de un archivo: "
    read -r archivo
    archivo_sin_extension="${archivo%.*}" # Se guarda el nombre del archivo sin la extensión para que el nombre del archivo comprimido sea igual al del archivo original y no tenga dos extensiones
    comprobar_existe "$archivo"
    if [ $? -eq 0 ]; then 
        echo "Introduzca el tipo de compresión .Tar(T) .Zip(Z): "
        read -r tipo
        comprobar_compresion "$tipo"
        if [ $? -eq 0 ]; then # Si la función comprovar_contenido() retorna 0, significa que el contenido es válido
            break             # Salir del bucle while
        fi
    fi
done
#############################IMPRIMIR#############################
if [[ "$tipo" =~ ^(T|t)$ ]]; then
    echo "Comprimiendo con tar..."
    tar -cvf "$archivo_sin_extension".tar "$archivo" # Se crea el fichero comprimido del tipo indicado
    rm "$archivo"                                    # Se elimina el fichero original
#    touch "$archivo"                                # Se crea el fichero original par reiniciar la prueva
elif [[ "$tipo" =~ ^(Z|z)$ ]]; then
    echo "Comprimiendo con zip..."
    zip "$archivo_sin_extension".zip "$archivo" # Se crea el fichero comprimido del tipo indicado
    rm "$archivo"                               # Se elimina el fichero original
#    touch "$archivo"                           # Se crea el fichero original par reiniciar la prueva
fi