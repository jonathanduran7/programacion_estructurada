#include <stdio.h>

int busqueda(int[], int, int);
void cargarSinDuplicados(int [], int);

int main()
{

  int vector[10] = {45, 7, 12, 64, 23, 14, 187, 165, 145, 187};
  // int valorBuscado = 1087;
  // int posicion = busqueda(vector, valorBuscado, 10);

  // if (posicion == -1)
  // {
  //   printf("\nEl valor %d no se encuentra", valorBuscado);
  // }
  // else
  // {
  //   printf("\nEl valor buscado %d se encuentra en la posicion %d", valorBuscado, posicion);
  // }

  int vectorNuevo[5];

  cargarSinDuplicados(vectorNuevo, 5);

  return 0;
}

int busqueda(int vector[], int datoABuscar, int cantElem)
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

void cargarSinDuplicados(int vector[], int cantElementos)
{
  int i, pos, aux;
  for (i = 0; i < cantElementos; i++)
  {
    do
    {
      printf("Ingrese un numero: ");
      scanf("%d", &aux);
      pos = busqueda(vector, aux, i);
      if (pos != -1)
      {
        printf("\nDato duplicado, por favor ingresa otro.\n");
      }
    } while (pos != -1);
    vector[i] = aux;
  }
}