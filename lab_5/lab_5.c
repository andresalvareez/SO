#include <stdio.h>
#include <stdlib.h> // Librería para números aleatorios
#include <time.h>   // Librería para la semilla de números aleatorios
#include <string.h> // Librería para las funciones de cadenas

// Prototipos de las funciones
int cuadrada(int filas, int columnas, int flag0);
void crear_matriz(int filas, int columnas, int tam_matriz, int matriz[filas][columnas]);
void imprimir_matriz_entera(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_diagonal_principal(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_diagonal_secundaria(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_pares_matriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_impares_matriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_diagonal_superior(int filas, int columnas, int matriz[filas][columnas]);
void imprimir_diagonal_inferior(int filas, int columnas, int matriz[filas][columnas]);
void separador(int columnas);

int main()
{
    int flag0 = 0; // Flag para saber si la matriz es cuadrada o no
    int filas = 0, columnas = 0, tam_matriz = 0;

    // Pedimos al usuario el tamaño de la matriz
    printf("Dame las filas de la matriz: \n");
    scanf("%d", &filas);
    printf("Dame las columnas de la matriz: \n");
    scanf("%d", &columnas);

    int matriz[filas][columnas]; // Declaramos la matriz con su tamaño

    flag0 = cuadrada(filas, columnas, flag0); // Llamamos a la función cuadrada
    // printf("\n\n%d\n\n",flag0); --> Para comprobar que el flag funciona

    printf("Hasta que tamaño quieres que vayan los valores de la matriz: \n");
    scanf("%d", &tam_matriz);
    separador(columnas); // Llamamos a la función separador

    crear_matriz(filas, columnas, tam_matriz, matriz); // Llamamos a la función crear_matriz
    imprimir_matriz_entera(filas, columnas, matriz);   // Llamamos a la función imprimir_matriz_entera

    if (flag0 == 1)
    {
        imprimir_diagonal_principal(filas, columnas, matriz);  // Llamamos a la función imprimir_diagonal_principal
        imprimir_diagonal_secundaria(filas, columnas, matriz); // Llamamos a la función imprimir_diagonal_secundaria
        imprimir_pares_matriz(filas, columnas, matriz);        // Llamamos a la función imprimir_pares_matriz
        imprimir_impares_matriz(filas, columnas, matriz);      // Llamamos a la función imprimir_impares_matriz
        imprimir_diagonal_superior(filas, columnas, matriz);   // Llamamos a la función imprimir_digonal_superior
        imprimir_diagonal_inferior(filas, columnas, matriz);   // Llamamos a la función imprimir_diagonal_inferior
    }
    else if (flag0 == 0)
    {
        printf("\nComo la matriz no es cuadrada no se pueden imprimir los valores correspondientes a la diagonal principal, diagonal secundaria, diagonal superior e inferior\n");
        separador(columnas);                              // Llamamos a la función separador
        imprimir_pares_matriz(filas, columnas, matriz);   // Llamamos a la función imprimir_pares_matriz
        imprimir_impares_matriz(filas, columnas, matriz); // Llamamos a la función imprimir_impares_matriz
    }
}

int cuadrada(int filas, int columnas, int flag0)
{
    // Con este if comprobamos si la matriz es cuadrada o no
    if (filas == columnas)
    {
        printf("\nHas elegido una matriz de %d x %d \n", filas, columnas);
        printf("\nLa matriz es cuadrada\n");
        flag0 = 1; // Si la matriz es cuadrada el cambiamos el valor del flag
    }
    else
    {
        printf("\nHas elegido una matriz de %d x %d \n", filas, columnas);
        printf("\nLa matriz no es cuadrada\n");
        flag0 = 0; // Si la matriz no es cuadrada el cambiamos el valor del flag
    }
    return flag0; // Devolvemos el valor del flag
}

void crear_matriz(int filas, int columnas, int tam_matriz, int matriz[filas][columnas])
{
    int i, j;                   // Variables para los ciclos for
    time_t t1;                  // Variable para la semilla de números aleatorios
    srand((unsigned)time(&t1)); // Inicializamos la semilla

    // Recorremos la matriz
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Ahora asignamos un valor aleatorio a cada dato de la matriz
            matriz[i][j] = rand() % tam_matriz;
        }
    }
}

void imprimir_matriz_entera(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j;              // Variables para los ciclos for
    int filas_aux = filas; // Variable auxiliar para las filas **prueva**

    // Imprimimos la matriz con ciclos for
    printf("\nLa matriz es: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Con estos if's hacemos que los números se vean con 3 dígitos
            if (matriz[i][j] >= 10)
            {
                printf("%d ", matriz[i][j]);
            }
            else
            {
                printf("0%d ", matriz[i][j]);
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_diagonal_principal(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLa matriz diagonal principal es: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este if es para la diagonal principal
            if (i == j)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else 
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_diagonal_secundaria(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLa matriz diagonal secundaria es: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este es el if para la diagonal secundaria
            if (i + j == columnas - 1)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_pares_matriz(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLos pares de la matriz son: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este if es para imprimir los pares
            if (matriz[i][j] % 2 == 0)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_impares_matriz(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLos impares de la matriz son: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este if es para imprimir los impares
            if (matriz[i][j] % 2 != 0)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_diagonal_superior(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLa matriz diagonal superior es: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este if es la condicion para imprimir la diagonal superior
            if (i < j || i == j)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else 
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void imprimir_diagonal_inferior(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j; // Variables para los ciclos for
    // Imprimimos la matriz con ciclos for
    printf("\nLa matriz diagonal inferior es: \n");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            // Este if es la condicion para imprimir la diagonal inferior
            if (i > j || i == j)
            {
                // Con estos if's hacemos que los números se vean con 3 dígitos
                if (matriz[i][j] >= 10)
                {
                    printf("%d ", matriz[i][j]);
                }
                else
                {
                    printf("0%d ", matriz[i][j]);
                }
            }
            else
            {
                printf("   "); // Con este printf hacemos que se vea como una matriz
            }
        }
        // Con este printf hacemos que se vea como una matriz
        printf("\n");
    }
    separador(columnas); // Llamamos a la función separador
}

void separador(int columnas)
{
    for (int i = 0; i < columnas; i++)
    {
        printf("≈≈≈");
    }
}
