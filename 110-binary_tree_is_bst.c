#include "binary_trees.h"

/**
 * is_binary_search_tree - Checks if a binary tree is
 * a valid Binary Search Tree (BST)
 *
 * @tree: Pointer to the root node of the binary tree
 * @min: Minimum allowed value for the current node
 * @max: Maximum allowed value for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int is_binary_search_tree(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n >= max || tree->n <= min)
			return (0);

		return (is_binary_search_tree(tree->left, min, tree->n) &&
				is_binary_search_tree(tree->right, tree->n, max));
	}
	return (1);


}


/**
 * binary_tree_is_bst - Checks if a binary tree is
 * a valid Binary Search Tree (BST)
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_binary_search_tree(tree, INT_MIN, INT_MAX));
}

