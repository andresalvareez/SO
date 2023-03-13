#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    pid_t childpid, waitreturn;
    int status;
    if ((childpid = fork()) == -1)
    {
        fprintf(stderr, "Error en fork %d\n", errno);
        exit(1);
    }
    else if (childpid == 0)
    { /* codigo del proceso hijo */
        if (execl("/bin/ps", "ps", "-fu", getenv("USER"), 0) < 0)
        {
            fprintf(stderr, "Error en exec %d\n", errno);
            exit(1);
        }
    }
    else /* codigo del proceso padre */
        while (childpid != (waitreturn = wait(&status)))
            if ((waitreturn == -1) && (errno != EINTR))
                break;
    exit(0);
}

/* Aquí está la explicación para el código de arriba:

1. El proceso padre llama a fork para crear un proceso hijo. Los procesos padre e hijo ahora se ejecutan en paralelo. 
    El proceso hijo es una copia del proceso padre, excepto por algunas condiciones.
2. El proceso padre llama a wait para esperar a que el hijo salga (o para recibir una señal). 
    El proceso padre se suspende hasta que el hijo salga o se reciba una señal.
3. El proceso hijo llama a exec para ejecutar el comando ps. El proceso hijo es reemplazado por el comando ps.
4. El proceso padre reanuda la ejecución después de la llamada wait.
5. El proceso padre sale.*/