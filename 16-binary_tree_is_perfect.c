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

/**
 * binary_tree_power - Computes the power of a number.
 * @base: The base
 * @ex: The exponent
 *
 * Return: the power of exponent
 */
size_t binary_tree_power(size_t base, size_t ex)
{
	if (ex == 0)
		return (1);
	return (base * binary_tree_power(base, ex - 1));
}

/**
 * binary_tree_is_perfect - a function that checks if a binary
 * tree is perfect
 * @tree:  a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect , 0 otherwise
 * if tree is NULL it returns 0
 */


int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size, perfect_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	perfect_nodes = binary_tree_power(2, height + 1) - 1;
	return (size == perfect_nodes);
}
