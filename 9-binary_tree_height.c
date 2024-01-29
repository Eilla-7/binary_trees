#include "binary_trees.h"

/**
 * binary_tree_height - Computes the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Description:
 * This function calculates the height of the binary tree rooted at the given
 * node. The height of the tree is defined as the length of the longest path
 * from the root to a leaf node. The height of an empty tree is considered 0.
 *
 * Return:
 * Returns the height of the binary tree. If the tree is NULL, the height is 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree != NULL)
	{
		left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
		right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

		return (max(left_height, right_height));
	}
	return (0);
}

/**
 * max - Computes the maximum of two integers.
 *
 * @a: First integer.
 * @b: Second integer.
 *
 * Return:
 * Returns the maximum of the two integers.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}
