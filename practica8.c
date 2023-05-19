#include <stdio.h>
#include <stdlib.h>

void capturarDatosDeAlumnos(FILE *fp);
void desplegarDatosDeAlumnos(FILE *fp);

int main() {
    FILE *fp;

    fp = fopen("registros.dat", "ab");
    if (fp == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    capturarDatosDeAlumnos(fp);

    fclose(fp);

    fp = fopen("registros.dat", "rb");
    if (fp == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    desplegarDatosDeAlumnos(fp);

    fclose(fp);

    return 0;
}
