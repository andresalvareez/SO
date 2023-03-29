#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
int main()
{
    int status;
    printf("Soy el proceso Padre, mi (PID) es %d\n", (int)getpid());
    printf("Listar los procesos \n");
    if (execl("/bin/ps", "ps", "-f", NULL) < 0)
    {
        fprintf(stderr, "Error en exec %d\n", errno);
        exit(1);
    }
    printf("Fin de la lista de procesos\n");
    exit(0);
}
/* Aquí está la explicación del código de arriba:

1. La primera línea del código es el archivo de encabezado para el programa. El archivo de encabezado define las funciones y variables utilizadas en el programa.
2. La siguiente línea es la función principal. La función principal es el punto de partida del programa.
3. La siguiente línea es la declaración de la variable estado. La variable estado almacena el estado de la llamada al sistema.
4. La siguiente línea imprime el mensaje "Soy el proceso Padre, mi (PID) es %d\n".
5. La siguiente línea imprime el mensaje "Listar los procesos \n".
6. La siguiente línea ejecuta el comando ps -f.
7. La siguiente línea imprime el mensaje "Fin de la lista de procesos\n".
8. La siguiente línea sale del programa. */