#include "binary_trees.h"

/**
 * enqueue - a function to ensert a node to the queue
 * @q: pointer to the queue
 * @node: node of the binary tree to be enserted
 *
 */

void enqueue(queue_t *q, const binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	new_node->node = node;
	new_node->next = NULL;

	if (q->end == NULL)
		q->start = q->end = new_node;
	else
	{
		q->end->next = new_node;
		q->end = new_node;
	}
}

/**
 * dequeue - a function to delete from the queue
 * @q: pointer to the queue
 *
 * Return: pointer to the deleted node
 */

const binary_tree_t *dequeue(queue_t *q)
{
	queue_node_t *satrt_node;
	const binary_tree_t *node;

	/*check if the Queue is empty*/
	if (q->start == NULL)
		return (NULL);

	satrt_node = q->start;
	node = satrt_node->node;

	q->start = satrt_node->next;

	if (q->start == NULL)
		q->end = NULL;

	free(satrt_node);
	return (node);
}


/**
 * binary_tree_levelorder - a function to visit the binary tree
 * in level order traversal
 *
 * @tree: pointer to the tree
 * @func: pointer to the function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *q;
	const binary_tree_t *current;

	if (tree != NULL && func != NULL)
	{
		q = malloc(sizeof(queue_t));
		q->start = q->end = NULL;

		enqueue(q, tree);

		/*while queue is not empty*/
		while (q->start != NULL)
		{
			current = dequeue(q);

			/*visit that node*/
			func(current->n);

			if (current->left != NULL)
				enqueue(q, current->left);


			if (current->right != NULL)
				enqueue(q, current->right);
		}
		free(q);
	}

}
