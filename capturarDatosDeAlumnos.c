#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno {
    int matricula;
    char nombre[50];
    char direccion[50];
};

void capturarDatosDeAlumnos(FILE *fp) {
    struct alumno a;

    while (1) {
        printf("Ingresa la matricula del alumno (deja en blanco para salir): ");
        char matriculaStr[50];
        fgets(matriculaStr, sizeof(matriculaStr), stdin);

        if (matriculaStr[0] == '\n') {
            break;
        }

        a.matricula = atoi(matriculaStr);

        printf("Ingresa el nombre del alumno: ");
        fgets(a.nombre, sizeof(a.nombre), stdin);
        a.nombre[strcspn(a.nombre, "\n")] = '\0';  

        printf("Ingresa la direccion del alumno: ");
        fgets(a.direccion, sizeof(a.direccion), stdin);
        a.direccion[strcspn(a.direccion, "\n")] = '\0';  

        fwrite(&a, sizeof(struct alumno), 1, fp);
    }
}
