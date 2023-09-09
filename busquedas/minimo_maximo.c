#include <stdio.h>

void mostrarMaximo(int [], int);

int main()
{

  int vector[10] = {23, 13, 8, 10, 6, 2, 21, 3, 11, 5};

  mostrarMaximo(vector, 10);
  mostrarMinimo(vector,10);

  return 0;
}

void mostrarMaximo(int vector[], int cantidad){
  int maximo = vector[0];
  for(int i = 0; i < cantidad; i++){
    if(vector[i] > maximo){
      maximo = vector[i];
    }
  }
  printf("El maximo dentro del vector es %d", maximo);
}

void mostrarMinimo(int vector[], int cantidad){
  int minimo = vector[0];
  for(int i = 0; i < cantidad; i++){
    if(vector[i] < minimo){
      minimo = vector[i];
    }
  }
  printf("\nEl minimo dentro del vector es %d", minimo);
}
