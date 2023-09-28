#include <stdio.h>
#include <stdlib.h>
#define PATH_FILE "ALUMNOS.dat"

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
  FILE *PROMOCIONADOS_ARCHIVO;
  FILE *CURSADOS_ARCHIVO;
  FILE *REPROBADOS_ARCHIVO;

  struct ALUMNO alumno;
  archivo = fopen(PATH_FILE, "rb");
  PROMOCIONADOS_ARCHIVO = fopen("PROMOCIONADOS.dat", "wb");
  CURSADOS_ARCHIVO = fopen("CURSADOS.dat", "wb");
  REPROBADOS_ARCHIVO = fopen("REPROBADOS.dat", "wb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo");
    exit(1);
  }

  while (!feof(archivo))
  {

    if (alumno.dni != 0)
    {

      if (alumno.nota1 >= 7 && alumno.nota2 >= 7)
      {
        fwrite(&alumno, sizeof(alumno), 1, PROMOCIONADOS_ARCHIVO);
      }
      else if (alumno.nota1 >= 4 && alumno.nota2 < 7)
      {
        fwrite(&alumno, sizeof(alumno), 1, CURSADOS_ARCHIVO);
      }
      else if (alumno.nota1 < 4 || alumno.nota2 < 4)
      {
        fwrite(&alumno, sizeof(alumno), 1, REPROBADOS_ARCHIVO);
      }
    }

    fread(&alumno, sizeof(alumno), 1, archivo);
  }

  fclose(PROMOCIONADOS_ARCHIVO);
  fclose(CURSADOS_ARCHIVO);
  fclose(REPROBADOS_ARCHIVO);

  printf("\n\nPROMOCIONADOS\n");
  LECTURA("PROMOCIONADOS.dat");

  printf("\n\nCURSADOS\n");
  LECTURA("CURSADOS.dat");

  printf("\n\nREPROBADOS\n");
  LECTURA("REPROBADOS.dat");

  printf("\n\n");

  fclose(archivo);
  return 0;
}

void LECTURA(char *path)
{
  FILE *archivo;
  struct ALUMNO alumno;

  archivo = fopen(path, "rb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo");
    exit(1);
  }

  fread(&alumno, sizeof(alumno), 1, archivo);

  while (!feof(archivo))
  {
    printf("\nDNI: %d", alumno.dni);
    printf("\nNombre completo: %s", alumno.nombreCompleto);
    printf("\nNota 1: %d", alumno.nota1);
    printf("\nNota 2: %d", alumno.nota2);
    printf("\nNota promedio: %d", alumno.notaPromedio);
    printf("\n--------------------------");

    fread(&alumno, sizeof(alumno), 1, archivo);
  }

  fclose(archivo);
}
