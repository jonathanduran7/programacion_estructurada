#include <stdio.h>
#define PATH_VENTAS "VENTAS.dat"
#define PATH_PRODUCTOS "PRODUCTOS.dat"

struct VENTA
{
  int codigoProducto;
  int cantidad;
  int codigoVendedor;
};

struct PRODUCTO
{
  int codigo;
  float precio;
};

int main()
{
  FILE *archivoVentas, *archivoProductos;
  struct VENTA venta;
  struct PRODUCTO productos[15];

  if((archivoVentas = fopen(PATH_VENTAS, "rb")) == NULL)
  {
    printf("Error al abrir el archivo %s", PATH_VENTAS);
    return 1;
  } else {
    printf("Archivo %s abierto correctamente\n", PATH_VENTAS);
  }

  // fread(&venta, sizeof(struct VENTA), 1, archivoVentas);

  // printf("Ventas:\n");
  // while(!feof(archivoVentas))
  // {
  //   printf("Codigo producto: %d\n", venta.codigoProducto);
  //   printf("Cantidad: %d\n", venta.cantidad);
  //   printf("Codigo vendedor: %d\n", venta.codigoVendedor);
  //   printf("\n");
  //   fread(&venta, sizeof(struct VENTA), 1, archivoVentas);
  // }

  if((archivoProductos = fopen(PATH_PRODUCTOS, "rb")) == NULL)
  {
    printf("Error al abrir el archivo %s", PATH_PRODUCTOS);
    return 1;
  } else {
    printf("Archivo %s abierto correctamente\n", PATH_PRODUCTOS);
  }

  fread(productos, sizeof(struct PRODUCTO), 15, archivoProductos);



  printf("Producto \t Vendedor 1 \t Vendedor 2 \t Vendedor 3 \t Vendedor 4 \t Vendedor 5\n");

  for(int i = 0; i < 15; i++){
    printf("%d \t\n", productos[i].codigo);
  }


  fclose(archivoVentas);
  fclose(archivoProductos);

  return 0;
}