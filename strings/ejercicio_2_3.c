#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_LONGITUD_NOMBRE 20

int main()
{
  char alumnos[MAX_ALUMNOS][MAX_LONGITUD_NOMBRE];
  int documentos[MAX_ALUMNOS];

  cargarInformacion(alumnos, documentos);

  buscarAlumnos(alumnos, documentos);

  ordenar(alumnos, MAX_ALUMNOS);

  mostrar(alumnos, MAX_ALUMNOS);

  return 0;
}

void cargarInformacion(char alumnos[][MAX_LONGITUD_NOMBRE], int documentos[])
{
  int contador = 0;

  while (contador < MAX_ALUMNOS)
  {
    // INGRESAR EL NOMBRE
    printf("\nIngrese el nombre: ");
    scanf("%s", alumnos[contador]);

    if (strcmp(alumnos[contador], "FIN") == 0)
    {
      break;
    }

    // INGRESAR EL DOCUMENTO
    printf("\nIngrese documento: ");
    scanf("%d", &documentos[contador]);

    contador++;
  }

  printf("\n-------------------------------------");
  printf("\nSe finalizo con la carga de alumnos");
  printf("\n-------------------------------------\n");
};

void buscarAlumnos(char alumnos[][MAX_LONGITUD_NOMBRE], int documentos[])
{
  int valido = 0;
  do
  {
    char abuscar[MAX_LONGITUD_NOMBRE];
    printf("\nIngrese el nombre del alumno a buscar: ");
    scanf("%s", abuscar);

    if (strcmp(abuscar, "NOBUSCARMAS") == 0)
    {
      valido++;
      break;
    }

    int nombreBuscado = buscar(alumnos, abuscar, MAX_ALUMNOS);

    if (nombreBuscado == -1)
    {
      printf("\nEl alumno ingresado no existe.\n");
    }
    else
    {
      printf("\nEl DNI del alumno es: %d \n", documentos[nombreBuscado]);
    }
  } while (valido == 0);
}

int buscar(char vector[][MAX_LONGITUD_NOMBRE], char buscado[], int cant)
{
  int i = 0, pos = -1;
  while (pos == -1 && i < cant)
  {
    if (strcmp(vector[i], buscado) == 0)
      pos = i;
    else
      i++;
  }
  return pos;
}

void ordenar(char vector[][MAX_LONGITUD_NOMBRE], int cant)
{
  int i, j;
  char aux[11];
  for (i = 0; i < cant - 1; i++)
  {
    for (j = 0; j < cant - 1 - i; j++)
    {
      if (strcmp(vector[j], vector[j + 1]) > 0)
      {
        strcpy(aux, vector[j]);
        strcpy(vector[j], vector[j + 1]);
        strcpy(vector[j + 1], aux);
      }
    }
  }
}

void mostrar(char vector[][MAX_LONGITUD_NOMBRE], int cant)
{
  int i;
  for (i = 0; i < cant; i++)
    puts(vector[i]);
}