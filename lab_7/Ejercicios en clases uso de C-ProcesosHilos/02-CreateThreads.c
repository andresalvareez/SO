/*
 * 2 - Programa de ejemplo de threads.
 *
 * Un �nico contador y dos threads para modificarlo. Uno lo incrementa y pone
 * su valor en pantalla precedido de la palabra "Padre". El otro lo 
 * decrementa y ponse su valor en pantalla precedido de la palabra "Hilo".
 * Vemos en pantalla como el contador se incrementa y se decrementa 
 * r�pidamente.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* Prototipo de la funci�n que va a ejecutar el thread hijo */
void *funcionThread (void *parametro);

/* Contador global para que sea visible desde el main y desde la funci�n funcionThread */
int contador = 0;

/*
 * Lanza un thread para la funci�n funcionThread. Despu�s de comprobar el posible error, se mete en un bucle infinito 
 *incrementando y mostrando el contador.
 */
main() {
	/* Identificador del thread hijo */
	pthread_t idHilo;

	/* error devuelto por la funci�n de creaci�n del thread */
	int error;

	/* Se crea el thread.
	 * En idHilo se devuelve un identificador para el nuevo thread,
	 * Se pasa atributos del nuevo thread NULL para que los coja por defecto
	 * Se pasa la funci�n que se ejecutar� en el nuevo hilo
	 * Se pasa NULL como par�metro para esa funci�n. */
	error = pthread_create (&idHilo, NULL, funcionThread, NULL);

	/* Comprobamos el error al arrancar el thread */
	if (error != 0)
	{
		perror ("No es posible crear el thread");
		exit (-1);
	}

	/* Bucle infinito para incrementar el contador y mostrarlo en pantalla */
	while (1)
	{
		contador++;
		printf ("Padre : %d\n", contador);
	}
}

/* Funcion que se ejecuta en el thread hijo.*/
void *funcionThread (void *parametro) {
   /* Bucle infinito para decrementar contador y mostrarlo en pantalla. */
	while (1)
	{
		contador--;
		printf ("==> Hilo  : %d\n", contador);
	}
}

/*Aquí está la explicación para el código de arriba:

La función pthread_create() se utiliza para crear un nuevo hilo. Toma los siguientes argumentos:
• pthread_t *thread: es un puntero a una variable pthread_t que se establece por esta función con el valor de ID para el nuevo hilo.
• const pthread_attr_t *attr: es un puntero a una estructura pthread_attr_t cuyo contenido se utiliza en el momento de la creación del hilo para determinar los atributos del nuevo hilo; este argumento es opcional y debe ser NULL si no se requieren atributos de hilo.
• void *(*start_routine) (void *): es el nombre de la función que se ejecutará en el nuevo hilo y debe tener un argumento de puntero void y devolver un puntero void.
• void *arg: es un puntero a un argumento que se pasa a start_routine; se puede utilizar para pasar parámetros al nuevo hilo.
En el programa anterior, se han creado dos hilos. Un hilo ejecuta la función main() y el otro hilo ejecuta la función funcionThread(). La función main() comienza con un bucle while que incrementa el valor de la variable global 'contador' e imprime su valor. La función funcionThread() también comienza con un bucle while que decrementa el valor de la variable global 'contador' e imprime su valor.
El programa se compila con el siguiente comando:
gcc -pthread -o test test.c
La salida del programa es:
Padre: 1
==> Hijo: 0
esto se repite indefinidamente.*/