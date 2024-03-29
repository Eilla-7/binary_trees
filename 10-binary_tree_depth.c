#include "binary_trees.h"

/**
 * binary_tree_depth - a function to masure the depth of the tree
 * @tree: a pointer to the node to masure the depth
 *
 * Return: 0 if the tree is NUUL , otherwise returns the depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

