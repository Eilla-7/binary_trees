#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left child of a given node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to be assigned to the new node.
 *
 * Description:
 * This function inserts a new node with the specified value as the left child
 * of the given parent node. If the parent already has a left child, the new
 * node is inserted, and the existing left child becomes the left child of the
 * newly inserted node.
 *
 * Return:
 * Returns a pointer to the newly created left child node, or NULL if memory
 * allocation fails or if the parent node is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *old_left_node, *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		old_left_node = parent->left;
		new_node->left = old_left_node;
		old_left_node->parent = new_node;
	}

	parent->left = new_node;

	return (parent->left);
}
