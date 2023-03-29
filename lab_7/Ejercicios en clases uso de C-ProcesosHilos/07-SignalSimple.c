#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Controlador para la se�al de ctrl-c
 */
void controlaSignal (int);

/*
 * Cambia el controlador para la se�al de ctrl-c y se mete en un bucle infinito de espera
 */
main()
{
	/* Se cambia el controlador para ctrl-c, escribiendo error en pantalla si lo hay. */
	if (signal(SIGINT, controlaSignal) == SIG_ERR)
	{
		perror ("No es posible modificar Signal");
	}

	/* Bucle infinito de espera. pause() deja el proceso dormido hasta que llegue una se�al. */
	while (1)
		sleep(10);
		
}

/*
 * Controlador para ctrl-c. Indica en pantalla que no se quiere salir y pone el controlador por defecto para ctrl-c. La segunda vez que se pulse ctrl-c, el programa se saldr� normalmente.
 */
void controlaSignal (int numeroSenhal)
{
	printf("\n Estas seguro que quieres dejarme? \n");
	printf("\n Vuelve a intentarlo... \n");

	/* Se pone controlador por defecto para ctrl-c */
	signal(SIGINT, SIG_DFL);
}

/* Explicacion del codigo:
1. Se incluyen las librerias necesarias para el manejo de las señales.
2. Se define la funcion controlaSignal que recibe como parametro el numero de la señal.
3. Se define la funcion main que es la que se ejecuta al ejecutar el programa.
4. En la funcion main se cambia el controlador de la señal SIGINT para que al pulsar ctrl-c se ejecute la funcion controlaSignal. 
Si no se puede cambiar se imprime un mensaje de error en la salida de error.
5. Se crea un bucle infinito que se ejecuta cada 10 segundos.
6. En la funcion controlaSignal se imprime un mensaje en la salida estandar y se cambia el controlador de la señal SIGINT para que al pulsar ctrl-c se 
ejecute la funcion controlaSignal. Si no se puede cambiar se imprime un mensaje de error en la salida de error.

Si se ejecuta el programa y se pulsa ctrl-c se ejecutará la funcion controlaSignal y se imprimirá el mensaje en la salida estandar. 
Si se pulsa ctrl-c de nuevo se ejecutará la funcion controlaSignal y se imprimirá el mensaje en la salida estandar. Si se pulsa ctrl-c de nuevo se ejecutará la funcion controlaSignal y se ejecutará el controlador por defecto de la señal SIGINT que es salir del programa. */