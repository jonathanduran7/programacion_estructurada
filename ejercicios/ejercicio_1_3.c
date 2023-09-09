#include <stdio.h>

int main()
{
  int productos[15];
  int vendedores[5] = {1001, 1002, 1003, 1004, 1005};
  int cantidadVendedores[5] = {0, 0, 0, 0, 0};
  int cantidadProductos[15];

  cargarProductos(productos, 3);
  CargarVentas(vendedores, productos);

  return 0;
}

void cargarProductos(int productos[], int cantidad)
{
  int vuelta = 0;
  while (vuelta < cantidad)
  {
    int codigo;
    printf("\nIngrese codigo: ");
    scanf("%d", &codigo);

    if (codigo >= 100 && codigo <= 999)
    {
      int buscarCodigo = BuscarCodigo(productos, codigo, cantidad);

      if (buscarCodigo == -1)
      {
        productos[vuelta] = codigo;
        vuelta++;
      }
      else
      {
        printf("\nEl codigo ya se ingreso");
      }
    }
    else
    {
      printf("\nEl codigo no es valido por favor ingresa otro.");
    }
  }
}

void CargarVentas(int vendedores[], int productos[])
{
  int vendedor = ingresarVendedor(vendedores);
  // TODO: cargar codigo de articulo
  int codigoProducto = ingresarCodigoProducto(productos);
  // TODO: cargar cantidad
}

int BuscarCodigo(int vector[], int datoABuscar, int cantElem)
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

int ingresarVendedor(int vendedores[])
{

  int codigo, validacion = 0;
  do
  {
    printf("\nIngrese el codigo del vendedor");
    scanf("%d", &codigo);

    int buscarCodigo = BuscarCodigo(vendedores, codigo, 5);
    if (buscarCodigo == -1)
    {
      printf("Por favor ingrese un codigo correcto");
    }
    else
    {
      validacion++;
    }
  } while (validacion == 0);

  return codigo;
}

int ingresarCodigoProducto(int productos[])
{

  int codigo, validacion = 0;
  do
  {
    printf("\nIngrese el codigo del producto");
    scanf("%d", &codigo);

    int codigoBuscado = BuscarCodigo(productos, codigo, 15);
    if (codigoBuscado == -1)
    {
      printf("Por favor ingrese un codigo correcto");
    }
    else
    {
      validacion++;
    }
  } while (validacion == 0);

  return codigo;
}