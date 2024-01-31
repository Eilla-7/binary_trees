#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of
 * two nodes in a binary tree.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Description:
 * This function recursively finds and returns the lowest common ancestor
 * of two nodes in a binary tree. If either node is NULL, or if they are
 * the same node, the function returns NULL or a pointer to the shared node,
 * respectively.
 *
 * Return: Returns a pointer to the lowest common ancestor of the
 * two input nodes, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *f_parent, *s_parent;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f_parent = first->parent;
	s_parent = second->parent;

    /* check if `first` is above `second` in the tree */
	if (f_parent == NULL || first == s_parent || (!f_parent->parent && s_parent))
	{
		return (binary_trees_ancestor(first, s_parent));
	}
    /* check if `second` is above `first` in the tree */
	else if (s_parent == NULL || f_parent == second ||
			(!s_parent->parent && f_parent))
	{
		return (binary_trees_ancestor(f_parent, second));
	}

	return (binary_trees_ancestor(f_parent, s_parent));
}
