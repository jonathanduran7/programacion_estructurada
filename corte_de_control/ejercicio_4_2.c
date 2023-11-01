#include <stdio.h>
#define PATH_VENTAS "ventas.dat"
#define PATH_PRODUCTOS "productos.dat"

struct producto
{
  int producto;
  char des[21];
  float precio;
  int stock;
  int puntodepedido;
  int cantidadparapedido;
};

struct sucursales
{
  char suc[16];
  int producto;
  int cantidad;
};

int main()
{
  FILE *archivo_ventas, *archivo_productos;

  struct producto producto;
  struct sucursales sucursales;

  archivo_ventas = fopen(PATH_VENTAS, "rb");
  archivo_productos = fopen(PATH_PRODUCTOS, "rb");

  if (archivo_ventas == NULL || archivo_productos == NULL)
  {
    printf("Error al abrir el archivo\n");
    exit(1);
  }

  fread(&sucursales, sizeof(struct sucursales), 1, archivo_ventas);

  while (!feof(archivo_ventas))
  {
    printf("Sucursal: %s \t Producto: %d \t Cantidad: %d\n", sucursales.suc, sucursales.producto, sucursales.cantidad);
    fread(&sucursales, sizeof(struct sucursales), 1, archivo_ventas);
  }

  fread(&producto, sizeof(struct producto), 1, archivo_productos);

  while (!feof(archivo_productos))
  {
    printf("Producto: %d \t Descripcion: %s \t Precio: %f \t Stock: %d \t Punto de pedido: %d \t Cantidad para pedido: %d\n", producto.producto, producto.des, producto.precio, producto.stock, producto.puntodepedido, producto.cantidadparapedido);
    fread(&producto, sizeof(struct producto), 1, archivo_productos);
  }

  fclose(archivo_ventas);
  fclose(archivo_productos);
  return 0;
}