#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree.
 *
 * @tree: Pointer to the root of the AVL tree.
 * @value: Value to be inserted into the AVL tree.
 *
 * Description: This function inserts a value into an AVL tree and initializes
 * the new_node pointer to the newly inserted node.
 *
 * Return: Pointer to the newly inserted node in the AVL tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_insert_recursive(tree, *tree, &new_node, value);

	return (new_node);

}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 *
 * @tree: Pointer to the root of the AVL tree.
 * @parent: Pointer to the parent node.
 * @new_node: Pointer to store the newly inserted node.
 * @value: Value to be inserted into the AVL tree.
 *
 * Description: This function recursively inserts a value into an AVL tree,
 * maintaining the AVL balance property. It performs rotations if necessary
 * to ensure the balance factor of each node is within the acceptable range.
 *
 * Return: Pointer to the root of the AVL tree after the insertion.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
				*tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = binary_tree_balance(*tree);
	if (balance_factor > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
