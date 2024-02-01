#include "binary_trees.h"

/**
 * enqueue - Enqueues a binary tree node into the queue
 * @head: Pointer to the head of the queue
 * @node: Pointer to the binary tree node to be enqueued
 *
 * Description:
 * This function enqueues a binary tree node into the queue represented by
 * the provided head. It returns a pointer to the head of the modified queue.
 *
 * Return: Pointer to the head of the modified queue
 */
complete_queue_t *enqueue(complete_queue_t **head, binary_tree_t *node)
{
	complete_queue_t *new = malloc(sizeof(complete_queue_t));
	complete_queue_t *curr = NULL;

	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		curr = *head;
		while (curr->next)
			curr = curr->next;

		curr->next = new;
	}

	return (*head);
}

/**
 * dequeue - Dequeues a binary tree node from the queue
 * @head: Pointer to the head of the queue
 *
 * Description:
 * This function dequeues a binary tree node from the queue represented by
 * the provided head. It returns a pointer to the dequeued binary tree node.
 *
 * Return: Pointer to the dequeued binary tree node
 */
binary_tree_t *dequeue(complete_queue_t **head)
{
	complete_queue_t *temp;
	binary_tree_t *node;

	if (head == NULL || *head == NULL)
		return (NULL);

	temp = *head;
	*head = temp->next;
	node = temp->node;

	free(temp);
	temp = NULL;

	return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root of the binary tree
 *
 * Description:
 * This function checks if the given binary tree is complete. A complete
 * binary tree is a binary tree in which every level, except possibly the
 * last, is completely filled, and all nodes are as left as possible.
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *tmp;
	complete_queue_t *head = NULL;
	int is_nonfull = 0;

	if (tree == NULL)
		return (0);

	enqueue(&head, (binary_tree_t *)tree);
	while (head)
	{
		tmp = dequeue(&head);

		if (tmp->left)
		{
			if (is_nonfull)
				return (0);
			enqueue(&head, tmp->left);
		}
		else
			is_nonfull = 1;

		if (tmp->right)
		{
			if (is_nonfull)
				return (0);
			enqueue(&head, tmp->right);
		}
		else
			is_nonfull = 1;
	}

	return (1);
}
