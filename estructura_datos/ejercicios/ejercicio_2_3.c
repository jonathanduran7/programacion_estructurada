#include <stdio.h>

#define MAX_ALUMNOS 80

struct alumno
{
  int dni;
  char nombreCompleto[80];
  int nota1;
  int nota2;
  float promedio;
};

int ingreso(struct alumno[], int);
void resultados(struct alumno[], int);
void informePromo(struct alumno[], int);

int main()
{
  struct alumno vAlumnos[MAX_ALUMNOS];
  int cant;

  cant = ingreso(vAlumnos, MAX_ALUMNOS);

  return 0;
}

int ingreso(struct alumno vector[], int limite)
{
  int i =0, dni;
  printf("Ingrese dni: ");

}