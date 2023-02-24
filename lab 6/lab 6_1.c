#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int num;
    pid_t pid;
    srandom(getpid());
    for (num = 0; num < 3; num++)
    {
        pid = fork();
        printf("Soy el proceso de PID %d y mi padre es %d (PPID).\n", getpid(), getppid());
        if (pid == 0)
            break;
    }
    if (pid == 0)
        sleep(random() % 5);
    else
        for (num = 0; num < 3; num++)
            printf("Fin del proceso de PID %d.\n", wait(NULL));
    return 0;
}

// Explicacion mia:
/* Aquí está la explicación del código anterior:
1. Se utiliza un bucle For para crear 3 procesos hijos. Los procesos hijos se crean en un bucle porque
    el proceso padre tiene que esperar a que los 3 procesos hijos terminen antes de poder salir.
2. La instrucción if comprueba si el proceso actual es un proceso hijo o no. Si es un proceso hijo, duerme durante un período aleatorio.
    Si es un proceso padre, espera a que los procesos hijos terminen.
3. Se utiliza la función wait() para esperar a que los procesos hijos terminen.
    Devuelve el ID de proceso del proceso hijo que terminó primero. El bucle For se utiliza para esperar a que todos los procesos hijos terminen.
4. En los procesos hijos, se imprimen los valores PID y PPID.
    Los procesos padres imprimen el PID de los procesos hijos que han terminado. */