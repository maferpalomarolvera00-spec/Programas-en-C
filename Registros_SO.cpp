#include <stdio.h>
#include <string.h>

#define MAX 20
#define REGISTROS_INICIALES 15
#define DISCO_TOTAL 1024
#define TAM_SECTOR_FIJO 512

int tam[MAX], sector[MAX], tamSector[MAX];
char root[MAX][20];
char usuario[MAX][20];
char nombre[MAX][10];
char fechaHora[MAX][25];
char tipo[MAX][15];
char origen[MAX][15];
char antecede[MAX][10];
char precede[MAX][10];
char atributos[MAX][10];

void mostrarTabla(int totalRegistros) {
    int j;

    printf("\nARCHIVOS\n\n");
    printf("%-5s %-7s %-8s %-5s %-20s %-8s %-8s %-8s %-8s %-8s %-8s %-8s\n",
           "Root", "Usuario", "Nombre", "Tam", "FechaHora", "Tipo",
           "Sector", "Origen", "Antecede", "Precede", "Atributos", "T.Sector");

    for (j = 0; j < totalRegistros; j++) {
        printf("%-5s %-7s %-8s %-5d %-20s %-8s %-8d %-8s %-8s %-8s %-9s %-8d\n",
               root[j],
               usuario[j],
               nombre[j],
               tam[j],
               fechaHora[j],
               tipo[j],
               sector[j],
               origen[j],
               antecede[j],
               precede[j],
               atributos[j],
               tamSector[j]);
    }
}

int calcularUsado(int totalRegistros) {
    int j, usado = 0;

    for (j = 0; j < totalRegistros; j++) {
        usado += tam[j];
    }

    return usado;
}

void actualizarEnlaces(int totalRegistros) {
    int j;

    for (j = 0; j < totalRegistros; j++) {
        if (j == 0) {
            strcpy(antecede[j], "---");
        } else {
            strcpy(antecede[j], nombre[j - 1]);
        }
        if (j == totalRegistros - 1) {
            strcpy(precede[j], "---");
        } else {
            strcpy(precede[j], nombre[j + 1]);
        }
    }
}

