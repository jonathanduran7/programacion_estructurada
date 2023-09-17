#include <stdio.h>

struct PERSONA // Aqui se declara la estructura de datos
{
  long int DNI;
  char ApellNombre[41];
  char Sexo;
  int DiaNacimiento;
  int MesNacimiento;
  int AnioNacimiento;
};

int main()
{

  struct PERSONA jefe = { 12345678, "Perez, Juan", 'M', 1, 1, 1980 };
  struct PERSONA empleados[10];

  for (int i = 0; i < 10; i++)
  {
    printf("\nIngrese el dni: ");
    scanf("%d", &empleados[i].DNI);

    printf("\nIngrese el sexo: ");
    scanf(" %c", &empleados[i].Sexo);
  }



  return 0;
}