#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *insert_node -  inserts a number into a sorted singly linked list.
 *@head: the head of the linked list.
 *@number: the number to be insorted .
 *Return: the new node or NULL.
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *temp;
listint_t *node;
if (head == NULL)
	return (NULL);
node = malloc(sizeof(listint_t));
if (node == NULL)
	return (NULL);
node->n = number;
node->next = NULL;
if ((*head) == NULL || (*head)->n > node->n)
	{
	node->next = (*head);
	(*head) = node;
	}
else
{
temp = *head;
while (temp != NULL && temp->next->n < node->n)
	temp = temp->next;
node->next = temp->next;
temp->next = node;
}
return (node);
}
