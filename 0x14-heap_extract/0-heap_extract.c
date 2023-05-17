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
heap_t *lchild = root->left, *rchild = root->right;

	if (rchild == NULL)
		return;

	if (lchild->left == NULL && rchild->left != NULL)
	{
		lchild->left = rchild->left;
		rchild->left->parent = lchild;
		rchild->left = NULL;
	}
	if (lchild->right == NULL && rchild->right != NULL)
	{
		lchild->right = rchild->right;
		rchild->right->parent = lchild;
		rchild->right = NULL;
	}
	heapify(root->left);
	heapify(root->right);
}

/**
* minHeap - get the min node of the heap
* @root: root node
* Return: min node
**/
heap_t *minHeap(heap_t *root)
{
	heap_t *min_node;

	if (!root)
		return (0);
	if (!root->left && !root->right)
		return (root);
	if (root->left && (!root->right || root->left->n >= root->right->n))
		min_node = root->left;
	else
		min_node = root->right;
	swap(root, min_node);
	return (minHeap(min_node));
}

/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: root
* Return: the value stored in the root node
**/
int heap_extract(heap_t **root)
{
	heap_t *min_node;
	int value;

	if (*root == NULL || root == NULL)
		return (0);
	min_node = minHeap(*root);
	value = min_node->n;
	if (min_node->parent->left == min_node)
		min_node->parent->left = NULL;
	else
		min_node->parent->right = NULL;
	free(min_node);
	heapify(*root);
	return (value);
}
