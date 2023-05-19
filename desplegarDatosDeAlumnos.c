#include <stdio.h>
#include <stdlib.h>

struct alumno {
    int matricula;
    char nombre[50];
    char direccion[50];
};

void desplegarDatosDeAlumnos(FILE *fp) {
    struct alumno a;

    while (fread(&a, sizeof(struct alumno), 1, fp) == 1) {
        printf("Matricula: %d\n", a.matricula);
        printf("Nombre: %s\n", a.nombre);
        printf("Direccion: %s\n", a.direccion);
        printf("\n");
    }
}
