#include "binary_trees.h"

/**
 * avl_remove - Removes a node with a specific value from an AVL tree.
 *
 * @root: Pointer to the root of the AVL tree.
 * @value: Value to be removed from the AVL tree.
 *
 * Description: This function removes a node with a specific value
 * from an AVL tree. It first uses the BST removal function and
 * then balances the AVL tree to ensure that it maintains its AVL property.
 *
 * Return: Pointer to the root of the AVL tree after the removal and balancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = bst_remove_avl(root, value);

	if (new_root == NULL)
		return (NULL);

	balance_recursive(&new_root);

	return (new_root);
}

/**
 * balance_recursive - Balances an AVL tree recursively after
 * a removal operation.
 *
 * @tree: Pointer to a pointer to the root of the AVL tree.
 *
 * Description: This function recursively balances an AVL tree by checking
 * the balance factor of each node and performing rotations if necessary.
 * It is called after a removal operation to maintain the AVL property
 * of the tree.
 *
 * Return: Pointer to the root of the AVL tree after balancing.
 */
avl_t *balance_recursive(avl_t **tree)
{
	int balance;

	if (tree == NULL || *tree == NULL)
		return (NULL);

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return (NULL);

	balance_recursive(&(*tree)->left);
	balance_recursive(&(*tree)->right);

	balance = binary_tree_balance(*tree);

	if (balance > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);

	return (*tree);
}

/**
 * bst_remove_avl - Removes a node with a specific value from
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
bst_t *bst_remove_avl(bst_t *root, int value)
{
	bst_t *node;

	if (root == NULL)
		return (NULL);

	node = bst_search_avl(root, value);

	return (bst_recursive_remove_avl(root, node));
}

/**
 * bst_recursive_remove_avl - Recursively removes a node from
 * a Binary Search Tree (BST).
 *
 * @root: Pointer to the root of the BST.
 * @node: Pointer to the node to be removed.
 *
 * Description: This function is called by bst_remove_avl to handle
 * the removal of a node with a specific value from a Binary Search Tree (BST).
 * It considers different cases based on the number of children the node has
 * and maintains the BST properties.
 *
 * Return: A pointer to the root of the BST after the removal.
 */
bst_t *bst_recursive_remove_avl(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor, *right_tree;

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

	right_tree = node->right;
	while (right_tree->left != NULL)
		right_tree = right_tree->left;
	successor = right_tree;
	node->n = successor->n;
	return (bst_recursive_remove_avl(root, successor));
}

/**
 * bst_search_avl - Searches for a value in a Binary Search Tree (BST).
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
bst_t *bst_search_avl(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search_avl(tree->left, value));
	if (value > tree->n)
		return (bst_search_avl(tree->right, value));

	return (NULL);
}
