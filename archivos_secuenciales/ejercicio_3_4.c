#include <stdio.h>
#include <stdlib.h>
#define PATH_ARCHIVO "PRECIOS.dat"

struct PRODUCTO
{
  int codigo;
  float precio;
  char descripcion[30];
};

int main()
{
  FILE *archivo;
  FILE *archivo_nuevo;

  struct PRODUCTO producto;

  int porcentaje_aumento;

  printf("Ingrese el porcentaje de aumento: ");
  scanf("%d", &porcentaje_aumento);

  if ((archivo = fopen(PATH_ARCHIVO, "rb")) == NULL)
  {
    printf("Error al abrir el archivo.\n");
    exit(1);
  }

  if ((archivo_nuevo = fopen("PRECIOS_NUEVOS.dat", "wb")) == NULL)
  {
    printf("Error al abrir el archivo.\n");
    exit(1);
  }

  fread(&producto, sizeof(struct PRODUCTO), 1, archivo);

  while (!feof(archivo))
  {
    producto.precio += producto.precio * porcentaje_aumento / 100;
    fwrite(&producto, sizeof(struct PRODUCTO), 1, archivo_nuevo);
    fread(&producto, sizeof(struct PRODUCTO), 1, archivo);
  }

  fclose(archivo);
  fclose(archivo_nuevo);

  return 0;
}