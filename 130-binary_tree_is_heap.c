#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_complete(tree) || !is_max_heap(tree))
		return (0);

	return (1);
}


/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */

int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
