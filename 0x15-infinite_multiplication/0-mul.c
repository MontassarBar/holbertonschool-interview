#include "holberton.h"
#include <stdlib.h>

/**
 * _malloc - allocates memory for an array and initializes it
 *
 * @num: the array
 * @size: tthe size of array
 * Return: the allocated array
 */
int *_malloc(int *num, int size)
{
	int x;

	num = malloc(sizeof(int) * size);
	if (!num)
	{
		error();
		exit(98);
	}
	for (x = 0; x < size; x++)
	{
		num[x] = 0;
	}
	return (num);
}

/**
 * to_array - fills an array
 *
 * @array: the array to be filled
 * @str: the content of array
 */
void to_array(int *array, char *str)
{
	int x;

	for (x = 0; x < _strlen(str); x++)
	{
		array[x] = str[x] - '0';
	}
}

/**
 * multi - multiplie two nums
 *
 * @num_1: num_1
 * @num_2: num_2
 * @len_1: num_1 lenght
 * @len_2: num_2 lenght
 * Return: num_1 * num_2
 */
int *multi(int *num_1, int *num_2, int len_1, int len_2)
{
	int *res = NULL, res_len = len_1 + len_2, x, y, z, tmp;

	res = _malloc(res, res_len);
	for (x = 0; x < len_1; x++)
	{
		for (y = 0; y < len_2; y++)
		{
			res[x + y] += num_1[x] * num_2[y];
		}
	}
	for (z = 0; z < res_len; z++)
	{
		tmp = res[z] / 10;
		res[z] = res[z] % 10;
		res[z + 1] = res[z + 1] + tmp;
	}
	return (res);
}

/**
 * only_degit - checks if an str contains only digits
 *
 * @str: str
 */
void only_degit(char *str)
{
	int x;

	for (x = 0; x < _strlen(str); x++)
	{
		if (str[x] > '9' || str[x] < '0')
		{
			error();
			exit(98);
		}
	}
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int *num_1 = NULL, *num_2 = NULL, *result = NULL, i;
	char *x, *y;
	int len_1 = _strlen(argv[1]), len_2 = _strlen(argv[2]);
	int result_len = len_1 + len_2;

	if (argc != 3)
	{
		error();
		exit(98);
	}

	num_1 = _malloc(num_1, len_1);
	num_2 = _malloc(num_2, len_2);
	result = _malloc(result, result_len);
	x = _strrev(argv[1]);
	y = _strrev(argv[2]);
	to_array(num_1, x);
	to_array(num_2, y);
	result = multi(num_1, num_2, len_1, len_2);
	for (i = result_len; i >= 0; i--)
	{
		if (result[i] > 0)
			break;
	}
	for (; i >= 0; i--)
	{
		_putchar(result[i] + '0');
	}
	_putchar('\n');
	free(num_1);
	free(num_2);
	free(result);
	return (0);
}

/**
 * _strrev - reverse a string
 *
 * @str: str
 * Return: str
 */
char *_strrev(char *str)
{
char tmp;
int x;

for (x = 0; x < _strlen(str) / 2; x++)
{
	tmp = str[x];
	str[x] = str[_strlen(str) - 1 - x];
	str[_strlen(str) - 1 - x] = tmp;
}
return (str);
}

/**
 * _strlen - count the lenght of a string
 *
 * @str: str
 * Return: len
 */
int _strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

/**
 * error - error
 */
void error(void)
{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
}
