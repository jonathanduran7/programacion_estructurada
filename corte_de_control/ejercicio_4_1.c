#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int numCanal;
  char programa[35];
  float rating;
} Canal;

typedef struct
{
  int numCanal;
  float promedio;
} CanalPromedio;

int main()
{
  FILE *archivo, *archivoPromedio;
  Canal canal;
  CanalPromedio canalPromedio;
  int canalAnterior, contadorCanal, contadorRating = 0, maxRating = 0, canalMaxRating = 0;

  archivo = fopen("RATING.dat", "rb");
  archivoPromedio = fopen("PROMEDIO.dat", "wb");

  if (archivo == NULL || archivoPromedio == NULL)
  {
    printf("Error al abrir el archivo\n");
    exit(1);
  }

  fread(&canal, sizeof(Canal), 1, archivo);
  printf("----- CANALES CON MENOS DE 15 PUNTOS DE RATING -----\n");
  while (!feof(archivo))
  {
    // printf("Canal: %d \t Programa: %s \t Rating %1.f\n", canal.numCanal, canal.programa, canal.rating);
    canalAnterior = canal.numCanal;
    contadorCanal = 0;
    contadorRating = 0;
    while (canal.numCanal == canalAnterior && !feof(archivo))
    {
      contadorCanal++;
      contadorRating += canal.rating;
      fread(&canal, sizeof(Canal), 1, archivo);
    }

    if (contadorRating > maxRating)
    {
      maxRating = contadorRating;
      canalMaxRating = canalAnterior;
    }

    if (contadorRating < 15)
    {
      printf("El canal %d tiene %d puntos de rating\n", canalAnterior, contadorRating);
    }

    canalPromedio.numCanal = canalAnterior;
    canalPromedio.promedio = contadorRating / contadorCanal;
    fwrite(&canalPromedio, sizeof(CanalPromedio), 1, archivoPromedio);
  }

  printf("\n----- CANAL CON MAYOR RATING -----");
  printf("\nEl canal con mayor rating es %d con %d\n", canalMaxRating, maxRating);

  fclose(archivo);
  fclose(archivoPromedio);
  return 0;
}