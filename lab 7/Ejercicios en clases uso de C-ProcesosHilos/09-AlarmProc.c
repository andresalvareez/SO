#include <signal.h>
#include <sys/time.h>
#include <stdio.h>

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
	printf ("==> Se�al recibida \n");
}
