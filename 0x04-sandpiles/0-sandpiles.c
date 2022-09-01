#include "sandpiles.h"
#include <stdio.h>
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * check_grid_stability - checks if a grid is stable or not
 * @grid: 3x3 grid
 *Return: 1 or 0
 */
int check_grid_stability(int grid[3][3])
{
int m = 0;
int k = 0;
int n;
while (m < 3)
	{
	n = 0;
	while (n < 3)
		{
		if (grid[m][n] > 3)
			k = 1;
		n++;
		}
	m++;
		}
return (k);
}
/**
 * grid_sum - computes the sum of two grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
int x = 0;
int y;

while (x < 3)
	{
	y = 0;
	while (y < 3)
		{
		grid1[x][y] = grid1[x][y] + grid2[x][y];
		y++;
		}
		x++;
	}
}
/**
 * sandpiles_calc - sandpiles things
 * @grid1: 3x3 grid
 *
 */
void sandpiles_calc(int grid1[3][3])
{
int i, j, f;

i = 0;
while (i < 3)
	{
	j = 0;
	while (j < 3)
		{
		if (grid1[i][j] > 3)
			{
			f = 0;
			if (grid1[i][j + 1] <= 3)
				f = 1;
			grid1[i][j] = grid1[i][j] - 4;
			if (j != 2)
				grid1[i][j + 1] = grid1[i][j + 1] + 1;
			if (j != 0)
				grid1[i][j - 1]	= grid1[i][j - 1] + 1;
			if (i != 2)
				grid1[i + 1][j] = grid1[i + 1][j] + 1;
			if (i != 0)
				grid1[i - 1][j]	= grid1[i - 1][j] + 1;
			if (f == 1)
				j++;
			}
		j++;
		}
	i++;
	}
}
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
grid_sum(grid1, grid2);
	if (check_grid_stability(grid1) == 1)
	{
	while (0 < 1)
	{
		printf("=\n");
		print_grid(grid1);
		sandpiles_calc(grid1);
		if (check_grid_stability(grid1) == 0)
			break;
	}
}
}
