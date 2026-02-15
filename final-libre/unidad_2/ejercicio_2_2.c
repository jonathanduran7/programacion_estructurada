#include <stdio.h>
#define CANT_MEDICAMENTOS 5

struct MEDICAMENTOS {
    int codigo;
    float precio;
    int stock;
};

void INGRESO(struct MEDICAMENTOS medicamentos[], int limite);
int BUSQUEDA_MEDI(struct MEDICAMENTOS medicamentos[], int codigo, int limite);
void INFORME(struct MEDICAMENTOS medicamentos[], int limite);

int main() {
    struct MEDICAMENTOS medicamentos[CANT_MEDICAMENTOS];

    INGRESO(medicamentos, CANT_MEDICAMENTOS);

    int codigo;
    printf("Ingrese el codigo del medicamento: ");
    scanf("%d", &codigo);
    while (codigo != 0) {
        int x = BUSQUEDA_MEDI(medicamentos, codigo, CANT_MEDICAMENTOS);
        if (x != -1) {
            printf("El precio del medicamento es: %f", medicamentos[x].precio);
        } else {
            printf("El medicamento no existe");
        }
        printf("Ingrese el codigo del medicamento: ");
        scanf("%d", &codigo);
    }

    INFORME(medicamentos, CANT_MEDICAMENTOS);
}

void INGRESO(struct MEDICAMENTOS medicamentos[], int limite) {
    for (int i = 0; i < limite; i++) {
        printf("Ingrese el codigo del medicamento: ");
        scanf("%d", &medicamentos[i].codigo);

        printf("Ingrese el precio del medicamento: ");
        scanf("%f", &medicamentos[i].precio);

        printf("Ingrese el stock del medicamento: ");
        scanf("%d", &medicamentos[i].stock);
    }
}

int BUSQUEDA_MEDI(struct MEDICAMENTOS medicamentos[], int codigo, int limite) {
    for (int i = 0; i < limite; i++) {
        if (medicamentos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void INFORME(struct MEDICAMENTOS medicamentos[], int limite) {
    for (int i = 0; i < limite; i++) {
        if (medicamentos[i].stock < 10) {
            printf("El medicamento %d tiene stock bajo", medicamentos[i].codigo);
        }
    }
}