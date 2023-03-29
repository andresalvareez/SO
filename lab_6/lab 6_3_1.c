#include <sys/types.h>
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

// Explicación mia:
/* Aquí está la explicación del código:

1. El proceso principal crea tres procesos hijos, cada uno con un tiempo de espera aleatorio. 
    Por lo tanto, el proceso principal es el padre de los tres procesos hijos. 
    Los procesos hijos tendrán tiempos de espera aleatorios y el proceso padre esperará a que sus hijos terminen. 
    El proceso padre esperará a que cada uno de sus hijos termine e imprimirá el mensaje "Fin del proceso de PID %d.\n" tres veces. 
    Los procesos hijos imprimirán el mensaje "Soy el proceso de PID %d y mi padre es %d (PPID).\n" tres veces. 
    Los procesos hijos dormirán durante tiempos aleatorios y luego terminarán. 
    El proceso principal esperará a que los tres procesos hijos terminen y imprimirá el mensaje "Fin del proceso de PID %d.\n" tres veces.*/