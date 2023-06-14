#include "lists.h"
#include<stdio.h>

/**
 *find_listint_loop - function that finds the loop in a linked list
 *@head: the head of the linked list to checked
 *Return: The address of the node where the loop starts, or NULL
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr1;
	listint_t *ptr2;

	if (!head)
		return (NULL);
	ptr1 = head;
	ptr2 = head;
	while (ptr1 && ptr2 && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr1 == ptr2)
		{
			break;
		}
	}
	if (!ptr2 || !ptr2->next)
	{
		return (NULL);
	}
	ptr1 = head;
	while (ptr1->next && ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (ptr1 == ptr2)
			break;
	}
	return (ptr1);
}
