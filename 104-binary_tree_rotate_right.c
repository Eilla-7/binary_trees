#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Description:
 * This function performs a right rotation on the binary tree rooted at the
 * given node. It reorganizes the structure of the tree, making the left
 * child of the node its new parent. The original parent becomes the right
 * child of the left child. The rotation helps maintain the binary search
 * property and can be used in self-balancing binary search trees.
 *
 * Return: A pointer to the new root after the right rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	tree->left = new_root->right;
	new_root->right = tree;
	tree->parent = new_root;

	return (new_root);
}
