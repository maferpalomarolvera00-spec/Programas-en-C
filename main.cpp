//SJR: Shortest Job First

#include <stdio.h>
#include<string.h>

#define MAX 20

int orden[MAX], prioridad[MAX],tam[MAX];
char nombre_proceso[MAX][15];

int historial[MAX][100];
int total_segundos=0;

void imprimirTabla(int totalRegistros){
    int i;
    printf("\n PROCESOS (SJR) \n\n");
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

int main()
{
    int totalRegistros;
    totalRegistros=leerArchivo();

    if(totalRegistros>0){
        ordernar_tam(totalRegistros);
        imprimirTabla(totalRegistros);
}

    return 0;
}
