#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 *
 * @tree: Pointer to the root node of the tree to be deleted.
 *
 * Description:
 * This function recursively deletes the entire binary tree rooted at the given
 * node. It follows a post-order traversal, deleting the left subtree, the
 * right subtree, and then the current node. Memory allocated for each node is
 * freed using the free() function.
 *
 * Note:
 * If the tree pointer is NULL, the function does nothing.
 *
 * Return: void.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
