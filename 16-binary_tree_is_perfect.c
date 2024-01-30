#include "binary_trees.h"

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
