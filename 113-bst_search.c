#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 *
 * @tree: Pointer to the root of the BST.
 * @value: Value to search for in the BST.
 *
 * Description: This function performs a search for a specific value within
 * a Binary Search Tree (BST). It traverses the tree recursively based on the
 * comparison of the target value with the values stored in each node.
 *
 * Return: If the value is found, a pointer to the node containing the value
 * is returned. If the value is not present in the BST or if the BST is empty
 * (NULL), the function returns NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));

	return (NULL);
}
