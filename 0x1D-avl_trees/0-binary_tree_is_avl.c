#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *binary_tree_is_avl-function that checks if a binary tree is a valid AVL Tree
 *
 *@tree: a pointer to the root node of the tree to check
 *Return:  return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int x;
	int y;

	if (tree == NULL)
		return (0);
	x = tree->left ? 1 + binary_tree_is_avl(tree->left) : 0;
	y = tree->right ? 1 + binary_tree_is_avl(tree->right) : 0;
	if (x - y <= 1)
		return (1);
	return (0);
}
