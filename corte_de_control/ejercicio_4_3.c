#include <stdio.h>
#include <stdlib.h>
#define LLAMADAS_FILE "LLAMADAS.dat"
#define COSTOS_FILE "COSTOS.dat"
#define GASTOS_FILE "GASTOS.dat"

struct LLAMADA
{
    char sector[15];
    int duracion;
    int tipoLLamada;
};

struct INFO_SECTOR
{
    char sector[15];
    int duracionTotal;
};

struct COSTOS
{
    float local;
    float largaDistancia;
    float celular;
};

struct GASTO_SECTOR
{
    char sector[15];
    int gastoTotal;
};

struct DETALLE_LLAMADA
{
    int duracion;
    int tipoLLamada;
    float costo;
};

int main()
{
        struct LLAMADA llamada;
        struct INFO_SECTOR infoSector;
        struct COSTOS costos;
        struct GASTO_SECTOR gastoSector;
        struct DETALLE_LLAMADA detalleLlamada;

        int llamadaUno, llamadaDos, llamadaTres;
        char sectorAnterior[15];
        FILE *llamada_file;
        FILE *costos_file;
        FILE *gastos_file;
        FILE *detalle_file;
        llamada_file = fopen(LLAMADAS_FILE, "rb");
        costos_file = fopen(COSTOS_FILE, "rb");
        gastos_file = fopen(GASTOS_FILE, "wb");

        if (llamada_file == NULL || costos_file == NULL)
        {
            printf("Error al abrir el archivo\n");
            exit(1);
        };

        fread(&costos, sizeof(struct COSTOS), 1, costos_file);
        while (!feof(costos_file))
        {
            printf("Costo local: %f\n", costos.local);
            printf("Costo larga distancia: %f\n", costos.largaDistancia);
            printf("Costo celular: %f\n", costos.celular);
            printf("\n");
            fread(&costos, sizeof(struct COSTOS), 1, costos_file);
        }

        fread(&costos, sizeof(struct COSTOS), 1, costos_file);
        fread(&llamada, sizeof(struct LLAMADA), 1, llamada_file);

        while (!feof(llamada_file))
        {
            char detalle_file_name[15];
            strcpy(detalle_file_name, llamada.sector);
            strcat(detalle_file_name, ".dat");
            printf("Nombre del archivo: %s\n", detalle_file_name);

            int duracionTotal = 0;
            int gastoTotal = 0;
            llamadaUno = 0;
            llamadaDos = 0;
            llamadaTres = 0;
            strcpy(sectorAnterior, llamada.sector);
            strcpy(infoSector.sector, llamada.sector);

            detalle_file = fopen(detalle_file_name, "wb");

            while ((!feof(llamada_file)) && (strcmp(sectorAnterior, llamada.sector) == 0))
            {
                duracionTotal += llamada.duracion;

                detalleLlamada.duracion = llamada.duracion;
                detalleLlamada.tipoLLamada = llamada.tipoLLamada;

                switch (llamada.tipoLLamada)
                {
                case 1:
                    llamadaUno++;
                    gastoTotal += llamada.duracion * costos.local;
                    detalleLlamada.costo = costos.local * llamada.duracion;
                    break;
                case 2:
                    llamadaDos++;
                    gastoTotal += llamada.duracion * costos.largaDistancia;
                    detalleLlamada.costo = costos.largaDistancia * llamada.duracion;
                    break;
                case 3:
                    llamadaTres++;
                    gastoTotal += llamada.duracion * costos.celular;
                    detalleLlamada.costo = costos.celular * llamada.duracion;
                    break;
                default:
                    break;
                }

                printf("Duracion: %d\n", detalleLlamada.duracion);
                printf("Tipo de llamada: %d\n", detalleLlamada.tipoLLamada);
                printf("Costo de la llamada: %f\n", detalleLlamada.costo);

                fread(&llamada, sizeof(struct LLAMADA), 1, llamada_file);
                fwrite(&detalleLlamada, sizeof(struct DETALLE_LLAMADA), 1, detalle_file);
            }

            printf("Sector: %s\n", sectorAnterior);
            printf("Llamada 1: %d\n", llamadaUno);
            printf("Llamada 2: %d\n", llamadaDos);
            printf("Llamada 3: %d\n", llamadaTres);
            printf("\n");

            gastoSector.gastoTotal = gastoTotal;
            strcpy(gastoSector.sector, sectorAnterior);

            fwrite(&gastoSector, sizeof(struct GASTO_SECTOR), 1, gastos_file);

            if (duracionTotal > infoSector.duracionTotal)
            {
                infoSector.duracionTotal = duracionTotal;
                strcpy(infoSector.sector, sectorAnterior);
            }

            printf("\n");
        };

        printf("Sector con mas duracion total: %s\n con %d minutos", infoSector.sector, infoSector.duracionTotal);

        fclose(llamada_file);
        fclose(costos_file);
        fclose(gastos_file);
        fclose(detalle_file);

        VerGastos();
    return 0;
}

void VerGastos()
{
    FILE *gastos_file;
    struct GASTO_SECTOR gastoSector;

    gastos_file = fopen(GASTOS_FILE, "rb");

    if (gastos_file == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    };

    fread(&gastoSector, sizeof(struct GASTO_SECTOR), 1, gastos_file);

    while (!feof(gastos_file))
    {
        printf("Sector: %s\n", gastoSector.sector);
        printf("Gasto total: %d\n", gastoSector.gastoTotal);
        printf("\n");
        fread(&gastoSector, sizeof(struct GASTO_SECTOR), 1, gastos_file);
    }
}

void VerDetalles()
{
    FILE *detalle_file;
    struct DETALLE_LLAMADA detalleLlamada;
    char files_name[4][15];

    strcpy(files_name[0], "ADMIN.dat");
    strcpy(files_name[1], "COMPRAS.dat");
    strcpy(files_name[2], "STOCK.dat");
    strcpy(files_name[3], "VENTAS.dat");

    for (int i = 0; i < 4; i++)
    {
        printf("Nombre del archivo: %s\n\n", files_name[i]);
        detalle_file = fopen(files_name[i], "rb");

        if (detalle_file == NULL)
        {
            printf("Error al abrir el archivo\n");
            exit(1);
        };

        fread(&detalleLlamada, sizeof(struct DETALLE_LLAMADA), 1, detalle_file);

        while (!feof(detalle_file))
        {
            printf("Duracion: %d\n", detalleLlamada.duracion);
            printf("Tipo de llamada: %d\n", detalleLlamada.tipoLLamada);
            printf("Costo de la llamada: %f\n", detalleLlamada.costo);
            printf("\n");
            fread(&detalleLlamada, sizeof(struct DETALLE_LLAMADA), 1, detalle_file);
        }

        fclose(detalle_file);
        printf("------------------\n");
    }
}