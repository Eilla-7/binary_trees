#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to be traversed.
 * @func: Pointer to a function to be called on each node's value.
 *
 * Description:
 * This function performs an in-order traversal on the binary tree rooted at
 * the given node. It applies the specified function to each node's value.
 * In-order traversal visits the left subtree, then the current node,
 * and finally the right subtree.
 *
 * Return: Nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);

		/* Call the specified function on the current node's value */
		func(tree->n);

		binary_tree_inorder(tree->right, func);
	}
}
