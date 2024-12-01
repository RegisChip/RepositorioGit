/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cpplite/CTemplate.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAGE_SIZE 4    // Tamaño de página (4 KB)
#define FRAME_COUNT 8  // Número de marcos de memoria disponibles
#define MAX_PAGES 16   // Número máximo de páginas en un proceso

typedef struct {
    int pageNumber; // Número de página
    int frameNumber; // Número de marco asignado (-1 si no está asignado)
} PageTableEntry;

void initializePageTable(PageTableEntry pageTable[], int pageCount) {
    for (int i = 0; i < pageCount; i++) {
        pageTable[i].pageNumber = i;
        pageTable[i].frameNumber = -1; // Sin asignar inicialmente
    }
}

void assignFrames(PageTableEntry pageTable[], int pageCount) {
    int assignedFrames[FRAME_COUNT] = {0}; // Rastrea los marcos asignados
    for (int i = 0; i < pageCount; i++) {
        int frame;
        do {
            frame = rand() % FRAME_COUNT; // Seleccionar un marco aleatorio
        } while (assignedFrames[frame] == 1); // Asegurar que no esté ocupado

        pageTable[i].frameNumber = frame; // Asignar el marco
        assignedFrames[frame] = 1; // Marcar el marco como ocupado
    }
}

void printPageTable(PageTableEntry pageTable[], int pageCount) {
    printf("\nTabla de Paginas:\n");
    printf("Pagina\tMarco\n");
    for (int i = 0; i < pageCount; i++) {
        printf("%d\t%d\n", pageTable[i].pageNumber, pageTable[i].frameNumber);
    }
}

void accessMemory(PageTableEntry pageTable[], int pageCount) {
    int virtualAddress;
    printf("\nIngrese una direccion virtual (en KB): ");
    scanf("%d", &virtualAddress);

    int pageNumber = virtualAddress / PAGE_SIZE; // Página correspondiente
    int offset = virtualAddress % PAGE_SIZE;    // Desplazamiento dentro de la página

    if (pageNumber >= pageCount) {
        printf("Direccion virtual fuera de rango. (Pagina %d no existe)\n", pageNumber);
    } else if (pageTable[pageNumber].frameNumber == -1) {
        printf("Fallo de pagina. Pagina %d no esta cargada en memoria.\n", pageNumber);
    } else {
        int frameNumber = pageTable[pageNumber].frameNumber;
        int physicalAddress = frameNumber * PAGE_SIZE + offset; // Dirección física
        printf("Direccion virtual %d KB -> Direccion fisica %d KB (Pagina %d, Marco %d, Desplazamiento %d)\n",
               virtualAddress, physicalAddress, pageNumber, frameNumber, offset);
    }
}

int main() {
    srand(time(NULL)); // Inicializar generador de números aleatorios

    PageTableEntry pageTable[MAX_PAGES];
    int pageCount;

    printf("Ingrese el numero de paginas del proceso (maximo %d): ", MAX_PAGES);
    scanf("%d", &pageCount);
    if (pageCount <= 0 || pageCount > MAX_PAGES) {
        printf("Numero de paginas invalido.\n");
        return 1;
    }

    initializePageTable(pageTable, pageCount);
    assignFrames(pageTable, pageCount);
    printPageTable(pageTable, pageCount);

    char choice;
    do {
        accessMemory(pageTable, pageCount);
        printf("\n¿Desea acceder a otra direccion? (s/n): ");
        scanf(" %c", &choice);
    } while (choice == 's' || choice == 'S');

    printf("Saliendo de la simulacion.\n");
    return 0;
}
