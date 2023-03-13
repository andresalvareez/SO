#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Funci�n para tratamiento de la se�al SIGALRM */
void procesaSenial (int);

/* Pone un contador de tiempo que salta la primera vez a los dos segundos y luego cada medio segundo. */
main() {	
	
	/* Estructura con el contador de tiempo */
	struct itimerval contador;

	/* Valor inicial del contador */
	struct timeval tiempoInicial;

	/* Tiempo de repetici�n del contador */
	struct timeval tiempoRepeticion;

	/* Se rellena el tiempo inicial del contador con 2 segundos */
	tiempoInicial.tv_sec=2;
	tiempoInicial.tv_usec=0;

	/* Se rellena el tiempo de repetici�n con medio segundo */
	tiempoRepeticion.tv_sec=0;
	tiempoRepeticion.tv_usec=500000;

	/* Se rellenan los datos del contador */
	contador.it_value=tiempoInicial;
	contador.it_interval=tiempoRepeticion;
	
	/* Se cambia el tratamiento de la se�al por defecto para que llame a
	 * nuestra funci�n procesaSenial */
	signal (SIGALRM, procesaSenial);

	/* Se pone en marcha el contador.
	 * La primera vez tardar� 2 segundos en saltar, seg�n indicamos en
	 * tiempoInicial. Luego saltar� autom�ticamente cada medio segundo, como
	 * indicamos en tiempoRepeticion. */
	setitimer (ITIMER_REAL, &contador, NULL);

	/* Bucle infinito con pause(). */
	while(1)
		pause();
}

/* Tratamiento de la se�al SIGALRM. Escribe en pantalla que ha llegado la se�al */
void procesaSenial (int idSenhal) {
	printf ("==> Señal recibida \n");
}

/* Explicacion del codigo:
1.  Se incluye el fichero signal.h que contiene las definiciones de las funciones y constantes necesarias para el tratamiento de las señales.
2. Se incluye el fichero sys/time.h que contiene las definiciones de las funciones y constantes necesarias para el manejo de temporizadores.
3. Se declara la función que va a tratar la señal SIGALRM.
4. Se declara la estructura del temporizador.
5. Se declara la estructura de tiempo inicial.
6. Se declara la estructura de tiempo de repetición.
7. Se rellena la estructura de tiempo inicial con 2 segundos.
8. Se rellena la estructura de tiempo de repetición con medio segundo.
9. Se rellenan los datos del temporizador.
10. Se cambia el tratamiento de la señal por defecto para que llame a nuestra función procesaSenial.
11. Se pone en marcha el temporizador.
12. Se pone en marcha el bucle infinito con la función pause().
13. Tratamiento de la señal SIGALRM. Escribe en pantalla que ha llegado la señal. */
