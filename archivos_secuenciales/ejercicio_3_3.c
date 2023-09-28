#include <stdio.h>
#include <stdlib.h>
#define PATH_ARCHIVO "PRODUCTOS.dat"

struct PRODUCTO
{
  int codigo;
  float precio;
  char descripcion[50];
};

int main()
{
  FILE *archivo;
  struct PRODUCTO productos[100];
  struct PRODUCTO aux;
  int cantidad = 0;

  archivo = fopen(PATH_ARCHIVO, "rb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo");
    exit(1);
  }

  fread(&aux, sizeof(aux), 1, archivo);
  while (!feof(archivo))
  {
    productos[cantidad] = aux;
    cantidad++;
    fread(&aux, sizeof(aux), 1, archivo);
  }
  fclose(archivo);

  printf("Cantidad de productos: %d\n", cantidad);
  printf("Producto 1 codigo: %d\n", productos[0].codigo);

  UPDATEPRODUCTOS(productos, cantidad);

  NuevoArchivo(productos, cantidad);

  return 0;
}

void NuevoArchivo(struct PRODUCTO productos[], int cant)
{
  int i;
  FILE *archivo;
  archivo = fopen("productos.dat", "wb");
  if (archivo == NULL)
  {
    printf("Error");
    exit(1);
  }
  for (i = 0; i < cant; i++)
  {
    printf("Producto\t|\tPrecio");
    fwrite(&productos[i], sizeof(struct PRODUCTO), 1, archivo);
  }
  fclose(archivo);
}

void UPDATEPRODUCTOS(struct PRODUCTO productos[], int cant)
{
  int codigo, x;
  float precio;

  printf("codigo: ");
  scanf("%d", &codigo);
  while (codigo != 0)
  {
    x = BUSQUEDA(productos, codigo, cant);
    if (x != -1)
    {
      printf("Precio: ");
      scanf("%f", &precio);
      productos[x].precio = precio;
    }
    else
      printf("Error.");

    printf("Codigo: ");
    scanf("%d", &codigo);
  }
}

int BUSQUEDA(struct PRODUCTO productos[], int codigo, int cant)
{
  int i = 0, pos = -1;
  while (i < cant && pos == -1)
  {
    if (productos[i].codigo == codigo)
      pos = i;
    else
      i++;
  }
  return pos;
}