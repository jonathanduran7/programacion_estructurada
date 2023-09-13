#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 20
#define MAX_LONGITUD_CODIGO 3

int main()
{
  char codigosProductos[MAX_PRODUCTOS][MAX_LONGITUD_CODIGO];
  int preciosProductos[MAX_PRODUCTOS];

  int ventasProductos[MAX_PRODUCTOS];

  cargarInformacion(codigosProductos, preciosProductos);
  IngresarVentas(codigosProductos, preciosProductos);
  return 0;
}

void cargarInformacion(char codigos[][MAX_LONGITUD_CODIGO], int precios[])
{
  int contador = 0;

  while (contador < MAX_PRODUCTOS)
  {
    // INGRESAR EL NOMBRE
    printf("\nIngrese el codigo del producto: ");
    scanf("%s", codigos[contador]);

    if (strcmp(codigos[contador], "FIN") == 0)
    {
      break;
    }

    // INGRESAR EL DOCUMENTO
    printf("\nIngrese el precio del producto: ");
    scanf("%d", &precios[contador]);

    contador++;
  }

  printf("\n-------------------------------------");
  printf("\nSe finalizo con la carga de productos");
  printf("\n-------------------------------------\n");
};

// TODO: ingresar ventas
void IngresarVentas(char codigos[][MAX_LONGITUD_CODIGO],int preciosProductos[])
{
  char abuscar[MAX_LONGITUD_CODIGO];
  printf("\nIngresar el codigo del producto: ");
  scanf("%s", abuscar);

  int codigoBuscado = buscar(codigos, abuscar, MAX_PRODUCTOS);

  if (codigoBuscado == -1)
  {
    printf("\nEl codigo ingresado no existe.\n");
  }
  else
  {
    int cantidad;
    printf("\nIngrese la cantidad de unidades vendidas: ");
    scanf("%d", &cantidad);

    printf("\nEl producto con precio %d y %d unidades vendidas hizo una venta de %d",preciosProductos[codigoBuscado],cantidad,preciosProductos[codigoBuscado]*cantidad);
  }
}

int buscar(char vector[][MAX_LONGITUD_CODIGO], char buscado[], int cant)
{
  int i = 0, pos = -1;
  while (pos == -1 && i < cant)
  {
    if (strcmp(vector[i], buscado) == 0)
      pos = i;
    else
      i++;
  }
  return pos;
}
