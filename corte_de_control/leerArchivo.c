#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO "Empleados.dat" //*

struct generadorDeArchivo
{ //*
    char dato1[50];
    int dato2;
    //*
};

int main()
{

    FILE *archivo;

    struct generadorDeArchivo aux ;

    archivo = fopen(ARCHIVO, "rb");

    if (archivo == NULL)
    {
        printf("Error.");
        exit(1);
    }

    fread(&aux, sizeof(generadorDeArchivo), 1, archivo);
    while (!feof(archivo))
    {
        fread(&aux, sizeof(generadorDeArchivo), 1, archivo);
        printf("%s\t|\t%d |\n", aux.dato1, aux.dato2);
    }

    fclose(archivo);

    return 0;
}