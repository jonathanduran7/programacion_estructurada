#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 50

struct PRODUCTO
{
  char codigo[5];
  int precio;
  char descripcion[30];
  int cantVendidas;
  int importeTotalVendido;
};

int main()
{

  struct PRODUCTO productos[MAX_PRODUCTOS];
  int cantidades[MAX_PRODUCTOS] = {{0}};

  ingresarProductos(productos, MAX_PRODUCTOS);

  printf("\n-----------------------Ingrese ventas --------- \n");

  ingresarVentas(productos, cantidades);

  printf("\n----------------------Ventas del mes ------------------------\n");

  actualizarProductos(productos, cantidades);

  mostrarVentas(productos);

  return 0;
}

void ingresarProductos(struct PRODUCTO productos[], int limite)
{
  int i = 0;
  while (i < limite)
  {
    printf("Ingrese el codigo del producto %d: ", i);
    fflush(stdin);
    scanf("%s", productos[i].codigo);

    printf("\nIngrese el precio del producto: ");
    fflush(stdin);
    scanf("%d", &productos[i].precio);

    printf("\nIngrese la descripcion del producto: ");
    fflush(stdin);
    scanf("%s", productos[i].descripcion);

    strupr(productos[i].descripcion);

    if (strcmp(productos[i].descripcion, "FIN") == 0)
    {
      break;
    }

    printf("\nIngrese la cantidad de unidades vendidas: ");
    scanf("%d", &productos[i].cantVendidas);

    productos[i].importeTotalVendido = productos[i].precio * productos[i].cantVendidas;

    printf("\nEL importe total vendido del mes anterior es: %d\n\n", productos[i].importeTotalVendido);

    i++;
  }

  printf("\nSe finalizo con la carga de productos");
}

void ingresarVentas(struct PRODUCTO productos[], int cantidades[])
{
  int valid = 0;
  while (valid == 0)
  {
    char codigo[5];
    int codigoNoencontrado = -1;
    printf("\nIngrese el codigo del producto: ");
    scanf("%s", codigo);
    fflush(stdin);

    int codigoBuscado = buscar(productos, codigo, MAX_PRODUCTOS);
    if (codigoBuscado != codigoNoencontrado)
    {
      int cantidadVendidas;
      printf("\nIngrese la cantidad vendida: ");
      scanf("%d", &cantidadVendidas);

      if (cantidadVendidas == 0)
      {
        valid++;
      }
      else
      {
        cantidades[codigoBuscado] += cantidadVendidas;
      }
    }
    else
    {
      printf("\nEl codigo no existe por favor ingrese otro");
    }
  }
}

void actualizarProductos(struct PRODUCTO productos[], int cantidades[])
{
  int i = 0, valid = 0;
  while (i < MAX_PRODUCTOS && valid == 0)
  {
    if (strcmp(productos[i].descripcion, "FIN") == 0)
    {
      valid++;
    }
    else
    {
      productos[i].cantVendidas = cantidades[i];
      productos[i].importeTotalVendido = productos[i].precio * productos[i].cantVendidas;
      i++;
    }
  };
}

void mostrarVentas(struct PRODUCTO productos[])
{
  int i = 0, valid = 0;

  printf("%-20s %-12s %-12s\n", "Descripcion", "CantVendidas", "Total");
  while (i < MAX_PRODUCTOS && valid == 0)
  {
    if (strcmp(productos[i].descripcion, "FIN") == 0)
    {
      valid++;
    }
    else
    {
      printf("%-20s %-12d %-12d\n", productos[i].descripcion, productos[i].cantVendidas, productos[i].importeTotalVendido);
      i++;
    }
  };
}

// FUNCIONES AUXULIARES

int buscar(struct PRODUCTO productos[], char dato[], int limite)
{
  int i = 0, posicion = -1;
  while (posicion == -1 && i < limite)
  {
    if (strcmp(productos[i].codigo, dato) == 0)
    {
      posicion = i;
    }
    else
    {
      i++;
    }
  }
  return posicion;
}

void strupr(char *p)
{
  while (*p)
  {
    *p = toupper(*p);
    p++;
  }
}