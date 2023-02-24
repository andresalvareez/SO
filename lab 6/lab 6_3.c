#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    int i;
    int padre;
    padre = 1;
    for (i = 0; i < 3; i++)
    {
        if (padre == 1)
        {
            if (fork() == 0) /* Proceso hijo */
            {
                fprintf(stdout, "Este es el proceso hijo con padre %ld\n",
                        (long)getppid());
                padre = 0;
            }
            else /* Proceso padre */
            {
                fprintf(stdout, "Este es el proceso padre con ID %ld\n", (long)getpid());
                padre = 1;
            }
        }
    }
    return 0;
}

// Explicacion mia:
/* Aquí está la explicación para el código de arriba:
1. La primera línea del código incluye la biblioteca de entrada/salida estándar que se necesita para la función fprintf.
2. La segunda línea del código incluye la biblioteca sys/types.h que se necesita para el tipo de datos pid_t.
3. La tercera línea del código incluye la biblioteca unistd.h necesaria para la función fork().
4. La cuarta línea del código define la función principal main().
5. La quinta línea del código define una variable entera i.
6. La sexta línea del código define una variable entera padre.
7. La séptima línea del código establece el valor de la variable padre en 1.
8. La octava línea del código inicia un bucle for que ejecutará las siguientes líneas de código 3 veces.
9. La novena línea del código comprueba si la variable padre tiene un valor de 1. Si es así, se ejecutarán las siguientes líneas de código.
10. La décima línea del código comprueba si la función fork() devuelve 0. Si lo hace, se ejecutarán las siguientes líneas de código.
11. La undécima línea del código imprime un mensaje en la pantalla con el ID de proceso del proceso padre utilizando la función fprintf.
12. La duodécima línea del código establece el valor de la variable padre en 0.
13. La decimotercera línea del código se ejecuta si la función fork() no devuelve 0. Si lo hace, se ejecutarán las siguientes líneas de código.
14. La decimocuarta línea del código imprime un mensaje en la pantalla con el ID de proceso del proceso padre utilizando la función fprintf.
15. La decimoquinta línea del código establece el valor de la variable padre en 1.
16. La decimosexta línea del código devuelve 0 a la función principal main(). */