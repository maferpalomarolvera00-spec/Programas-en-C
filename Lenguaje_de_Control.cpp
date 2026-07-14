#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>

int main() {
    char comando[100];
    char parametro[100];  //Guardar el nombre de una carpeta o archivo
    char parametro2[100]; //Comandos con dos datos
    char comando_sys[256]; //Comando que se envia al SO
    bool ejecutando = true;

    printf("--------------------------------------------------------\n");
    printf("  Bienvenido al lenguaje de control M & M (Mia & Marin) \n");
    printf("--------------------------------------------------------\n");
    printf("Escribe 'MM-ayuda' para ver la lista de comandos.\n\n");

    while (ejecutando) {
        printf("C:\\Usuario> ");

        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0;

        if (strlen(comando) == 0) continue;


        if (strcmp(comando, "MM-ayuda") == 0) {
            printf("\n--------------------------------------------------------------\n");
            printf(" COMANDO          | DESCRIPCION COMANDO                       \n");
            printf("--------------------------------------------------------------\n");
            printf(" MM-ayuda         | Muestra esta tabla de comandos.           \n");
            printf(" MM-borrar        | Limpia la pantalla.                       \n");
            printf(" MM-hora          | Muestra la hora del sistema.         \n");
            printf(" MM-fecha         | Muestra la fecha del sistema.        \n");
            printf(" MM-listar        | Muestra los archivos de la carpeta actual.\n");
            printf(" MM-ver           | Abre el contenido de texto en consola.    \n");
            printf(" MM-crearArch     | Crea un archivo de texto en blanco.       \n");
            printf(" MM-editar        | Abre el block de notas para editar.       \n");
            printf(" MM-borrarArch    | Elimina un archivo permanentemente.       \n");
            printf(" MM-renombrar     | Cambia el nombre de un archivo.           \n");
            printf(" MM-mover         | Mueve un archivo de un lugar a otro.      \n");
            printf(" MM-copiar        | Copia un archivo exacto.                  \n");
            printf(" MM-atributos     | Muestra los atributos reales.    \n");
            printf(" MM-crearDir      | Crea una nueva carpeta real.              \n");
            printf(" MM-borrarDir     | Elimina una carpeta.                      \n");
            printf(" MM-cd            | Cambia de directorio.                     \n");
            printf(" MM-salir         | Cierra el programa.                       \n");
            printf("--------------------------------------------------------------\n\n");
        }
        else if (strcmp(comando, "MM-borrar") == 0) {
            system("cls");
        }
        else if (strcmp(comando, "MM-hora") == 0) {
            system("time /t");
            printf("\n");
        }
        else if (strcmp(comando, "MM-fecha") == 0) {
            system("date /t");
            printf("\n");
        }
        else if (strcmp(comando, "MM-listar") == 0) {
            system("dir");
            printf("\n");
        }
        else if (strcmp(comando, "MM-ver") == 0) {
            printf("Nombre del archivo a leer (ej. texto.txt): ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "type \"%s\"", parametro);
            system(comando_sys);
            printf("\n");
        }
        else if (strcmp(comando, "MM-crearArch") == 0) {
            printf("Nombre del nuevo archivo (ej. nuevo.txt): ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "echo. > \"%s\"", parametro);
            system(comando_sys);
            printf("Archivo '%s' creado.\n\n", parametro);
        }
        else if (strcmp(comando, "MM-editar") == 0) {
            printf("Nombre del archivo a editar: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "notepad \"%s\"", parametro);
            system(comando_sys);
            printf("Se abrio el editor.\n\n");
        }
        else if (strcmp(comando, "MM-borrarArch") == 0) {
            printf("Nombre del archivo A BORRAR: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "del \"%s\"", parametro);
            system(comando_sys);
            printf("Comando de borrado ejecutado.\n\n");
        }
        else if (strcmp(comando, "MM-renombrar") == 0) {
            printf("Nombre actual del archivo: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            printf("Nuevo nombre: ");
            fgets(parametro2, sizeof(parametro2), stdin);
            parametro2[strcspn(parametro2, "\n")] = 0;

            sprintf(comando_sys, "ren \"%s\" \"%s\"", parametro, parametro2);
            system(comando_sys);
            printf("Comando renombrar ejecutado.\n\n");
        }
        else if (strcmp(comando, "MM-mover") == 0) {
            printf("Archivo a mover: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            printf("Ruta de destino (ej. C:\\Carpeta): ");
            fgets(parametro2, sizeof(parametro2), stdin);
            parametro2[strcspn(parametro2, "\n")] = 0;

            sprintf(comando_sys, "move \"%s\" \"%s\"", parametro, parametro2);
            system(comando_sys);
            printf("\n");
        }
        else if (strcmp(comando, "MM-copiar") == 0) {
            printf("Archivo a copiar: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            printf("Ruta o nombre de destino: ");
            fgets(parametro2, sizeof(parametro2), stdin);
            parametro2[strcspn(parametro2, "\n")] = 0;

            sprintf(comando_sys, "copy \"%s\" \"%s\"", parametro, parametro2);
            system(comando_sys);
            printf("\n");
        }
        else if (strcmp(comando, "MM-atributos") == 0) {
            printf("Nombre del archivo: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "attrib \"%s\"", parametro);
            system(comando_sys);
            printf("\n");
        }
        else if (strcmp(comando, "MM-crearDir") == 0) {
            printf("Nombre de la nueva carpeta: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "mkdir \"%s\"", parametro);
            system(comando_sys);
            printf("Carpeta creada.\n\n");
        }
        else if (strcmp(comando, "MM-borrarDir") == 0) {
            printf("Nombre de la carpeta a borrar: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            sprintf(comando_sys, "rmdir \"%s\"", parametro);
            system(comando_sys);
            printf("Comando borrar carpeta ejecutado.\n\n");
        }
        else if (strcmp(comando, "MM-cd") == 0) {
            printf("Nombre de la carpeta a la que quieres entrar: ");
            fgets(parametro, sizeof(parametro), stdin);
            parametro[strcspn(parametro, "\n")] = 0;

            if (_chdir(parametro) != 0) {
                printf("Error: No se pudo acceder a la carpeta '%s'.\n\n", parametro);
            } else {
                printf("Directorio cambiado con exito.\n\n");
            }
        }
        else if (strcmp(comando, "MM-salir") == 0) {
            printf("Saliendo del sistema MM...\n");
            ejecutando = false;
        }

        else {
            printf("Error: El comando '%s' no existe.\n", comando);

            if (strstr(comando, "fecha")) printf("Tal vez quisiste decir: 'MM-fecha'\n\n");
            else if (strstr(comando, "ver")) printf("Tal vez quisiste decir: 'MM-ver'\n\n");
            else if (strstr(comando, "crear") && strstr(comando, "dir")) printf("Tal vez quisiste decir: 'MM-crearDir'\n\n");
            else if (strstr(comando, "crear") && strstr(comando, "arch")) printf("Tal vez quisiste decir: 'MM-crearArch'\n\n");
            else if (strstr(comando, "renombrar")) printf("Tal vez quisiste decir: 'MM-renombrar'\n\n");
            else if (strstr(comando, "mover")) printf("Tal vez quisiste decir: 'MM-mover'\n\n");
            else if (strstr(comando, "atributos")) printf("Tal vez quisiste decir: 'MM-atributos'\n\n");
            else if (strstr(comando, "ayuda") || strstr(comando, "help")) printf("Tal vez quisiste decir: 'MM-ayuda'\n\n");
            else printf("Recuerda que todos los comandos empiezan con 'MM-'. Usa 'MM-ayuda'.\n\n");
        }
    }

    return 0;
}
