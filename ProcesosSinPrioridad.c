/*
 * prioridad.c
 * 
 * Copyright 2024 pirof <pirof@GLADOS>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nodo {
    int valor;
    //int prioridad;
    struct _nodo *siguiente;
} nodo;

int numero_aleatorio() {
    return (rand() % 4) + 1;
}

nodo* genera_proceso() {
    static int contador = 1;
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->valor = contador++;
    //nuevo->prioridad = numero_aleatorio();
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertar_final(nodo** cabeza) {
    nodo* nuevoNodo = genera_proceso();

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void imprimir_lista(nodo* cabeza) {
    nodo* temp = cabeza;
    while (temp != NULL) {
        printf("Proceso %d -> ", temp->valor /*, temp->prioridad*/);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void atender_prioridad_mas_alta(nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("No hay procesos para atender.\n");
        return;
    }

    nodo* temp = *cabeza;
    nodo* maxNodo = temp;
    nodo* maxNodoPrevio = NULL;
    nodo* previo = NULL;

    // Buscar el nodo con la prioridad más alta
    while (temp != NULL) {
        if (temp->valor > maxNodo->valor) {
            maxNodo = temp;
            maxNodoPrevio = previo;
        }
        previo = temp;
        temp = temp->siguiente;
    }

    // Atender el nodo con prioridad más alta
    printf("Atendiendo proceso %d\n", maxNodo->valor /*, maxNodo->prioridad*/);

    // Eliminar el nodo de la lista
    if (maxNodoPrevio == NULL) {
        *cabeza = maxNodo->siguiente;  // El nodo con mayor prioridad es la cabeza
    } else {
        maxNodoPrevio->siguiente = maxNodo->siguiente;
    }

    free(maxNodo);
}

int main(){
	
	srand(time(NULL));
    nodo* cabeza = NULL;
    int op = 0;

    do {
        printf("1. Genera proceso\n");
        printf("2. Atiende proceso\n");
        printf("3. Mostrar Lista de Procesos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insertar_final(&cabeza);
                break;
            case 2:
                atender_prioridad_mas_alta(&cabeza);
                break;
            case 3:
                imprimir_lista(cabeza);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (op != 4);
    
	return 0;
}

