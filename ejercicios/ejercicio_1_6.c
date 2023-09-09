#include <stdio.h>

int main()
{
  int maximo = 3;
  int empresas[maximo];
  char servicios[maximo];

  int empresasFacturacion[maximo];
  int meses[12] = {{0}};

  IngresarEmpresas(empresas, servicios, maximo);

  // TODO: ingresar facturacion
  // CODIGO => 1122
  // MES => 2
  // IMPORTE => 1245

  IngresarFacturacion(empresas, empresasFacturacion, meses, maximo);

  return 0;
}

void IngresarEmpresas(int empresas[], char servicios[], int maximo)
{
  int limite = 0, validacion = 0;
  while (limite < maximo && validacion == 0)
  {
    // REMEMBER: borrar este print
    printf("\nVuelta: %d", limite);
    int codigoEmpresa;
    printf("\nIngrese el codigo de la empresa");
    scanf("%d", &codigoEmpresa);

    if (codigoEmpresa != 0)
    {
      if (codigoEmpresa < 1000 || codigoEmpresa > 5000)
      {
        printf("\nEl codgio no es valido ingrese otro por favor");
      }
      else
      {
        int codigoBuscado = BuscarCodigo(empresas, codigoEmpresa, maximo);

        if (codigoBuscado == -1)
        {
          IngresarServicio(servicios, limite);
          empresas[limite] = codigoEmpresa;
          limite++;
        }
        else
        {
          printf("\nEl codigo ya fue ingresado, por favor ingrese otro.");
        }
      }
    }
    else
    {
      validacion++;
    }
  }
}

void IngresarServicio(char servicios[], int posicion)
{
  int validacion = 0;
  while (validacion == 0)
  {
    char servicio;
    printf("\nIngrese el servicio");
    scanf(" %c", &servicio);

    if (servicio == 'L' || servicio == 'A' || servicio == 'G')
    {
      servicios[posicion] = servicio;
      validacion++;
    }
    else
    {
      printf("\nPor favor ingrese un servicio valido (L, A o G)");
    }
  }
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

void IngresarFacturacion(int empresas[], int empresasFacturacion[], int meses[], int maximo)
{
  printf("\n--------------- FACTURACIONES --------------");
  int validacion = 0;
  while (validacion == 0)
  {
    int codigo, mes, importe;
    printf("\nIngrese el codigo de la empresa: ");
    scanf("%d", &codigo);

    int codigoBuscado = BuscarCodigo(empresas, codigo, maximo);

    if (codigoBuscado == -1)
    {
      printf("\nEl codigo de la empresa no existe. Por favor ingresa un codigo valido");
    }
    else
    {

      // TODO: ingresar el mes
      // hacerlo dentro de un dowhile
      printf("\nIngrese el mes de la facturacion");
      scanf("%d", &mes);

      if (mes > 0 && mes < 13)
      {
        printf("\nEl mes es valido");
      }
      else
      {
        printf("\nEl mes no es valido");
      }

      // TODO: validar el mes

      // TODO: ingresar importe facturado
      // hacer la validacion
      printf("\nIngrese el importe de la facturacion");
      scanf("%d", &importe);
    }
  }
}
