#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: Pointer to the node to find the sibling for.
 *
 * Description:
 * This function finds and returns the sibling of a given node in a binary
 * tree. The sibling of a node is another node that shares the same parent.
 * If the input node is NULL, or if it has no parent, or if it has no
 * sibling, the function returns NULL.
 *
 * Return: Returns a pointer to the sibling node,
 * or NULL if the sibling is not found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if ((node == node->parent->left) && node->parent->right)
		return (node->parent->right);

	if ((node == node->parent->right) && node->parent->left)
		return (node->parent->left);

	return (NULL);
}
