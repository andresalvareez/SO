#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_SIZE 1024
#define MAX_REGISTROS 100
#define LOG_FILE "print_log.txt"

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
void imprimirRegistros(Registro *registros, int cont);
void logPrint(char *txt, char *var);
double horasJugadas(char *fechaInicio, char *fechaFin);

int main()
{
    // Este 7 es porque la tabla temporal tiene 7 filas
    double horasjuego[7];
    int numRegistros;
    FILE *logFile = fopen(LOG_FILE, "a");
    time_t t = time(NULL);                      
    Registro *registros = leerArchivo("ejemplotabla.txt", &numRegistros);

    for (int i = 0; i < numRegistros; i++)
    {
        horasjuego[i] = horasJugadas(registros[i].FECHA_INICIO, registros[i].FECHA_FIN);
        char resultado[50];
        sprintf(resultado, "%.2f", horasjuego[i]);
        logPrint("Horas de juego:", resultado);
        imprimirRegistros(registros, i);
    }                               // Obtenemos la hora actual
    fprintf(logFile, "********************************************************\n**Nuevo log, la hora actual es: %s********************************************************\n", ctime(&t)); // Convertimos la hora en una cadena legible y la imprimimos
    free(registros);
    return 0;
}

// Función para leer el archivo y almacenar los registros en un array
Registro *leerArchivo(char *filename, int *numRegistros)
{
    FILE *logFile = fopen(LOG_FILE, "a");
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
void imprimirRegistros(Registro *registros, int cont)
{
    FILE *logFile = fopen(LOG_FILE, "a");
    logPrint("\nIdApuesta:", registros[cont].IdApuesta);
    logPrint(":::FECHA_INICIO:", registros[cont].FECHA_INICIO);
    logPrint(":::FECHA_FIN:", registros[cont].FECHA_FIN);
    logPrint(":::IdUsuario:", registros[cont].IdUsuario);
    logPrint(":::IdSesionJuego:", registros[cont].IdSesionJuego);
    logPrint(":::Participacion:", registros[cont].Participacion);
    logPrint(":::Apuesta(en €):", registros[cont].Apuesta);
    logPrint(":::Estado(en €):", registros[cont].Estado);
    logPrint("\n", NULL);
}

void logPrint(char *txt, char *var)
{
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL)
    {
        printf("Error al abrir el archivo de log\n");
        exit(1);
    }
    // Estos if son para que si no hay variable en el log solo se imprima el texto
    if (var != NULL && txt != NULL)
    {
        fprintf(logFile, "%s %s", txt, var);
        printf("%s %s\n", txt, var);
    }
    else if (var == NULL)
    {
        fprintf(logFile, "%s", txt);
        printf("%s\n", txt);
    }
    else if (txt == NULL)
    {
        fprintf(logFile, "%s", var);
        printf("%s\n", var);
    }
    else
    {
        printf("\n");
    }
    fclose(logFile);
}

double horasJugadas(char *fechaInicio, char *fechaFin)
{
    int diaInicio, mesInicio, anoInicio, horaInicio, minInicio;
    int diaFin, mesFin, anoFin, horaFin, minFin;

    sscanf(fechaInicio, "%d/%d/%d %d:%d", &diaInicio, &mesInicio, &anoInicio, &horaInicio, &minInicio);
    sscanf(fechaFin, "%d/%d/%d %d:%d", &diaFin, &mesFin, &anoFin, &horaFin, &minFin);

    time_t tiempoInicio, tiempoFin;
    struct tm tmInicio = {0}, tmFin = {0};
    tmInicio.tm_year = anoInicio - 1900;
    tmInicio.tm_mon = mesInicio - 1;
    tmInicio.tm_mday = diaInicio;
    tmInicio.tm_hour = horaInicio;
    tmInicio.tm_min = minInicio;
    tiempoInicio = mktime(&tmInicio);

    tmFin.tm_year = anoFin - 1900;
    tmFin.tm_mon = mesFin - 1;
    tmFin.tm_mday = diaFin;
    tmFin.tm_hour = horaFin;
    tmFin.tm_min = minFin;
    tiempoFin = mktime(&tmFin);

    double difHoras = difftime(tiempoFin, tiempoInicio) / 3600.0;
    return difHoras;
}