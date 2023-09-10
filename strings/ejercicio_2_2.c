#include <stdio.h>
#include <string.h>

int main() {
  char apellido[20];
  char nombre[20];

  printf("Escriba su nombre: ");
  fgets(nombre, 20, stdin);

  printf("Escriba su apellido: ");
  fgets(apellido, 20, stdin);

  char nombre_completo[40];
  strcat(nombre_completo, nombre);
  strcat(nombre_completo, apellido);

  puts(nombre_completo);
  return 0;
}