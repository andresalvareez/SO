#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("Soy example_01.4.C\n");
    printf("Mi PID es %d\n", getpid());
    return 0;
}

/* Aquí está la explicación para el código de arriba:

1. Primero, tenemos que incluir las bibliotecas que vamos a utilizar en nuestro programa. En este caso, 
    vamos a utilizar la biblioteca estándar de entrada/salida, la biblioteca unistd y la biblioteca estándar.
2. Luego, definimos la función principal (main), que es la primera función que se ejecuta cuando se ejecuta el programa.
3. En la función principal (main), utilizamos la función printf para imprimir el texto "Soy example_01.4.C" y "Mi PID es %d", que contiene un %d, 
    que es un carácter especial que será reemplazado por el valor de la función getpid(), que es el identificador de proceso del proceso actual.
4. Finalmente, devolvemos 0, que es el valor que devuelve la función principal (main) cuando se ejecuta correctamente el programa.*/