/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CTemplate.c to edit this template
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 10

typedef struct {
    int size;
    bool isFree;
} Partition;

void printPartitions(Partition partitions[], int partitionCount) {
    printf("\nEstado de las particiones:\n");
    for (int i = 0; i < partitionCount; i++) {
        printf("Partición %d: Tamaño = %d, Estado = %s\n", 
               i + 1, 
               partitions[i].size, 
               partitions[i].isFree ? "Libre" : "Ocupada");
    }
    printf("\n");
}

void assignProcess(Partition partitions[], int partitionCount) {
    int processSize;
    printf("\nTamaño del proceso a asignar: ");
    scanf("%d", &processSize);

    for (int i = 0; i < partitionCount; i++) {
        if (partitions[i].isFree && partitions[i].size >= processSize) {
            partitions[i].isFree = false;
            printf("Proceso asignado a la partición %d.\n", i + 1);
            return;
        }
    }
    printf("No hay partición disponible para el proceso.\n");
}

void releasePartition(Partition partitions[], int partitionCount) {
    int partitionNumber;
    printf("\nNúmero de partición a liberar: ");
    scanf("%d", &partitionNumber);

    if (partitionNumber < 1 || partitionNumber > partitionCount) {
        printf("Número de partición inválido.\n");
        return;
    }

    if (!partitions[partitionNumber - 1].isFree) {
        partitions[partitionNumber - 1].isFree = true;
        printf("Partición %d liberada.\n", partitionNumber);
    } else {
        printf("La partición %d ya está libre.\n", partitionNumber);
    }
}

int main() {
    Partition partitions[MAX_PARTITIONS];
    int partitionCount;

    printf("Ingrese el número de particiones: ");
    scanf("%d", &partitionCount);

    if (partitionCount > MAX_PARTITIONS || partitionCount <= 0) {
        printf("Número inválido de particiones. Debe estar entre 1 y %d.\n", MAX_PARTITIONS);
        return 1;
    }

    for (int i = 0; i < partitionCount; i++) {
        printf("Tamaño de la partición %d: ", i + 1);
        scanf("%d", &partitions[i].size);
        partitions[i].isFree = true;
    }

    int option;
    do {
        printf("\n--- Administrador de Memoria ---\n");
        printf("1. Ver particiones\n");
        printf("2. Asignar proceso\n");
        printf("3. Liberar partición\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printPartitions(partitions, partitionCount);
                break;
            case 2:
                assignProcess(partitions, partitionCount);
                break;
            case 3:
                releasePartition(partitions, partitionCount);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 4);

    return 0;
}

