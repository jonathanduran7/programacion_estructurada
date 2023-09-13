#include <stdio.h>

struct MEDICAMENTO
{
  int codigo;
  float precio;
  int stock;
};

void Ingreso(struct medicamento[], int);
int Busqueda(struct medicamento[], int, int);
void Informe(struct medicamento[], int);

int main()
{

  int codigo, x;
  struct MEDICAMENTO vec[50];

  Ingreso(vec, 50);
  printf("Codigo a buscar: ");
  scanf("%d", &codigo);
  x = Busqueda(vec, codigo, 50);

  if (x != -1)
  {
    printf("El precio del codigo es %d es %f", vec[x].codigo, vec[x].precio);
  }
  else
  {
    printf("Codigo inexistente");
  }

  Informe(vec, 50);

  return 0;
}

void Ingreso(struct MEDICAMENTO vector[], int n)
{
  int i;
  for ( i = 0; i < n; i++)
  {
    printf("Codigo: ");
    scanf("%d", &vector[i].codigo);

    printf("Ingrese precio: ");
    scanf("%f", &vector[i].precio);

    printf("Ingrese stock: ");
    scanf("%d", &vector[i].stock);
  }
}

int Busqueda(struct MEDICAMENTO vector[], int codigoIngresado, int limite){
  int i, pos;
  i = 0; pos = -1;
  while (i < limite && pos == -1)
  {
    if(codigoIngresado == vector[i].codigo)
      pos = i;
    else
      i++;
  }
  return pos;
}

void Informe(struct MEDICAMENTO vector[], int limite){
  int i;
  for ( i = 0; i < limite; i++)
  {
    if(vector[i].stock < 0)
      printf("%d", vector[i].codigo);
  }

}