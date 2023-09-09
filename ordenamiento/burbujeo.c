#include <stdio.h>

void OrdenBurbujeo(int[],int);
void MostrarVector(int[],int);

int main()
{

  int vector[5] = {5,2,9,1,7};

  OrdenBurbujeo(vector,5);
  MostrarVector(vector,5);

  return 0;
}

void OrdenBurbujeo(int vector[], int cantElementos)
{
  int i, j, aux;

  for (i = 0; i < cantElementos - 1; i++)
  {
    for (j = 0; j < cantElementos - 1 - i; j++)
    {
      if (vector[j] >= vector[j + 1])
      {
        aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
}

void MostrarVector(int vector[], int cantElementos)
{
  for(int i = 0; i < cantElementos; i++)
  {
    printf("%d ", vector[i]);
  }
}
