#include "holberton.h"
#include <stdlib.h>

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
