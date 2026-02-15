#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_PRODUCTOS 50

typedef struct {
    char codigo[6];
    float precio;
    char descripcion[30];
    int uniVendidas;
    float impTotal;
} PRODUCTO;

int cargarProductos(PRODUCTO productos[], int maxProductos);
void ingresarVentas(PRODUCTO productos[], int cantProductos);
void mostrarVentas(PRODUCTO productos[], int cantProductos);
int buscarProducto(PRODUCTO productos[], char codigo[], int cantProductos);

int main() {
    PRODUCTO productos[MAX_PRODUCTOS];
    int cantProductos;

    cantProductos = cargarProductos(productos, MAX_PRODUCTOS);
    ingresarVentas(productos, cantProductos);
    mostrarVentas(productos, cantProductos);

    return 0;
}

int cargarProductos(PRODUCTO productos[], int maxProductos) {
    int i = 0;
    char codigo[6];

    while (i < maxProductos) {
        printf("\nIngrese el codigo del producto: ");
        scanf("%5s", codigo);

        if (buscarProducto(productos, codigo, i) != -1) {
            printf("\nEl producto ya existe, por favor ingrese otro.\n");
            continue;
        }

        strcpy(productos[i].codigo, codigo);

        printf("\nIngrese el precio del producto: ");
        scanf("%f", &productos[i].precio);

        printf("\nIngrese la descripcion del producto: ");
        scanf("%29s", productos[i].descripcion);

        /* Pasar descripcion a mayusculas para comparar con "FIN" */
        for (int j = 0; productos[i].descripcion[j]; j++) {
            productos[i].descripcion[j] = (char) toupper((unsigned char) productos[i].descripcion[j]);
        }

        if (strcmp(productos[i].descripcion, "FIN") == 0) {
            break;
        }

        printf("\nIngrese la cantidad de unidades vendidas (mes anterior): ");
        scanf("%d", &productos[i].uniVendidas);

        productos[i].impTotal = productos[i].precio * productos[i].uniVendidas;

        i++;
    }
    return i;
}

int buscarProducto(PRODUCTO productos[], char codigo[], int cantProductos) {
    int i = 0, pos = -1;
    while (i < cantProductos && pos == -1) {
        if (strcmp(productos[i].codigo, codigo) == 0) {
            pos = i;
        }
        i++;
    }
    return pos;
}

void ingresarVentas(PRODUCTO productos[], int cantProductos) {
    char codigo[6];
    int cantidadVendida;

    printf("\n--- Ingreso de ventas del mes (cantidad 0 para finalizar) ---\n");

    do {
        printf("\nIngrese el codigo del producto: ");
        scanf("%5s", codigo);

        int codigoBuscado = buscarProducto(productos, codigo, cantProductos);
        if (codigoBuscado == -1) {
            printf("\nEl producto no existe, por favor ingrese otro.\n");
            continue;
        }

        printf("\nIngrese la cantidad pedida: ");
        scanf("%d", &cantidadVendida);

        if (cantidadVendida == 0) {
            break;
        }

        productos[codigoBuscado].uniVendidas += cantidadVendida;
        productos[codigoBuscado].impTotal = productos[codigoBuscado].precio * productos[codigoBuscado].uniVendidas;
    } while (1);
}

void mostrarVentas(PRODUCTO productos[], int cantProductos) {
    printf("\n---------------------- Listado de productos actualizado ----------------------\n");
    printf("%-30s %-25s %-20s\n", "DESCRIPCION", "CANTIDAD UNIDADES VENDIDAS", "IMPORTE TOTAL VENDIDO");
    printf("%-30s %-25s %-20s\n", "----------", "-------------------------", "---------------------");

    for (int i = 0; i < cantProductos; i++) {
        printf("%-30s %-25d $%.2f\n",
               productos[i].descripcion,
               productos[i].uniVendidas,
               productos[i].impTotal);
    }
}
