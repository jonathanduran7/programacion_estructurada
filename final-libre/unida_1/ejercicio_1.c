/*
1.1.1 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa mediante
la función IngresaCódigos.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>

int IngresaCodigo();
int BuscarProducto(int[], int, int);
int ValidarCantidad(int);

int main()
{
    int productos[10];
    int unidades[10];
    int codProd, cantidad; 

    // Inicializar unidades en 0
    for (int i = 0; i < 10; i++)
        unidades[i] = 0;

    // CARGA DE PRODUCTOS
    for (int i = 0; i < 10; i++) {
        printf("\nCarga el producto numero %d: ", i + 1);
        productos[i] = IngresaCodigo();
    }

    // CARGA DE PEDIDOS
    printf("\n======= CARGA DE PEDIDOS ======\n");
    printf("(Ingrese codigo 0 para finalizar)\n");

    do {
        printf("\nIngrese el codigo del producto: ");
        scanf("%d", &codProd);

        if (codProd == 0)
            break;

        int indice = BuscarProducto(productos, codProd, 10);
        while (indice == -1) {
            printf("Codigo no valido. Ingrese el codigo del producto (0 para terminar): ");
            scanf("%d", &codProd);
            if (codProd == 0)
                break;
            indice = BuscarProducto(productos, codProd, 10);
        }
        if (codProd == 0)
            break;

        printf("Ingrese la cantidad de unidades: ");
        scanf("%d", &cantidad);
        cantidad = ValidarCantidad(cantidad);

        unidades[indice] += cantidad;

    } while (1);

    // a) Listado con codigo y cantidad por producto
    printf("\n======= LISTADO DE PEDIDOS ======\n");
    printf("%-10s %s\n", "Codigo", "Unidades");
    for (int i = 0; i < 10; i++)
        printf("%-10d %d\n", productos[i], unidades[i]);

    // b) y c) Mayor y menor cantidad
    int maxUnid = unidades[0], minUnid = unidades[0];
    for (int i = 1; i < 10; i++) {
        if (unidades[i] > maxUnid) maxUnid = unidades[i];
        if (unidades[i] < minUnid) minUnid = unidades[i];
    }

    printf("\nProducto(s) con MAYOR cantidad solicitada (%d unidades):\n", maxUnid);
    for (int i = 0; i < 10; i++)
        if (unidades[i] == maxUnid)
            printf("  Codigo %d\n", productos[i]);

    printf("\nProducto(s) con MENOR cantidad solicitada (%d unidades):\n", minUnid);
    for (int i = 0; i < 10; i++)
        if (unidades[i] == minUnid)
            printf("  Codigo %d\n", productos[i]);

    return 0;
}

int IngresaCodigo(){
    int codigo;
    printf("\nIngresa el codigo (1-9999): ");
    scanf("%d", &codigo);
    while (codigo < 1 || codigo > 9999) {
        printf("Por favor ingresa un codigo entre 1 y 9999: ");
        scanf("%d", &codigo);
    }
    return codigo;
}

/* Devuelve el indice del producto si existe, -1 si no. */
int BuscarProducto(int productos[], int cod, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (productos[i] == cod)
            return i;
    return -1;
}

int ValidarCantidad(int num) {
    int cantidad = num;
    while (cantidad < 1) {
        printf("Por favor ingrese un numero positivo: ");
        scanf("%d", &cantidad);
    }
    return cantidad;
}