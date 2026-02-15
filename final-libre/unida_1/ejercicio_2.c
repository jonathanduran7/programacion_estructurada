/*
Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.

Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota.
*/
#include <stdio.h>

int Buscar(int[],int,int);

int main(){
    int alumnos[60] = {0};
    int notas[60] = {0};

    int dni, indice;

    printf("\nIngrese el dni del alumno: ");
    scanf("%d", &dni);

    while (dni != 0 || indice < 60) {
        int buscar = Buscar(alumnos, dni, 60);

        while(buscar != -1){
            printf("\nEl dni ya existe ingrese otro: %d", buscar);
            scanf("%d", &dni);

            if(dni == 0)
                break;

            buscar = Buscar(alumnos, dni, 60);

            printf("%d", buscar);
        } 

        int nota; 
        printf("\nIngrese la nota del alumno: "); 
        scanf("%d",&nota);

        while (nota < 1 || nota > 10) {
            printf("Por favor ingrese una nota valida: ");
            scanf("%d",&nota);
        }

        alumnos[indice] = dni;
        notas[indice] = nota;
        indice++;

        printf("\nIngrese el dni del alumno: ");
        scanf("%d", &dni);

        if(dni == 0)
            break;
    }

    return 0;
}

int Buscar(int vector[60], int buscar, int cantidad){
    for(int i = 0; i < cantidad; i++){
        if(vector[i] == buscar)
            return i;
    }
    return -1;
}