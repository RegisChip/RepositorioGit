/*
 * ConteoIslas.c
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
#include <conio.h>

// algoritmo DFS

#define FILAS 6
#define COLUMNAS 8

/*
void cargar(int mat[6][8])
{
	int f, c;
	for(f = 0; f < 6; f++)
	{
		for(c = 0; c < 8; c++)
		{
			printf("Ingrese componente:");
            scanf("%i",&mat[f][c]);
		}
	}
}
*/

int esValido(int mat[FILAS][COLUMNAS], int fila, int col)
{
    return (fila >= 0 && fila < FILAS && col >= 0 && col < COLUMNAS && mat[fila][col] == 1);
}

void marcarIsla(int mat[FILAS][COLUMNAS], int fila, int col)
{
    int direccionFila[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int direccionColumna[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    mat[fila][col] = 0;

    for (int i = 0; i < 8; i++)
    {
        int nuevaFila = fila + direccionFila[i];
        int nuevaColumna = col + direccionColumna[i];

        if(esValido(mat, nuevaFila, nuevaColumna))
        {
            marcarIsla(mat, nuevaFila, nuevaColumna);
        }
    }
}

int contarIslas(int mat[FILAS][COLUMNAS])
{
    int numIslas = 0;

    for(int f = 0; f < FILAS; f++){
        for(int c = 0; c < COLUMNAS; c++)
        {
            if(mat[f][c] == 1)
            {
                marcarIsla(mat, f, c);
                numIslas++;
            }
        }
    }

    return numIslas;

}

void imprimir(int mat[6][8])
{
    int f,c;
    for(f = 0; f < 6; f++)
    {
        for(c = 0; c < 8; c++)
        {
            printf("%i ",mat[f][c]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
	//int mat[6][8];
	int mat[6][8] = {
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0}
    };
	imprimir(mat);

    int numIslas = contarIslas(mat);
    printf("Numero de islas: %d", numIslas);
	getch();
	return 0;
}

