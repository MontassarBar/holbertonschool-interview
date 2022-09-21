#include <stdio.h>
#include "lists.h"
/**
* check_cycle - hecks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
**/
int check_cycle(listint_t *list)
{
listint_t *ptr = list;
listint_t *ptr2 = list;
while (ptr && ptr2 && ptr2->next)
{
	if (ptr->next == ptr2->next->next)
		return (1);
	ptr = ptr->next;
	ptr2 = ptr2->next->next;
}
return (0);
}
