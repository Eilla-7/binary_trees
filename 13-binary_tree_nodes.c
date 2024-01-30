#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child
 *                     in a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Description:
 * This function calculates the number of nodes in the binary tree rooted at
 * the given node that have at least one child. A node with at least one child
 * is considered a "non-leaf" or "internal" node. The function returns 0 for an
 * empty tree or a leaf node.
 *
 * Return: Returns the number of nodes with at least one child
 * in the binary tree. If the tree is NULL or empty, the count is 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree != NULL && (tree->left || tree->right))
	{
		tree->left ? ++nodes : nodes;
		tree->right ? ++nodes : nodes;
		tree->left && tree->right ? ++nodes : nodes;
	}

	return (nodes);
}
