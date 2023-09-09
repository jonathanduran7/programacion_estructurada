#include <stdio.h>

struct Producto
{
  char codigo[5];
  int precio;
  char descripcion[30];
  int uniVendidas;
  int impTotal;
};

void cargarProductos(struct Producto[]);

int main()
{
  struct Producto productos[50];
  cargarProductos(productos);
  mostrarProductos(productos);

  return 0;
}

void cargarProductos(struct Producto productos[])
{
  int cantidad = 0;
  while (cantidad <= 2)
  {
    printf("\nIngrese el codigo del producto: ");
    scanf("%s", productos[cantidad].codigo);

    printf("\nIngrese el precio del producto: ");
    scanf("%d", &productos[cantidad].precio);

    getchar();

    printf("\nIngrese la descripcion del producto: ");
    scanf("%s", productos[cantidad].descripcion);

    printf("\nIngrese la cantidad de unidades vendidas: ");
    scanf("%d", &productos[cantidad].uniVendidas);

    printf("\nIngrese el importe total: ");
    scanf("%d", &productos[cantidad].impTotal);

    cantidad++;
  }
}

void mostrarProductos(struct Producto productos[])
{
  for (int i = 0; i < 2; i++)
  {
    // printf("El producto con el codigo %d tiene $%d precio");
  }
}