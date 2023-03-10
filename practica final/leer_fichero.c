#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_REGISTROS 100

// Estructura para almacenar cada registro del archivo
typedef struct
{
    char IdApuesta[50];
    char FECHA_INICIO[50];
    char FECHA_FIN[50];
    char IdUsuario[50];
    char IdSesionJuego[50];
    char Participacion[50];
    char Apuesta[50];
    char Estado[50];
} Registro;

// Funciones prototipadas
Registro *leerArchivo(char *filename, int *numRegistros);
void imprimirRegistros(Registro *registros, int numRegistros);

void logPrint(char *txt, char *var)
{
    FILE *logFile = fopen("print_log.txt", "a");
    if (logFile == NULL)
    {
        printf("Error al abrir el archivo de log\n");
        exit(1);
    }
    // Estos if son para que si no hay variable en el log solo se imprima el texto
    if (var != NULL && txt != NULL)
    {
        fprintf(logFile, "%s %s\n", txt, var);
        printf("%s %s\n", txt, var);
    }
    else if(var == NULL)
    {
        fprintf(logFile, "%s\n", txt);
        printf("%s\n", txt);
    }
    else if(txt == NULL)
    {
        fprintf(logFile, "%s\n", var);
        printf("%s\n", var);
    }
    else{
        printf("\n");
    }
    fclose(logFile);
}

//
int main()
{
    int numRegistros;
    Registro *registros = leerArchivo("ejemplotabla.txt", &numRegistros);
    imprimirRegistros(registros, numRegistros);
    free(registros);
    return 0;
}

// Función para leer el archivo y almacenar los registros en un array
Registro *leerArchivo(char *filename, int *numRegistros)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        logPrint("Error al abrir el archivo \n", filename);
        exit(1);
    }
    Registro *registros = malloc(sizeof(Registro) * MAX_REGISTROS);
    char line[MAX_LINE_SIZE];
    int i = 0;
    while (fgets(line, MAX_LINE_SIZE, file) != NULL)
    {
        char *token = strtok(line, ";");
        strcpy(registros[i].IdApuesta, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].FECHA_INICIO, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].FECHA_FIN, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].IdUsuario, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].IdSesionJuego, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].Participacion, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].Apuesta, token);
        token = strtok(NULL, ";");
        strcpy(registros[i].Estado, token);
        if (i < MAX_REGISTROS)
        {
            i++;
        }
        else
        {
            logPrint("Número máximo de registros alcanzado\n", NULL);
            break;
        }
    }
    *numRegistros = i;
    fclose(file);
    return registros;
}

// Funcion para imprimir los datos
void imprimirRegistros(Registro *registros, int numRegistros)
{
    for (int i = 0; i < numRegistros; i++)
    {
        logPrint("IdApuesta: \n", registros[i].IdApuesta);
        logPrint("FECHA_INICIO: \n", registros[i].FECHA_INICIO);
        logPrint("FECHA_FIN: \n", registros[i].FECHA_FIN);
        logPrint("IdUsuario: \n", registros[i].IdUsuario);
        logPrint("IdSesionJuego: \n", registros[i].IdSesionJuego);
        logPrint("Participacion: \n", registros[i].Participacion);
        logPrint("Apuesta(en €): \n", registros[i].Apuesta);
        logPrint("Estado(en €): \n", registros[i].Estado);
        logPrint("\n", NULL);
    }
}