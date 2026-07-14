//FCFS: First Come-First Served

#include <stdio.h>

#define MAX 20

int orden[MAX], prioridad[MAX],tam[MAX];
char nombre_proceso[MAX][15];

void imprimirTabla(int totalRegistros){
    int i;
    printf("\n PROCESOS (FCFS) \n\n");
    printf("%-15s %-20s %-10s %-10s\n",
           "NumeroOrden","Nombre","Tam","Prioridad");

    for (i = 0; i < totalRegistros; i++) {
        printf("%-15d %-20s %-10d %-10d \n",
               orden[i],
               nombre_proceso[i],
               tam[i],
               prioridad[i]);
    }
}

int leerArchivo(){
    int i=0;
    FILE*fp;

    //Abrir el archivo
    fp=fopen("datos.txt","r");
    if (fp == NULL) {
        printf("Error: No se pudo encontrar el archivo 'datos.txt'.\n");
        return 1;
    }
    while (fscanf(fp, "%d %s %d %d", &orden[i], nombre_proceso[i], &tam[i], &prioridad[i]) == 4) {
        i++;
    }
    fclose(fp);
    return i;
}

int main()
{
    int totalRegistros;
    totalRegistros=leerArchivo();
    imprimirTabla(totalRegistros);
    return 0;
}
