#include <stdio.h>
#define PATH_ARCHIVO "ALUMNOS.dat"

struct ALUMNO
{
  int dni;
  char nombreCompleto[80];
  int nota1;
  int nota2;
  int notaPromedio;
};

int main()
{

  FILE *archivo;
  struct ALUMNO alumno;

  archivo = fopen(LLAMADAS_FILE, "wb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo");
    exit(1);
  }

  printf("\nIngrese el DNI del alumno: ");
  scanf("%d", &alumno.dni);
  while (alumno.dni != 0)
  {
    printf("Ingrese el nombre completo del alumno: ");
    fflush(stdin);
    scanf("%s", alumno.nombreCompleto);

    printf("Ingrese la nota 1 del alumno: ");
    scanf("%d", &alumno.nota1);

    printf("Ingrese la nota 2 del alumno: ");
    scanf("%d", &alumno.nota2);

    alumno.notaPromedio = (alumno.nota1 + alumno.nota2) / 2;

    fwrite(&alumno, sizeof(alumno), 1, archivo);

    printf("\nIngrese el DNI del alumno: ");
    scanf("%d", &alumno.dni);
  }

  fclose(archivo);
  LECTURA();

  return 0;
}

void LECTURA()
{
  FILE *archivo;
  struct ALUMNO alumno;

  archivo = fopen(LLAMADAS_FILE, "rb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo");
    exit(1);
  }

  printf("dni\t|\tnombre\t|\tPrimer nota\t|\tSegunda Nota\t|\tPromedio");
  while (!feof(archivo))
  {
    printf("%d\t|\t%s\t|\t%d\t|\t%d\t|\t%d", alumno.dni, alumno.nombreCompleto, alumno.nota1, alumno.nota2, alumno.notaPromedio);
    fread(&alumno, sizeof(alumno), 1, archivo);
  }

  fclose(archivo);
}