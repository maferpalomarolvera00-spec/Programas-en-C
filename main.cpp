//RR: Round Robin

#include <stdio.h>
#include<string.h>

#define MAX 20

int orden[MAX], prioridad[MAX],tam[MAX];
char nombre_proceso[MAX][15];

int historial[MAX][100];
int total_segundos=0;

void imprimirTabla(int totalRegistros){
    int i,d;
    printf("\n PROCESOS (RR) \n\n");
    printf("%-12s %-15s %-10s %-10s", "NumeroOrden", "Nombre", "Prioridad", "Tam_Ini");

    for (d = 1; d <= total_segundos; d++) {
        printf("%ds   ", d);
    }
    printf("\n");

    for (i = 0; i < totalRegistros; i++) {
        printf("%-12d %-15s %-10d %-10d",
               orden[i],
               nombre_proceso[i],
               prioridad[i],
               historial[i][0]);
        for (d = 1; d <= total_segundos; d++) {
            printf("%-4d ", historial[i][d]);
        }
        printf("\n");
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

void ordernar_tam(int totalRegistros){
    char aux_cad[15];
    for(int k=0;k<totalRegistros;k++){
        for(int i=0;i<totalRegistros-1-k;i++){
            if(tam[i]>tam[i+1]){
                //TAMAÑO
                int aux_tam=tam[i];
                tam[i]=tam[i+1];
                tam[i+1]=aux_tam;

                //ORDEN
                int aux_orden=orden[i];
                orden[i]=orden[i+1];
                orden[i+1]=aux_orden;

                //PRIORIDAD
                int aux_prio=prioridad[i];
                prioridad[i]=prioridad[i+1];
                prioridad[i+1]=aux_prio;

                //NOMBRE DEL PROCESO
                strcpy(aux_cad,nombre_proceso[i]);
                strcpy(nombre_proceso[i],nombre_proceso[i+1]);
                strcpy(nombre_proceso[i+1],aux_cad);
            }
        }
    }
}

void aplicarRegla(int totalRegistros){
    int i;
    int todosEnCero;

    for (i = 0; i < totalRegistros; i++) {
        historial[i][0] = tam[i];
    }

    total_segundos = 0;
    while (1) {
        todosEnCero = 1;
        total_segundos++;

        for (i = 0; i < totalRegistros; i++) {
            int nuevo_tam = historial[i][total_segundos - 1] - 5;
            if (nuevo_tam < 0) {
                nuevo_tam = 0;
            }
            historial[i][total_segundos] = nuevo_tam;
            if (nuevo_tam > 0) {
                todosEnCero = 0;
            }
        }
        if (todosEnCero == 1) {
            break;
        }
    }
}

int main()
{
    int totalRegistros;
    totalRegistros=leerArchivo();

    if(totalRegistros>0){
        ordernar_tam(totalRegistros);

        aplicarRegla(totalRegistros);

        imprimirTabla(totalRegistros);
}

    return 0;
}
