#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void procesaSenial (int);


/* 
 * Crea un proceso hijo y le env�a una se�al SIGUSR1 cada segundo.
 */
main()
{
	/* Identificador del proceso hijo */
	pid_t idProceso;

	/* Se crea el proceso hijo y se comprueba el error */
	idProceso = fork();

	if (idProceso == -1)
	{
		perror ("No se puede lanzar proceso");
		exit (-1);
	}

	/* Camino que sigue el proceso hijo. Pone trataSenhal() para tratar la se�al SIGUSR1 y se mete en un bucle de espera */
	if (idProceso == 0)
	{
		signal (SIGUSR1, procesaSenial);
		while (1)
			pause ();
	}

	/* Camino que sigue el proceso padre. Cada segundo env�a una se�al SIGUSR1 a su proceso hijo. */
	if (idProceso > 0)
	{
		while (1)
		{
			sleep (1);
			printf ("PAPA: Envio una señal a mi hijo \n");
			kill (idProceso, SIGUSR1);
		}
	}
}

/* Funci�n de tratamiento de SIGUSR1. Escribe en pantalla un aviso de que ha llegado la se�al. */
void procesaSenial (int numeroSenhal)
{
	printf ("==> HIJO: he recibido la señal de Papa \n");
}

/* Explicacion del codigo:
1. El primer paso es crear un proceso hijo con fork().
2. El proceso hijo ejecuta una funcion que trata la senial del padre.
3. El proceso padre envia una senial al hijo cada segundo.
4. El proceso hijo trata la senial del padre y escribe un mensaje en pantalla.
5. Cuando el proceso padre termina, el hijo queda sin padre y lo coge el proceso init.
6. Cuando el proceso hijo termina, se le envia una senial al padre para que termine.
7. Cuando el proceso padre termina, se le envia una senial al hijo para que termine.
8. Cuando el proceso hijo termina, se le envia una senial al proceso init para que termine.
9. Cuando el proceso init termina, se le envia una senial a todos los procesos para que terminen.
10. Todos los procesos terminan. */