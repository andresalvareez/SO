#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    pid_t childpid;
    int status = 0;
    int result;
    if ((childpid = fork()) == -1)
    {
        perror("Error en llamada a fork\n");
        exit(1);
    }
    else if (childpid == 0)
    {
        result = getpid() < getppid();
        fprintf(stdout, "Soy el proceso hijo (%ld) y voy a devolver a mi padre(%ld) el valor %d después de esperar 2 segundos\n", (long)getpid(), (long)getppid(), result);
        sleep(2);
        exit(result);
    }
    else
    {
        while (childpid != wait(&status))
            ;
        fprintf(stdout, "Soy el proceso padre (%ld) y mi hijo (%ld) me ha devuelto %d\n", (long)getpid(), (long)childpid, status);
    }
    return (0);
}

/* Aquí está la explicación del código:

1. El proceso padre llama a fork() para crear un nuevo proceso, que es una copia del padre. 
    El proceso hijo tiene su propia copia de los datos del padre, incluyendo el contador de programa (PC) y el puntero de pila (SP).
    El proceso hijo es igual que el padre, excepto que tiene un ID de proceso (PID) diferente. 
    El proceso hijo puede utilizarse para realizar una tarea en paralelo con su padre. 
    Los procesos padre e hijo continuarán ejecutándose de forma independiente a partir de este punto.
2. El proceso padre llama a wait() para esperar a que el proceso hijo termine. 
    El proceso padre se pone en espera hasta que el proceso hijo termine.
3. El proceso hijo llama a getpid() para obtener su propio PID y a getppid() para obtener el PID de su padre. 
    El proceso hijo luego comprueba si su PID es menor que el PID de su padre. 
    El proceso hijo imprime el resultado y sale con el resultado como estado de salida. 
    El estado de salida es un valor entre 0 y 255, pero se almacena en un entero. 
    Como el estado de salida es un entero, el resultado debe convertirse en un entero.
4. El proceso padre se despierta y llama a wait() de nuevo. Esta vez, wait() devuelve el PID del proceso hijo, 
    que se almacena en la variable childpid. El proceso padre luego llama a wait() de nuevo para obtener el estado de salida del hijo. 
    El estado de salida es el mismo valor que el proceso hijo pasó a la función exit(). 
    El proceso padre luego imprime el PID del proceso hijo y el estado de salida. El proceso padre luego sale.
5. El proceso hijo termina y el proceso padre imprime el PID del hijo y el estado de salida.
    La salida de este programa se muestra a continuación. 
    La salida variará porque el PID del proceso padre siempre es mayor que el PID del proceso hijo. 
    La salida del programa será diferente si lo ejecuta de nuevo. 
    La salida del programa será diferente si lo ejecuta en un ordenador diferente.
    Soy el proceso hijo (28055) y voy a devolver a mi padre(28054) el valor 0 después de esperar 2 segundos 
    Soy el proceso padre (28054) y mi hijo (28055) me ha devuelto 0 */