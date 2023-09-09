#include <stdio.h>

void mostrarNotas(int[], int[], int);
int cargarNota();
int BuscarDocumentos(int[], int, int);
void ordenarNotas(int[], int[], int);
void cargarDocumento(int[], int[], int);

int main()
{
  int maximo = 5;
  int documentos[maximo];
  int notas[maximo];

  cargarDocumento(documentos, notas, maximo);
  ordenarNotas(notas, documentos, maximo);
  mostrarNotas(documentos, notas, maximo);
  return 0;
}

void cargarDocumento(int documentos[], int notas[], int maximo)
{
  int validacion = 0, vuelta = 0;
  do
  {
    printf("\nVuelta: %d validacion: %d", vuelta, validacion);
    int dni;
    printf("\nIngrese un DNI: ");
    scanf("%d", &dni);

    if (dni < 0)
    {
      printf("\nEl dni es negativo, el programa a finalizado");
      validacion++;
    }
    else
    {
      int documentoBuscado = BuscarDocumentos(documentos, dni, maximo);
      if (documentoBuscado == -1)
      {
        documentos[vuelta] = dni;
        notas[vuelta] = cargarNota();
        vuelta++;
      }
      else
      {
        printf("\nEl DNI ingresado ya se encuentra cargado");
      }
    }

  } while (validacion == 0 && vuelta < maximo);
}

int cargarNota()
{

  int nota;
  do
  {
    printf("\nIngrese la nota del parcial");
    scanf("%d", &nota);

    if (nota < 0)
    {
      printf("\nPor favor ingrese una nota correcta");
    }

  } while (nota < 0);

  return nota;
}

int BuscarDocumentos(int vector[], int datoABuscar, int cantElem)
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

void mostrarNotas(int documentos[], int notas[], int maximo)
{
  int vuelta = 0, validacion = 0;
  do
  {
    printf("\nEl DNI: %d tuvo la nota %d", documentos[vuelta], notas[vuelta]);
    vuelta++;
  } while (validacion == 0 && vuelta < maximo);
}

void ordenarNotas(int notas[], int documentos[], int cantElementos)
{
  int i, j, aux, auxDocumento;

  for (i = 0; i < cantElementos - 1; i++)
  {
    for (j = 0; j < cantElementos - 1 - i; j++)
    {
      if (notas[j] <= notas[j + 1])
      {
        aux = notas[j];
        auxDocumento = documentos[j];

        notas[j] = notas[j + 1];
        notas[j + 1] = aux;

        documentos[j] = documentos[j + 1];
        documentos[j + 1] = auxDocumento;
      }
    }
  }
}