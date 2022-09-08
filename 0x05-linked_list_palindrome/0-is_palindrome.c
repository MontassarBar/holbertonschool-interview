#include "lists.h"
#include <stdio.h>

/**
 * reverse - reverse a singly linked list
 * @head: the head of the singly linked list
 * Return: a pointer to the reversed list
 */
listint_t *reverse(listint_t **head)
{
listint_t *node = *head;
listint_t *prev = NULL;
listint_t *next = NULL;
while (node != NULL)
	{
	next = node->next;
	node->next = prev;
	prev = node;
	node = next;
	}
return (prev);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: the head of the singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
int x = 0;
int m = 0;
int y = 0;
listint_t *size = *head;
listint_t *node = *head;
listint_t *node2 = *head;
listint_t *rev = NULL;
if ((*head) == NULL)
	return (1);
while (size != NULL)
	{
	x++;
	size = size->next;
	}
if (x % 2 == 0)
	{
	m = x / 2;
	}
else
	{
	m = (x + 1) / 2;
	}
while (y < m)
{
node2 = node2->next;
y++;
}
rev = reverse(&node2);
while (node != NULL && rev != NULL)
{
if (node->n != rev->n)
	return (0);
node = node->next;
rev = rev->next;
}
return (1);
}
