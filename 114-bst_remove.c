#include "binary_trees.h"

/**
 * bst_remove - Removes a node with a specific value from
 * a Binary Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 * @value: Value to be removed from the BST.
 *
 * Description: This function searches for a node with a specific
 * value in a BST and removes it while maintaining the BST properties.
 * If the value is not found or if the BST is empty, the function returns NULL.
 *
 * Return: A pointer to the root of the BST after the removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (root == NULL)
		return (NULL);

	node = bst_search(root, value);

	return (bst_recursive_remove(root, node));
}

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

/**
 * bst_recursive_remove - Recursively removes a node from
 * a Binary Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 * @node: Pointer to the node to be removed.
 *
 * Description: This function is called by bst_remove to handle
 * the removal of a node with a specific value from a Binary Search Tree (BST).
 * It considers different cases based on the number of children the node has
 * and maintains the BST properties.
 *
 * Return: A pointer to the root of the BST after the removal.
 */
bst_t *bst_recursive_remove(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor;

	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;

		free(node);
		return (!parent ? node->right : root);
	}

	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;

		if (node->left)
			node->left->parent = parent;

		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_recursive_remove(root, successor));
}

/**
 * inorder_successor - Finds the inorder successor of
 * a node in a Binary Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 *
 * Description: This function finds and returns the inorder successor
 * (the smallest node in the right subtree) of a given node in
 * a Binary Search Tree (BST).
 *
 * Return: A pointer to the inorder successor node.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
