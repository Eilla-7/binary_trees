#include "binary_trees.h"


/**
 * binary_tree_height - Computes the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Description:
 * This function calculates the height of the binary tree rooted at the given
 * node. The height of the tree is defined as the length of the longest path
 * from the root to a leaf node. The height of an empty tree is considered 0.
 *
 * Return:
 * Returns the height of the binary tree. If the tree is NULL, the height is 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree != NULL)
	{
		left_height = tree->left ? binary_tree_height(tree->left) + 1 : 1;
		right_height = tree->right ? binary_tree_height(tree->right) + 1 : 1;

		return (max(left_height, right_height));
	}
	return (0);
}

/**
 * max - Computes the maximum of two integers.
 *
 * @a: First integer.
 * @b: Second integer.
 *
 * Return:
 * Returns the maximum of the two integers.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}


/**
 * avl_binary_tree - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the binary tree.
 * @min: The minimum value allowed for a node in the tree.
 * @max: The maximum value allowed for a node in the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */


int avl_binary_tree(const binary_tree_t *tree, int min, int max)
{
	size_t left_h, right_h, height;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);

		left_h = binary_tree_height(tree->left);
		right_h = binary_tree_height(tree->right);
		height = left_h > right_h ? left_h - right_h : right_h - left_h;


		if (height > 1)
			return (0);

		return (avl_binary_tree(tree->left, min, tree->n - 1) &&
				avl_binary_tree(tree->right, tree->n + 1, max));
	}

	return (1);
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */


int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (avl_binary_tree(tree, INT_MIN, INT_MAX));
}
