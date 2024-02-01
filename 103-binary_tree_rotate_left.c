#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Description:
 * This function performs a left rotation on the binary tree rooted at the
 * given node. It reorganizes the structure of the tree, making the right
 * child of the node its new parent. The original parent becomes the left
 * child of the right child. The rotation helps maintain the binary search
 * property and can be used in self-balancing binary search trees.
 *
 * Return: A pointer to the new root after the left rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		/* No rotation needed if the tree is NULL or has no right child */
		return (tree);


	new_root = tree->right;
	tree->right = new_root->left;
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}
