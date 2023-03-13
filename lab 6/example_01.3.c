#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("Soy example_01.3.C, mi PID es %d\n", getpid());
    char *args[] = {"example_01.4", "C", "Programming", NULL};
    execv("./example_01.4", args);
    printf("Volviendo a example_01.3.C \n");
    return 0;
}
/* Aquí está la explicación para el código de arriba:
1. El programa recibe tres parámetros: el nombre del programa, el nombre del estudiante y el curso.
2. El programa imprime el nombre del programa, su identificador de proceso (PID) y los parámetros recibidos.
3. El programa llama a la función execv() para ejecutar el programa example_01.4.C.
4. El programa imprime el mensaje "Volviendo a example_01.3.C".
5. El programa termina.*/