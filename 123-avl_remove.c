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
	avl_t *new_root = bst_remove(root, value);

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
