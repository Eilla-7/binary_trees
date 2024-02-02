#include "binary_trees.h"

/**
 * complete_enqueue - Enqueues a binary tree node into the queue
 * @head: Pointer to the head of the queue
 * @node: Pointer to the binary tree node to be enqueued
 *
 * Description:
 * This function enqueues a binary tree node into the queue represented by
 * the provided head. It returns a pointer to the head of the modified queue.
 *
 * Return: Pointer to the head of the modified queue
 */
complete_queue_t *complete_enqueue(complete_queue_t **head,
		binary_tree_t *node)
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
 * complete_dequeue - Dequeues a binary tree node from the queue
 * @head: Pointer to the head of the queue
 *
 * Description:
 * This function dequeues a binary tree node from the queue represented by
 * the provided head. It returns a pointer to the dequeued binary tree node.
 *
 * Return: Pointer to the dequeued binary tree node
 */
binary_tree_t *complete_dequeue(complete_queue_t **head)
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
 * free_queue - Frees the memory allocated for a queue
 * @head: Pointer to the head of the queue
 *
 * Description:
 * This function traverses the given queue and frees the memory associated
 * with each node in the queue. It starts from the head of the queue and
 * iteratively frees each node until the end of the queue is reached.
 *
 * @head: Pointer to the head of the queue to be freed
 */
void free_queue(complete_queue_t *head)
{
	complete_queue_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * is_heap - Checks if a binary tree is a valid binary heap.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid binary heap, 0 otherwise.
 */

int is_heap(const binary_tree_t *tree)
{
	binary_tree_t *new;
	complete_queue_t *head = NULL;
	int is_nonfull = 0;

	if (tree == NULL)
		return (1);

	complete_enqueue(&head, (binary_tree_t *)tree);

	while (head)
	{
		new = complete_dequeue(&head);

		if (new->left)
		{
			if (is_nonfull || new->left->n > new->n)
			{
				free_queue(head);
				return (0);
			}
			complete_enqueue(&head, new->left);
		}
		else
			is_nonfull = 1;

		if (new->right)
		{
			if (is_nonfull || new->right->n > new->n)
			{
				free_queue(head);
				return (0);
			}
			complete_enqueue(&head, new->right);
		}
		else
			is_nonfull = 1;
	}

	return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_heap(tree))
		return (0);

	return (1);
}
