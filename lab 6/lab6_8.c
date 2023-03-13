#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd[2];
    pid_t childpid;
    pipe(fd);
    //printf("pipe: %d\n", pipe(fd)); // Estos comentario es para hacer pruevas
    if ((childpid = fork()) == 0)
    { /* ls es el hijo */
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        //printf("Mi (PID) es %d ", childpid); // Estos comentario es para hacer pruevas
        execl("/usr/bin/ls", "ls", "-l", NULL);
        perror("Exec fallo en ls");
    }
    else
    { /* sort es el padre */
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/sort", "sort", "-n", "+4", NULL);
        perror("Exec fallo en sort");
    }
    exit(0);
}
/* Aquí está la explicación para el código de arriba:

1. La llamada al sistema pipe() se utiliza para crear una tubería. Toma un solo argumento, que es una matriz de dos enteros. 
    La llamada al sistema pipe() crea una nueva tubería, un canal de datos unidireccional que se puede utilizar para la comunicación 
    entre procesos. La matriz pipefd se utiliza para devolver dos descriptores de archivo que se refieren a los extremos de la tubería. 
    pipefd[0] se refiere al extremo de lectura de la tubería. pipefd[1] se refiere al extremo de escritura de la tubería. 
    Los datos escritos en el extremo de escritura de la tubería se almacenan en búfer por el kernel hasta que se leen desde el extremo 
    de lectura de la tubería. Para obtener más información, consulte pipe(7).
2. La llamada al sistema fork() se utiliza para crear un nuevo proceso. El nuevo proceso creado será una copia del proceso padre. 
    El nuevo proceso se llama proceso hijo mientras que el proceso padre se llama proceso padre. La llamada al sistema fork() 
    devuelve el ID de proceso del proceso hijo al proceso padre y devuelve 0 al proceso hijo.
3. La llamada al sistema dup2() se utiliza para duplicar un descriptor de archivo. Toma dos argumentos; 
    el descriptor de archivo antiguo y el descriptor de archivo nuevo. La llamada al sistema dup2() cierra el descriptor de archivo nuevo 
    si ya está abierto. La llamada al sistema dup2() devuelve el descriptor de archivo nuevo en caso de éxito o -1 en caso de error. 
    Para obtener más información, consulte dup2(2).
4. La llamada al sistema execl() se utiliza para ejecutar un archivo. Toma al menos dos argumentos; la ruta del 
    archivo que se va a ejecutar y el primer argumento que se pasa al archivo que se está ejecutando. La llamada al sistema execl() 
    devuelve -1 en caso de error. Para obtener más información, consulte execl(3).
5. La llamada al sistema close() se utiliza para cerrar un descriptor de archivo. Toma un solo argumento, que es el 
    descriptor de archivo que se va a cerrar. La llamada al sistema close() devuelve 0 en caso de éxito o -1 en caso de error. 
    Para obtener más información, consulte close(2).
6. La función perror() se utiliza para imprimir un mensaje de error descriptivo en stderr, basado en el valor de errno. 
    Toma un solo argumento, que es la cadena que se imprimirá antes del mensaje de error. Para obtener más información, consulte perror(3).
7. La llamada al sistema exit() se utiliza para terminar el proceso que llama. Toma un solo argumento, que es el estado de 
    salida del proceso. La llamada al sistema exit() devuelve el estado de salida al proceso padre. Para obtener más información, 
    consulte exit(3). */