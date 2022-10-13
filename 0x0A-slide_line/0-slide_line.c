#include "slide_line.h"
#define LINE_SIZE   32
/**
*left_direction - a given line slided & merged to the left
*@line: points to an array of integers
*@size: size of array
**/
void left_direction(int *line, size_t size)
{
size_t x, i = 0, h;
int y = 0, z;
int arr[LINE_SIZE], arr2[LINE_SIZE];
for (x = 0; x < size; x++)
{
	if (line[x] != 0)
	{
		arr[y] = line[x];
		y++;
	}
}
for (z = 0; z < y; z += 1)
{
	if (arr[z] == arr[z + 1])
	{
		arr2[i] = arr[z] + arr[z + 1];
		z++;
		i++;
	}
	else
	{
		arr2[i] = arr[z];
		i++;
	}
}
for (h = 0; h < size; h++)
{
	if (h < i)
		line[h] = arr2[h];
	else
		line[h] = 0;
}
}
/**
*right_direction - a given line slided & merged to the right
*@line: points to an array of integers
*@size: size of array
**/
void right_direction(int *line, size_t size)
{
size_t  i = 0, c = 0;
int y = 0, z, h, x;
int arr[LINE_SIZE], arr2[LINE_SIZE];
for (x = size - 1; x > -1; x--)
{
	if (line[x] != 0)
	{
		arr[y] = line[x];
		y++;
	}
}
for (z = 0; z < y; z += 1)
{
	if (arr[z] == arr[z + 1])
	{
		arr2[i] = arr[z] + arr[z + 1];
		z++;
		i++;
	}
	else
	{
		arr2[i] = arr[z];
		i++;
	}
}
for (h = size - 1; h > -1; h--)
{
	if (c < i)
	{
		line[h] = arr2[c];
		c++;
	}
	else
		line[h] = 0;
}
}
/**
*slide_line - slide & merge an array of integers to the left or to the right
*@line: points to an array of integers
*@size: size of array
*@direction: the direction can be either right or left
*Return: 1 or 0
**/
int slide_line(int *line, size_t size, int direction)
{
if (direction == SLIDE_LEFT)
{
	left_direction(line, size);
	return (1);
}
else if (direction == SLIDE_RIGHT)
{
	right_direction(line, size);
	return (1);
}
return (0);
}
