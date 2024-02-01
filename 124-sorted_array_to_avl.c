#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}

/**
 * build_avl_tree - Recursive function to build an AVL tree
 * from a sorted array.
 *
 * @array: A pointer to the first element of the array.
 * @start: The starting index of the current subtree.
 * @end: The ending index of the current subtree.
 * @parent: A pointer to the parent node of the current subtree
 *
 * Return: A pointer to the root node of the created AVL tree
 * or NULL on failure.
 */

avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	root = calloc(1, sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	root->n = array[mid];
	root->parent = parent;
	root->left = build_avl_tree(array, start, mid - 1, root);
	root->right = build_avl_tree(array, mid + 1, end, root);

	return (root);
}





