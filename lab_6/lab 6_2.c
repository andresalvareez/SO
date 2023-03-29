#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    printf("PADRE: Soy el proceso Padre: mi (PID) es %d\n", (int)getpid());
    int pid = fork();
    if (pid == 0)
    {
        printf("HIJO: después de fork()\n");
        printf("HIJO: soy el proceso Hijo, mi (PID) es %d\n", (int)getpid());
    }
    else
    {
        printf("PADRE: después de fork()\n");
        printf("PADRE: el (PID) del Padre sigue siendo %d - fork() retorna %d\n", (int)getpid(), pid);
    }
    return 0;
}

// Explicacion del profesor:
/* Este programa demuestra el uso de la función getpid().
1. Cuando se ejecutó 100 veces en la computadora del autor, sólo dos veces se ejecutó el proceso padre antes de que se
    ejecutara el proceso hijo.
2. Tenga en cuenta que si se yuxtaponen dos cadenas de texto, el compilador las concatenará automáticamente, por ejemplo,
    "¡Hola " "mundo!" se convertirá en "¡Hola mundo!".
3. El valor de retorno de fork() es en realidad de tipo pid_t ('pid' 't'ipo). Cuando se asigna a 'int pid', si los tipos son
    diferentes, hay una conversión implícita; sin embargo, cuando se imprime el valor de retorno de getpid(), es necesario
    convertirlo explícitamente a un entero.
4. El tipo 'pid_t' está definido en la biblioteca <sys/types.h> */

// Explicacion mia:
/* Aquí está la explicación para el código de arriba:
1. Incluimos las bibliotecas necesarias.
2. Creamos la función principal main().
3. Usamos printf() para mostrar un mensaje.
4. Usamos la función getpid() para obtener el ID de proceso del proceso actual.
5. Usamos la función fork() para crear un nuevo proceso hijo.
6. Usamos una instrucción if-else para verificar el valor de retorno de la función fork().
    Si el valor de retorno es 0, significa que el proceso actual es el proceso hijo.
    Si el valor de retorno es un valor positivo, significa que el proceso actual es el proceso padre.
7. Usamos printf() para mostrar un mensaje.
8. Usamos getpid() para obtener el ID de proceso del proceso actual.
9. Devolvemos 0. */