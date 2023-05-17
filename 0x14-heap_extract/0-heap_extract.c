#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
*swap - swap 2 nodes values
*@node_1: node_1
*@node_2: node_2
**/
void swap(heap_t *node_1, heap_t *node_2)
{
	int temp = node_2->n;

	node_2->n = node_1->n;
	node_1->n = temp;
}

/**
*heapify - creating a heap data structure from a binary tree
*@root: root node
**/
void heapify(heap_t *root)
{
	heap_t *tmp = root;

	if (!tmp)
		return;
	if (tmp->right && (tmp->n < tmp->right->n))
	{
	swap(tmp, tmp->right);
	heapify(tmp->right);
	}
	else if (tmp->left && (tmp->n < tmp->left->n))
	{
	swap(tmp, tmp->left);
	heapify(tmp->left);
	}
}

/**
* minHeap - get the min node of the heap
* @root: root node
* Return: min node
**/
heap_t *minHeap(heap_t *root)
{
	heap_t *tmp = root;
	heap_t *min_node;

	if (!tmp)
		return (0);
	if (!tmp->left && !tmp->right)
		return (tmp);
	if (tmp->left && (!tmp->right || tmp->left->n >= tmp->right->n))
		min_node = tmp->left;
	else
		min_node = tmp->right;
	swap(tmp, min_node);
	return (minHeap(min_node));
}

/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: root
* Return: the value stored in the root node
**/
int heap_extract(heap_t **root)
{
	heap_t *tmp = *root;
	heap_t *min_node = minHeap(tmp);
	int value = min_node->n;

	if (tmp == NULL || tmp == NULL)
		return (0);
	if (min_node->parent->left == min_node)
		min_node->parent->left = NULL;
	else
		min_node->parent->right = NULL;
	free(min_node);
	heapify(tmp);
	return (value);
}
