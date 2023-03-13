/*
 * 1 - Programa de ejemplo de fork()
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Programa principal: crear un proceso hijo que escriba su id en pantalla, espere 5 segundos y finalice con un exit (33).
 * El proceso padre espera un segundo, escribe su id, el de su hijo y espera que el hijo termine. Escribe en pantalla el valor de exit del hijo.
 */
main()
{
	/* Identificador del proceso creado */
	pid_t idProceso;

	/* Variable para comprobar que se copia inicialmente en cada proceso y que luego puede cambiarse independientemente en cada uno de ellos. */
	int variable = 1;

	/* Estado del hijo */
	int estadoHijo;

	/* Se crea el proceso hijo. En algún sitio dentro del fork(), nuestro programa se duplica en dos procesos. Cada proceso obtendr� una salida distinta. */
	idProceso = fork();


	/* Si fork() devuelve -1, es que hay un error y no se ha podido crear el proceso hijo. */
	if (idProceso == -1)
	{
		perror("No es posible crear proceso");
		exit(-1);
	}

	/* fork() devuelve 0 al proceso hijo.*/
	if (idProceso == 0)
	{
		/* El hijo escribe su pid en pantalla y el valor de variable */
		printf("==> HiloHijo: Mi pid es %d. El PID de mi padre es %d\n", getpid(), getppid());

		/* Escribe valor de variable y la cambia */
		printf("==> HiloHijo: variable = %d. Modifico variable = 2\n", variable);
		variable = 2; 

		/* Espera 5 segundos, saca en pantalla el valor de variable y sale */
		sleep(5);
		printf("==> HiloHijo: variable = %d,\n FINALIZO \n", variable);
		exit(33);
	}

	/* fork() devuelve un n�mero positivo al padre. Este n�mero es el id del hijo. */
	if (idProceso > 0)
	{
		/* Espera un segundo (para dar tiempo al hijo a hacer sus cosas y no entremezclar salida en la pantalla) y escribe su pid y el de su hijo */
		sleep(1);
		printf("==> PPadre: Mi pid es %d. El pid de HiloHijo es %d\n", getpid(), idProceso);

		/* Espera que el hijo muera */
		wait(&estadoHijo);

		/* Comprueba la salida del hijo */
		if (WIFEXITED(estadoHijo) != 0)
		{
			printf("==> PPadre: HiloHijo ha finalizado. Devuelve %d\n", WEXITSTATUS(estadoHijo));
		}

		/* Escribe el valor de variable, que mantiene su valor original */
		printf("==> PPadre: variable = %d\n", variable);
	}
}

/* Aquí está la explicación para el código de arriba:

La función fork() crea un nuevo proceso, llamado proceso hijo, que se ejecuta concurrentemente con el proceso que hace la llamada a fork() (proceso padre). El proceso hijo es un duplicado del proceso padre. Devuelve 0 al proceso hijo y devuelve el ID de proceso del proceso hijo al proceso padre. Si el valor devuelto es negativo, entonces la creación de un nuevo proceso no tuvo éxito.

La función getpid() devuelve el ID de proceso del proceso que hace la llamada.

La función getppid() devuelve el ID de proceso del padre del proceso que hace la llamada.

La función wait() suspende la ejecución del proceso que hace la llamada hasta que uno de sus hijos termina. La llamada se permite devolver si un proceso hijo ya ha terminado. La llamada se permite devolver si un proceso hijo ya ha terminado. La función wait() devuelve el ID de proceso del proceso hijo terminado.

La función WIFEXITED() devuelve verdadero si el proceso hijo terminó de forma normal, es decir, llamando a exit(3) o _exit(2), o retornando desde main().

La función WEXITSTATUS() devuelve el estado de salida del proceso hijo. Esto consta de los 8 bits menos significativos del argumento de estado que el hijo especificó en una llamada a exit(3) o _exit(2) o como argumento para una instrucción return en main(). Esta macro solo debe usarse si WIFEXITED() devolvió verdadero. */