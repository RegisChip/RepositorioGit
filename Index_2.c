/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CTemplate.c to edit this template
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 20
#define MAX_PROCESSES 20

void firstFit(int partitions[], bool isFree[], int partitionCount, int processes[], int processCount) {
    for (int i = 0; i < processCount; i++) {
        bool assigned = false;
        for (int j = 0; j < partitionCount; j++) {
            if (isFree[j] && partitions[j] >= processes[i]) {
                printf("Proceso %d (tamanio %d) asignado a particion %d (tamanio %d).\n", 
                        i + 1, processes[i], j + 1, partitions[j]);
                isFree[j] = false; // Marcar partición como ocupada
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            printf("Proceso %d (tamanio %d) no puede ser asignado.\n", i + 1, processes[i]);
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS], processes[MAX_PROCESSES];
    bool isFree[MAX_PARTITIONS];
    int partitionCount, processCount;

    // Entrada de particiones
    printf("Ingrese el numero de particiones: ");
    scanf("%d", &partitionCount);
    if (partitionCount > MAX_PARTITIONS || partitionCount <= 0) {
        printf("Numero invalido de particiones.\n");
        return 1;
    }

    for (int i = 0; i < partitionCount; i++) {
        printf("Tamanio de la particion %d: ", i + 1);
        scanf("%d", &partitions[i]);
        isFree[i] = true; // Todas las particiones comienzan libres
    }

    // Entrada de procesos
    printf("\nIngrese el numero de procesos: ");
    scanf("%d", &processCount);
    if (processCount > MAX_PROCESSES || processCount <= 0) {
        printf("Numero invalido de procesos.\n");
        return 1;
    }

    for (int i = 0; i < processCount; i++) {
        printf("Tamanio del proceso %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Asignación de procesos usando First Fit
    printf("\n--- Asignacion de procesos ---\n");
    firstFit(partitions, isFree, partitionCount, processes, processCount);

    return 0;
}

