#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Description:
 * This function checks if a binary tree is full, meaning each
 * node in the tree has either 0 or 2 children. If the tree is NULL,
 * the function returns 0.
 *
 * Return: Returns 1 if the binary tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recursive_helper(tree));
}

/**
 * recursive_helper - Recursive helper function to check
 * if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Description:
 * This function recursively checks if a binary tree is full. A binary tree
 * is considered full if each node in the tree has either 0 or 2 children.
 * The function returns 1 if the tree is full, and 0 otherwise.
 *
 * Return: Returns 1 if the binary tree is full, 0 otherwise.
 */
int recursive_helper(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
				recursive_helper(tree->left) == 0 ||
				recursive_helper(tree->right) == 0)
			return (0);
	}

	return (1);
}
