#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * is_palindrome - checks whether or not a given unsigned integer is a
 * palindrome
 *
 * @n:the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
unsigned long int x = 0;
unsigned long int y = n;
while (y != 0)
	{
	x += y % 10;
	y /= 10;
	x *= 10;
	}
if (x / 10 != n)
	return (0);
return (1);
}
