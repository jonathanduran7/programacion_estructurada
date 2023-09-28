#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 3

struct VENTA
{
  int codCliente;
  int importe;
  int codVendedor;
};

struct CLIENTE
{
  int codCliente;
  char nombre[50];
};

int main()
{

  struct CLIENTE clientes[MAX_CLIENTES];
  // TODO: ver como hacer dinamico las ventas
  struct VENTA ventas[10];

  CARGA_CLIENTE(clientes);
  CARGA_VENTAS(ventas, clientes);
  MOSTRAR_VENTAS(ventas, clientes);

  return 0;
}

void CARGA_CLIENTE(struct CLIENTE clientes[])
{
  int i = 0;
  while (i < MAX_CLIENTES)
  {
    int codClient;
    printf("\nIngrese el codigo del cliente %d: ", i);
    fflush(stdin);
    scanf("%d", &codClient);

    int pos = BUSQUEDA(clientes, codClient, MAX_CLIENTES);

    if (pos != -1)
    {
      printf("\nEl cliente ya existe");
    }
    else
    {
      char nombre[50];
      printf("\nIngrese el nombre del cliente: ");
      fflush(stdin);
      scanf("%s", nombre);

      if (strcmp(nombre, "FIN") == 0)
      {
        break;
      }
      else
      {
        strcpy(clientes[i].nombre, nombre);
        clientes[i].codCliente = codClient;
      }
      i++;
    }
  }
  printf("\n----------------------Clientes------------------------\n");
}

void CARGA_VENTAS(struct VENTA ventas[], struct CLIENTE clientes[])
{
  int i = 0;
  while (i == 0)
  {
    int codClient, codVendedor, importe;
    printf("\nIngrese el codigo del cliente %d: ", i);
    fflush(stdin);
    scanf("%d", &codClient);

    if (codClient == 999)
    {
      i++;
    }

    if (codClient != 0)
    {
      int pos = BUSQUEDA(clientes, codClient, MAX_CLIENTES);

      if (pos != -1)
      {
        do
        {
          printf("\nIngrese el importe de la venta: ");
          scanf("%d", &importe);

          if (importe <= 0)
            printf("\nEl importe debe ser mayor a 0");

        } while (importe <= 0);

        printf("\nIngrese el codigo del vendedor: ");
        scanf("%d", &codVendedor);

        ventas[i].codCliente = codClient;
        ventas[i].codVendedor = codVendedor;
        ventas[i].importe = importe;
      }
      else
      {
        printf("\nEl cliente no existe\n");
      }
    }
  };
}

int BUSQUEDA(struct CLIENTE clientes[], int codigoIngresado, int limite)
{
  int i, pos;
  i = 0;
  pos = -1;
  while (i < limite && pos == -1)
  {
    if (codigoIngresado == clientes[i].codCliente)
      pos = i;
    else
      i++;
  }
  return pos;
}

void MOSTRAR_VENTAS(struct VENTA ventas[], struct CLIENTE clientes[])
{
  int i = 0;
  printf("\n---------------------- INFORMACION DE VENTAS ------------------------\n");

  printf("%-20s %-12s %-22s\n", "CODIGO DE CLIENTE", "NOMBRE Y APELLIDO", "TOTAL FACTURADO");

  while (i < MAX_CLIENTES)
  {
    printf("%-20d %-12s %-22d\n", clientes[i].codCliente, clientes[i].nombre, 0);
    i++;
  }
}

int CANTIDAD_VENTAS_CLIENTE(struct VENTA ventas[], int codCliente)
{
  int i = 0;
  int cantidad = 0;
  while (i < 10)
  {
    if (ventas[i].codCliente == codCliente)
    {
      cantidad++;
    }
    i++;
  }
  return cantidad;
}