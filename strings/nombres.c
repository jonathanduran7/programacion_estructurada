#include <stdio.h>

int main() {

  char nombre[20];

  printf("Ingrese un nombre: ");
  // gets(nombre);
  fgets(nombre,20,stdin);
  scanf("%s",nombre);
  printf("El nombre ingresado es %s",nombre);

  return 0;
}