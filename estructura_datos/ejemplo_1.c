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

  struct PERSONA empleado = { 12345678, "Perez, Juan", 'M', 1, 1, 1980 };

  printf("DNI: %ld\n", empleado.DNI);
  printf("Apellido y Nombre: %s\n", empleado.ApellNombre);
  printf("Sexo: %c\n", empleado.Sexo);
  printf("Fecha de Nacimiento: %d/%d/%d\n", empleado.DiaNacimiento, empleado.MesNacimiento, empleado.AnioNacimiento);

  return 0;
}