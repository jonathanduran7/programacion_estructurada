#include <stdio.h>
#include <string.h>

int main() {

  char frase[500];
  printf("Escriba una frase: ");
  fgets(frase,500,stdin);

  puts(frase);

  printf("la frase tiene %d palabras", strlen(frase));
  return 0;
}