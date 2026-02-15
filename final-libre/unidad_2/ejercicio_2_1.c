#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PRODUCTOS 5

typedef struct {
    char codigo[5];
    float precio;
    char descripcion[30];
    int uniVendidas;
    float impTotal;
}PRODUCTO;

void cargarProductos(PRODUCTO productos[], int maxProductos);
void ingresarVentas(PRODUCTO productos[]);
void mostrarVentas(PRODUCTO productos[]);
int buscarProducto(PRODUCTO productos[], char codigo[]);

int main() {
    PRODUCTO productos[MAX_PRODUCTOS];

    cargarProductos(productos, MAX_PRODUCTOS);
    ingresarVentas(productos);
    mostrarVentas(productos);

    return 0;
}

void cargarProductos(PRODUCTO productos[], int maxProductos) {
    int i = 0;
    while ( i < maxProductos || strcmp(productos[i].descripcion, "FIN") != 0) {
        printf("\nIngrese el codigo del producto: ");
        char codigo[5];
        scanf("%s", codigo);

        int codigoBuscado = buscarProducto(productos, codigo);
        if (codigoBuscado != -1) {
            printf("\nEl producto ya existe por favor ingrese otro");
            continue;
        }

        strcpy(productos[i].codigo, codigo); 

        printf("\nIngrese el precio del producto: ");
        scanf("%f", &productos[i].precio);

        printf("\nIngrese la descripcion del producto: ");
        scanf("%s", productos[i].descripcion);

        if (strcmp(productos[i].descripcion, "FIN") == 0) {
            break;
        }

        printf("\nIngrese la cantidad de unidades vendidas: ");
        scanf("%d", &productos[i].uniVendidas);

        productos[i].impTotal = productos[i].precio * productos[i].uniVendidas;

        i++;
    }
}

int buscarProducto(PRODUCTO productos[], char codigo[]) {
    int i = 0, pos = -1;
    while(i < MAX_PRODUCTOS && pos == -1) {
        if (strcmp(productos[i].codigo, codigo) == 0) {
            pos = i;
        }
        i++;
    }
    return pos;
}

void ingresarVentas(PRODUCTO productos[]) {
    printf("\nIngrese las ventas del mes actual");
    char codigo[5];
    int cantidadVendida;
    do {
        printf("\nIngrese el codigo del producto: ");
        scanf("%s", codigo);

        int codigoBuscado = buscarProducto(productos, codigo);
        if (codigoBuscado == -1) {
            printf("\nEl producto no existe por favor ingrese otro");
            continue;
        }

        printf("\nIngrese la cantidad de unidades vendidas: ");
        scanf("%d", &cantidadVendida);

        if (cantidadVendida == 0) {
            continue;
        }

        productos[codigoBuscado].uniVendidas += cantidadVendida;
        productos[codigoBuscado].impTotal = productos[codigoBuscado].precio * productos[codigoBuscado].uniVendidas;
    } while (cantidadVendida != 0);
}

void mostrarVentas(PRODUCTO productos[]) {
    printf("\n---------------------- Ventas del mes actual ------------------------\n");
    printf("%-20s %-12s %-12s\n", "Descripcion", "CantVendidas", "Total");
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        if (strcmp(productos[i].descripcion, "FIN") != 0 && productos[i].impTotal > 0) {
            printf("%-20s %-12d %-12f\n", productos[i].descripcion, productos[i].uniVendidas, productos[i].impTotal);
        }
    }
}