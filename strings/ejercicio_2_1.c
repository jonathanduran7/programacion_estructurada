#include <stdio.h>
#include <string.h>

int main()
{

  char frase[500];
  printf("Escriba una frase: ");
  fgets(frase, 500, stdin);

  // LeerTextoUnEspacio(frase);
  LeerTextoMasDeUnEspacio(frase);

  return 0;
}

void LeerTextoUnEspacio(char frase[])
{
  int buscar = 0, contador = 0, palabras = 1;
  while (buscar == 0)
  {
    if (frase[contador] == ' ')
    {
      palabras++;
    }

    if (frase[contador] == '\0')
    {
      buscar++;
    }

    contador++;
  }

  printf("vueltas: %d \nPalabras: %d", contador, palabras);
}

void LeerTextoMasDeUnEspacio(char frase[])
{
  int valido = 0, contador = 0, palabras = 1, espacios = 0;
  while (valido == 0)
  {
    if (frase[contador] == ' ')
    {
      espacios++;
    }
    else
    {
      if (espacios > 0)
      {
        palabras++;
        espacios = 0;
      }
    }

    if (frase[contador] == '\0')
      valido++;

    contador++;
  }
  printf("En la frase hay %d palabras", palabras);
}