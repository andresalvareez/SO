#!/bin/bash

echo "****************************************************************************************"
echo "********************************* ZODIACO **********************************************"
echo "****************************************************************************************"

#############################COMPROBACIONES#############################
dia() {
    # Comprueba si el dia es valido
    if [[ "$dia" =~ ^[0-9]+$ ]]; then                  # Comprueba si el dia es un numero
        if [ "$dia" -ge 1 ] && [ "$dia" -le 31 ]; then
            return 0                                   # Si es valido, sale del bucle
        else
            echo "Error: Dia de nacimiento invalido" # Si no es valido, muestra un mensaje de error y vuelve a preguntar
            return 1
        fi
    else
        echo "Error: Dato invalido" # Si no es un numero, muestra un mensaje de error y vuelve a preguntar
        return 1
    fi
}
mes() {
    # Comprobacion mes
    if [[ "$mes" =~ ^[0-9]+$ ]]; then                  # Comprueba si el mes es un numero
        if [ "$mes" -ge 1 ] && [ "$mes" -le 12 ]; then # Comprueba si el mes es valido
            return 0                                   # Si es valido, sale del bucle
        else
            echo "Error: Mes de nacimiento invalido" # Si no es valido, muestra un mensaje de error y vuelve a preguntar
            return 1
        fi
    else
        echo "Error: Dato invalido" # Si no es un numero, muestra un mensaje de error y vuelve a preguntar
        return 1
    fi
}
#############################BUCLES#############################
while true; do # Bucle para comprobar que el dia es valido
    # Pregunta el dia de nacimiento
    echo "Ingrese su dia de nacimiento"
    read -r dia
    dia "$dia"
    if [ $? -eq 0 ]; then # Si la función dia() retorna 0, significa que el contenido es válido
        break             # Salir del bucle while
    fi
done
while true; do # Bucle para comprobar que el mes es valido
    # Pregunta el mes de nacimiento
    echo "Ingrese su mes de nacimiento"
    read -r mes
    dia "$mes"
    if [ $? -eq 0 ]; then # Si la función mes() retorna 0, significa que el contenido es válido
        break             # Salir del bucle while
    fi
done
#############################IMPRIMIR#############################
if [ "$mes" -eq "03" ] && [ "$dia" -ge 21 ] || [ "$mes" -eq "04" ] && [ "$dia" -le 20 ]; then # Comprueba el signo zodiacal
    echo "Tu signo zodiacal es Aries"
elif [ "$mes" -eq "04" ] && [ "$dia" -ge 21 ] || [ "$mes" -eq "05" ] && [ "$dia" -le 21 ]; then
    echo "Tu signo zodiacal es Tauro"
elif [ "$mes" -eq "05" ] && [ "$dia" -ge 22 ] || [ "$mes" -eq "06" ] && [ "$dia" -le 21 ]; then
    echo "Tu signo zodiacal es Géminis"
elif [ "$mes" -eq "06" ] && [ "$dia" -ge 22 ] || [ "$mes" -eq "07" ] && [ "$dia" -le 22 ]; then
    echo "Tu signo zodiacal es Cáncer"
elif [ "$mes" -eq "07" ] && [ "$dia" -ge 23 ] || [ "$mes" -eq "08" ] && [ "$dia" -le 23 ]; then
    echo "Tu signo zodiacal es Leo"
elif [ "$mes" -eq "08" ] && [ "$dia" -ge 24 ] || [ "$mes" -eq "09" ] && [ "$dia" -le 23 ]; then
    echo "Tu signo zodiacal es Virgo"
elif [ "$mes" -eq "09" ] && [ "$dia" -ge 24 ] || [ "$mes" -eq "10" ] && [ "$dia" -le 23 ]; then
    echo "Tu signo zodiacal es Libra"
elif [ "$mes" -eq "10" ] && [ "$dia" -ge 24 ] || [ "$mes" -eq "11" ] && [ "$dia" -le 22 ]; then
    echo "Tu signo zodiacal es Escorpio"
elif [ "$mes" -eq "11" ] && [ "$dia" -ge 23 ] || [ "$mes" -eq "12" ] && [ "$dia" -le 21 ]; then
    echo "Tu signo zodiacal es Sagitario"
elif [ "$mes" -eq "12" ] && [ "$dia" -ge 22 ] || [ "$mes" -eq "01" ] && [ "$dia" -le 20 ]; then
    echo "Tu signo zodiacal es Capricornio"
elif [ "$mes" -eq "01" ] && [ "$dia" -ge 21 ] || [ "$mes" -eq "02" ] && [ "$dia" -le 19 ]; then
    echo "Tu signo zodiacal es Acuario"
elif [ "$mes" -eq "02" ] && [ "$dia" -ge 20 ] || [ "$mes" -eq "03" ] && [ "$dia" -le 20 ]; then
    echo "Tu signo zodiacal es Piscis"
fi