int main() {
    FILE *fp;
    int i = 0;
    int usado, libre;
    float porcentaje;
    char nuevoRoot[20], nuevoUsuario[20], nuevoNombre[10];
    char nuevaFechaHora[25], nuevoTipo[15], nuevoOrigen[15], nuevosAtributos[10];
    int nuevoTam, nuevoSector;

    fp = fopen("datos.txt", "r");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo datos.txt\n");
        return 1;
    }

    while (i < REGISTROS_INICIALES &&
           fscanf(fp, "%s %s %s %d %s %s %d %s %s %s %s %d",
                  root[i],
                  usuario[i],
                  nombre[i],
                  &tam[i],
                  fechaHora[i],
                  tipo[i],
                  &sector[i],
                  origen[i],
                  antecede[i],
                  precede[i],
                  atributos[i],
                  &tamSector[i]) == 12) {
        i++;
    }

    fclose(fp);

    printf("\n----------- TABLA -----------\n");
    mostrarTabla(i);
    usado = calcularUsado(i);
    libre = DISCO_TOTAL - usado;
    porcentaje = (usado * 100.0f) / DISCO_TOTAL;

    printf("\nTotal Disco: %d bytes\n", DISCO_TOTAL);
    printf("Espacio Usado: %d bytes\n", usado);
    printf("Espacio Libre: %d bytes\n", libre);
    printf("Porcentaje de Uso: %.2f%%\n", porcentaje);

    printf("\n----------- AGREGAR UN REGISTRO -----------\n");

    printf("Ingrese root: ");
    scanf("%s", nuevoRoot);

    printf("Ingrese usuario: ");
    scanf("%s", nuevoUsuario);

    printf("Ingrese nombre del archivo: ");
    scanf("%s", nuevoNombre);

    printf("Ingrese tamano: ");
    scanf("%d", &nuevoTam);

    printf("Ingrese fecha y hora (ejemplo 26/03/2026_11:00): ");
    scanf("%s", nuevaFechaHora);

    printf("Ingrese tipo de archivo: ");
    scanf("%s", nuevoTipo);

    printf("Ingrese sector de almacenamiento: ");
    scanf("%d", &nuevoSector);

    printf("Ingrese origen (Interno/Externo): ");
    scanf("%s", nuevoOrigen);

    printf("Ingrese atributos del archivo: ");
    scanf("%s", nuevosAtributos);

    if (nuevoTam <= libre && i < MAX) {
        strcpy(root[i], nuevoRoot);
        strcpy(usuario[i], nuevoUsuario);
        strcpy(nombre[i], nuevoNombre);
        tam[i] = nuevoTam;
        strcpy(fechaHora[i], nuevaFechaHora);
        strcpy(tipo[i], nuevoTipo);
        sector[i] = nuevoSector;
        strcpy(origen[i], nuevoOrigen);
        strcpy(atributos[i], nuevosAtributos);


        tamSector[i] = TAM_SECTOR_FIJO;
        i++;
        actualizarEnlaces(i);

        usado = calcularUsado(i);
        libre = DISCO_TOTAL - usado;
        porcentaje = (usado * 100.0f) / DISCO_TOTAL;

        printf("\nRegistro agregado correctamente.\n");
        mostrarTabla(i);

        printf("\nTotal Disco: %d bytes\n", DISCO_TOTAL);
        printf("Espacio Usado: %d bytes\n", usado);
        printf("Espacio Libre: %d bytes\n", libre);
        printf("Porcentaje de Uso: %.2f%%\n", porcentaje);
    } else {
        printf("\nERROR: No hay suficiente espacio para agregar el archivo.\n");
    }

    printf("\n----------- AGREGAR OTRO REGISTRO -----------\n");

    printf("Ingrese root: ");
    scanf("%s", nuevoRoot);

    printf("Ingrese usuario: ");
    scanf("%s", nuevoUsuario);

    printf("Ingrese nombre del archivo: ");
    scanf("%s", nuevoNombre);

    printf("Ingrese tamano: ");
    scanf("%d", &nuevoTam);

    printf("Ingrese fecha y hora (ejemplo 26/03/2026_11:30): ");
    scanf("%s", nuevaFechaHora);

    printf("Ingrese tipo de archivo: ");
    scanf("%s", nuevoTipo);

    printf("Ingrese sector de almacenamiento: ");
    scanf("%d", &nuevoSector);

    printf("Ingrese origen (Interno/Externo): ");
    scanf("%s", nuevoOrigen);

    printf("Ingrese atributos del archivo: ");
    scanf("%s", nuevosAtributos);

    if (nuevoTam <= libre && i < MAX) {
        strcpy(root[i], nuevoRoot);
        strcpy(usuario[i], nuevoUsuario);
        strcpy(nombre[i], nuevoNombre);
        tam[i] = nuevoTam;
        strcpy(fechaHora[i], nuevaFechaHora);
        strcpy(tipo[i], nuevoTipo);
        sector[i] = nuevoSector;
        strcpy(origen[i], nuevoOrigen);
        strcpy(atributos[i], nuevosAtributos);


        tamSector[i] = TAM_SECTOR_FIJO;

        i++;
        actualizarEnlaces(i);

        usado = calcularUsado(i);
        libre = DISCO_TOTAL - usado;
        porcentaje = (usado * 100.0f) / DISCO_TOTAL;

        printf("\nRegistro agregado correctamente.\n");
        mostrarTabla(i);

        printf("\nTotal Disco: %d bytes\n", DISCO_TOTAL);
        printf("Espacio Usado: %d bytes\n", usado);
        printf("Espacio Libre: %d bytes\n", libre);
        printf("Porcentaje de Uso: %.2f%%\n", porcentaje);
    } else {
        printf("\nYa no hay espacio en el disco, el archivo es muy grande\n");
    }

    return 0;
}
