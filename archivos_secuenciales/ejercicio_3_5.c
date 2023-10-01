#include <stdio.h>
#define PATH_ARCHIVO "STOCK.dat"

struct PRODUCTO
{
  int codigo;
  char descripcion[50];
  int stock;
};

struct FALTANTE
{
  int codigo;
  int cantidad;
};

int main()
{

  struct PRODUCTO productos[10];
  struct FALTANTE faltante;

  CargaProductos(productos);
  CargaVentas(productos, faltante);
  ActualizarStock(productos, 10);
  MostrarProductos(productos, 10);

  return 0;
}

void CargaProductos(struct PRODUCTO productos[])
{
  FILE *archivo;
  archivo = fopen(PATH_ARCHIVO, "rb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    exit(1);
  };

  fread(productos, sizeof(struct PRODUCTO), 10, archivo);

  fclose(archivo);
}

void CargaVentas(struct PRODUCTO productos[], struct FALTANTE faltante)
{
  FILE *archivo;
  archivo = fopen("FALTANTE.dat", "wb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    exit(1);
  };

  int codigo;
  printf("Ingrese Codigo de Producto: ");
  scanf("%d", &codigo);

  while (codigo != 0)
  {
    int codigoBuscado = Busqueda(productos, codigo, 10);

    if (codigoBuscado == -1)
    {
      printf("Codigo no encontrado\n");
    }
    else
    {
      int cantidad;
      printf("Ingrese cantidad de productos a vender: ");
      scanf("%d", &cantidad);

      if (productos[codigoBuscado].stock < cantidad)
      {
        printf("No hay stock suficiente, el stock restante es: %d\n", productos[codigoBuscado].stock);
        faltante.codigo = codigo;
        faltante.cantidad = -(productos[codigoBuscado].stock - cantidad);
        fwrite(&faltante, sizeof(struct FALTANTE), 1, archivo);
      }
      else
      {
        productos[codigoBuscado].stock -= cantidad;
      }
    }

    printf("Ingrese Codigo de Producto: ");
    scanf("%d", &codigo);
  }

  fclose(archivo);
}

int Busqueda(struct PRODUCTO productos[], int codigo, int cant)
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

void ActualizarStock(struct PRODUCTO productos[], int cant)
{
  FILE *archivo;
  archivo = fopen(PATH_ARCHIVO, "wb");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    exit(1);
  };

  fwrite(productos, sizeof(struct PRODUCTO), cant, archivo);

  fclose(archivo);
}

void MostrarProductos(struct PRODUCTO productos[], int cant)
{
  int i;
  for (i = 0; i < cant; i++)
  {
    printf("Codigo: %d\n", productos[i].codigo);
    printf("Descripcion: %s\n", productos[i].descripcion);
    printf("Stock: %d\n", productos[i].stock);
  }
}