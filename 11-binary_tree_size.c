#include "binary_trees.h"

/**
 * binary_tree_size - Computes the size (number of nodes) of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Description:
 * This function calculates the size of the binary tree rooted at the given
 * node. The size of a tree is defined as the total number of nodes, including
 * the root. The size of an empty tree is considered 0.
 *
 * Return:
 * Returns the size (number of nodes) of the binary tree. If the tree is NULL,
 * the size is 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		size += 1; /* Increment size for the current node */
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}

	return (size);
}
