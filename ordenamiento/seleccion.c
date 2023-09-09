#include <stdio.h>

void OrdenSeleccion(int[],int);
int ValorMinimo(int[],int,int);
void mostrarVector(int[],int);

int main()
{
  int vector[5] = {5,7,2,6,9};

  OrdenSeleccion(vector,5);
  mostrarVector(vector,5);

  return 0;
}

void OrdenSeleccion(int vector[], int  cantElem)
{
  int posMin,i,aux;
  for(i = 0; i < cantElem - 1; i++){
    posMin = ValorMinimo(vector,i,cantElem);
    if(posMin!=i)
    {
      aux = vector[i];
      vector[i] = vector[posMin];
      vector[posMin] = aux;
    }
  }
}

int ValorMinimo(int vector[],int ini, int tam)
{
  int i, posMin;
  posMin = ini;

  for(i = ini+1;i<tam;i++)
  {
    if(vector[i] < vector[posMin])
    {
      posMin = i;
    }
  }
  return posMin;
}

void mostrarVector(int vector[], int cantElementos)
{
  for(int i = 0; i < cantElementos; i++)
  {
    printf("%d ", vector[i]);
  }
}
