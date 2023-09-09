#include <stdio.h>

void IngresaCodigos(int[], int);
void IngresaPedidos(int[],int[],int);
void MostrarVector(int[],int[],int);
int Busqueda(int[], int, int);

int main()
{

  int codigoProductos[10];
  int cantidadPedidos[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int cantidades = 10;
  IngresaCodigos(codigoProductos, cantidades);

  printf("--------------------------");

  IngresaPedidos(cantidadPedidos, codigoProductos, cantidades);

  printf("--------------------------");

  MostrarVector(codigoProductos, cantidadPedidos ,cantidades);
  return 0;
}

void IngresaCodigos(int codigos[], int cantidad)
{
  int i;
  for (i = 0; i < cantidad; i++)
  {
    int existeCodigo, codigo, esValido;
    do
    {
      printf("\nIngrese el codigo del producto: ");
      scanf("%d", &codigo);

      if (codigo >= 1000 && codigo <= 9999)
      {
        existeCodigo = Busqueda(codigos, codigo, cantidad);
        if (existeCodigo == -1)
        {
          codigos[i] = codigo;
          esValido++;
        }
        else
        {
          esValido = 0;
          printf("\nEl codigo no se puede guardar porque ya existe");
        }
      }
      else
      {
        esValido = 0;
        printf("El codigo debe ser de 4 cifras");
      }
    } while (existeCodigo != -1 && i != cantidad && esValido == 0);
  }
}

int Busqueda(int vector[], int datoABuscar, int cantElem)
{
  int i = 0, pos = -1;
  while (pos == -1 && i < cantElem)
  {
    if (vector[i] == datoABuscar)
    {
      pos = i;
    }
    else
    {
      i++;
    }
  }
  return pos;
}

void MostrarVector(int codigos[],int unidades[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    printf("\nEl producto con codigo %d tuvo %d pedidos", codigos[i], unidades[i]);
  }
}

void IngresaPedidos(int cantidadPedidos[], int codigos[], int cantidad)
{
  int producto, busqueda;
  do
  {
    printf("\nIngrese codigo para el pedido: ");
    scanf("%d", &producto);

    if (producto != 0)
    {
      busqueda = Busqueda(codigos, producto, cantidad);
      if (busqueda == -1)
      {
        printf("\nEl codigo del producto no existe por favor ingrese devuelta");
      }
      else
      {
        int unidadesSolicitadas;
        printf("\nIngrese la cantidad de unidades solicitadas: ");
        scanf("%d", &unidadesSolicitadas);
        cantidadPedidos[busqueda] += unidadesSolicitadas;
      }
    }
  } while (producto != 0);
}