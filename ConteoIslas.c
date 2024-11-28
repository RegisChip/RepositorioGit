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
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
	imprimir(mat);
	getch();
	return 0;
}

